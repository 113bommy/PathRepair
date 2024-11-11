#include<bits/stdc++.h>
#define int long long
#define L 999999
using namespace std;
int n,k,a[L];
bool f(int x) {
	int ret=0;
	for(int i=1; i<=n; i++) {
		ret+=((a[i]/x)-1+(a[i]%x>0));
	}
	return ret<=k;
}
signed main() {
	cin>>n>>k;
	int l=1,r=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		r=max(r,a[i]);
	}
	r++;
	int mid;
	while(l+1<r) {
		mid=(l+r)/2;
		if(f(mid))r=mid;
		else l=mid;
	}
	if(check(l))cout<<l<<endl;else cout<<r<<endl;
	return 0;
}