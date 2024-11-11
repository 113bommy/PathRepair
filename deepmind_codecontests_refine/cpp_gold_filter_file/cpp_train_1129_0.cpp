#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,a[100008],t,nxt,pos[100008];
char op[100008];
LL ans,tmp,suf[100008];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>t;
	for(int i=1;i<n;++i){
		cin>>op[i]>>a[i];
	}
	nxt=n;
	for(int i=n-1;i;--i){
		suf[i]=suf[i+1]+a[i];
		if(op[i]=='-'){
			pos[i]=nxt;
			nxt=i;
		}
	}
	for(int i=1;i<n;++i){
		if(op[i]=='-'){
			ans=max(ans,tmp-(suf[i]-suf[pos[i]])+suf[pos[i]]);
			tmp-=a[i];
		}
		else{
			tmp+=a[i];
			if(i==n-1)	ans=max(ans,tmp);
		}
	}
	cout<<ans+t;
	return 0;
}