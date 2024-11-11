#include<bits/stdc++.h>
using namespace std;
int main (){
	int x,j,ans,s=9999;
	cin>>x;
	if(x==1){cout<<x;return 0;}
	for(int i=2;i*i<=x;i++){
		for(j=i;j*i<=x;j=j*i){}
		if(x-j<s) s=x-j;
	}
	ans=x-s;
	cout<<ans;
	return 0;
}