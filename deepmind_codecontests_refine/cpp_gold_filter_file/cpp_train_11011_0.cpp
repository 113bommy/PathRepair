#include <bits/stdc++.h>
using namespace std;
int a[200001],c[200002],n,k;
int main()
{
	cin>>n>>k;
	register int i,j,t,s,f;
	for (i=1;i<=n;++i) {
		cin>>a[i];
	}
	for (j=1;j<=k;++j) {
		memset(c,0,sizeof(c));
		for (i=1;i<=n;++i) {
			++c[max(1,i-a[i])];
			--c[min(n+1,i+a[i]+1)];
		}
		s=0,f=1;
		for (i=1;i<=n;++i) {
			a[i]=s+=c[i];
			if (a[i]<n) f=0;
		}
		if (f)break;
	}
	for(i=1;i<=n;++i) {
		cout<<a[i]<<" ";
	}
}