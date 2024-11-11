#include<bits/stdc++.h>
using namespace std;
int H,W,d[22][22],D,r,i,j,k,l,t[22][22];
char c;
void move(int i,int j,int n){
	if(t[i][j]&&(d[i][j]>n||d[i][j]==-1)){
		d[i][j]=n;
		move(i+1,j,n+1);
		move(i-1,j,n+1);
		move(i,j+1,n+1);
		move(i,j-1,n+1);
	}
}
int main(){
	cin>>H>>W;
	for(i=1;i<=H;i++)for(j=1;j<=W;j++){
		cin>>c;
		t[i][j]=(c=='.');
	}
	for(i=1;i<=H;i++)for(j=1;j<=W;j++){
		memset(d,-1,sizeof(d));
		move(i,j,0);
		D=0;
		for(k=1;k<=H;k++)for(l=1;l<=W;l++)D=max(D,d[k][l]);
		r=max(D,r);
	}
	cout<<r;
}