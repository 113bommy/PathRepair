#include<bits/stdc++.h>
using namespace std;
int n,d[55],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<n;i++)
	    for(int j=i+1;j<=n;j++)
	        ans+=d[i]*d[j];
	cout<<ans;
	return 0;
}