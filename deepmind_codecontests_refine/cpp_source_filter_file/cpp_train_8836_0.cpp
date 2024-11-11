#include<cstdio>
#include<iostream>
#include<slgorithm>
using namespace std;
int main(void){
	int n,p[1000][3],flg[1000],i,j,k,f,temp,cnt;
	cin>>n;
	for(i=0;i<n;i++) flg[i]=0;
	for(i=0;i<n;i++){
		for(j=0;j<3;j++) cin>>p[i][j];
	}
	for(i=0;i<n;i++){
		sort(p[i],p[i]+3);
	}
	cnt=0;
	for(i=0;i<n-1;i++){
		if(flg[i]!=1){
			for(j=i+1;j<n;j++){
				f=1;
				for(k=0;k<3;k++){
					if(p[i][k]!=p[j][k]){
						f=0;
						break;
					}
				}
				if(f==1){
					cnt++;
					flg[j]=1;
				}
			}		
		}
	}
	cout<<cnt<<endl;
	return 0;
}