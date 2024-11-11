#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m[4],p[4]={10,50,100,500},x[4],y[4],k,i=0,q,j;
	while(true){
		cin>>n;if(!n){break;}
		if(i){
			cout<<endl;
		}
		i++;
		k=0;
		cin>>m[0]>>m[1]>>m[2]>>m[3];
		for(j=3;j>=0;j--){
			k+=m[j]*p[j];
		}
		q=k-n;
		for(int j=3;j>=0;j--){
			x[j]=q/p[j];
			q-=x[j]*p[j];
			y[j]=max(0,m[j]-x[j]);
		}
		for(int j=0;j<4;j++){
			if(y[j]){printf("%d %d\n",p[j],y[j]);}
		}
	}
}