#include<bits/stdc++.h>
using namespace std;

int ans[10];
int n,m;
int main(){
	cin>>n>>m;	
	for(int i=1;i<=m;i++){
		int s,c;
		cin>>s>>c;
		if(s==1&&c==0&&n>1){ cout<<-1;return 0;}
		else if(ans[s-1]==0|| ans[s-1]==c) ans[s-1]=c;
		else { cout<<-1;return 0;}
	}
	if(n==1) cout<<ans[0];
	else 
	{
		if(ans[0])cout<<ans[0];
		else cout<<1;
		for(int i=1;i<n;i++) cout<<ans[i];
	}
}