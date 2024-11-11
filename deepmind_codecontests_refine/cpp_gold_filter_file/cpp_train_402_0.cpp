#include <iostream>
using namespace std;
int n,m,seiz[220][2],data[1100][2],x,y,cnt,k;
int main(){
	while(1){
	cin>>m;
	if(m==0){
		break;
	}
	for(int i=0;i<m;i++){
		cin>>seiz[i][0]>>seiz[i][1];
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i][0]>>data[i][1];
	}
	for(int i=0;i<n;i++){
		cnt=1;
		x=data[i][0]-seiz[0][0];
		y=data[i][1]-seiz[0][1];
		for(int j=1;j<m;j++){
			for(k=0;k<n;k++){
				if(k!=i && seiz[j][0]==(data[k][0]-x)){
					if(seiz[j][1]==(data[k][1]-y)){
						cnt++;
						break;
					}
				}
			}
					
		}
		if(cnt==m){
			break;
		}
	}
	cout<<x<<" "<<y<<endl;
	}
	return 0;
}