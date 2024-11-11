#include<iostream>
using namespace std;
int dp[1401][1401]={},m,h,w,f,i,j;
int main(){
	cin>>h>>w;
	m=0;
	for(i=0;i<h;i++)for(j=0;j<w;j++){
		cin>>f;
		if(!f){
			dp[i+1][j+1]=min(dp[i][j],min(dp[i+1][j],dp[i][j+1]))+1;
			m=max(m,dp[i+1][j+1]);}
	}
	cout<<m*m<<endl;
}
