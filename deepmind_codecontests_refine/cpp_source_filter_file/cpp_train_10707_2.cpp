#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int a[maxn],n,vis[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!vis[a[i]]) vis[a[i]]++,ans++;	
	}
	if(ans%2) cout<<ans;
	else cout<<ans-1;
	return 0;
}