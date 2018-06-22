#include<iostream>
using namespace std;

int main(){
	
	int p=5,r=3;
	
	int allot[5][3],max[5][3],avail[3],need[5][3];
	int i,j,k;
	
	cout<<"Allocation";
	
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			cin>>allot[i][j];
		}
	}
	
	cout<<"max";
	
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			cin>>max[i][j];
		}
	}
	
	cout<<"Available";
	
	for(i=0;i<r;i++){
		
			cin>>avail[i];
	}
	
	cout<<"need";
	
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			need[i][j] = max[i][j] - allot[i][j];
		}
	}
	
	
	for(i=0;i<p;i++){
		cout<<" \n"
		for(j=0;j<r;j++){
			cout<<"  "<<need[i][j];
		}
	}
	
	
	
	int safestate[p]={0};
	int finish[p]={0};
	int found=0;
	int count=0;
	
	while(count < p){
		
			found=0;
			
			for(i=0;i<p;i++){
				
					if(finish[i] == 0){
						
							for(j=0;j<r;j++){
							
								if( need[i][j] > avail[j] ){
									
									break;
								}
							}
						
						
							if(j == r){
								
								for(k=0;k<r;k++){
									
									avail[k] = avail[k] + allot[i][k];
								}
								
								finish[i]=1;
								found=1;
								safestate[count++]=i;
							}
					}
			}
		
		
		if(found == 0){
			cout<<"No safe sate";
		}
		
	}
	
	cout<<"safe State";
	
	for(i=0;i<p;i++){
		cout<<"  "<<safestate[i];
	}
	
	return 0;
}
