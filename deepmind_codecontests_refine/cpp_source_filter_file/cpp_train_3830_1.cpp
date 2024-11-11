
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll k,a[202020];
ll st=-2e18,en=2e18;

int main() {
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	while(st+1!=en) {
		ll mid=(st+en)/2,cnt=0;
		for(int i=0;i<n;i++) {
			int l=i,r=n;
			while(l+1!=r) {
				int m=(l+r)/2;
				if(a[i]*a[m]<=mid) 
					(a[i]<0)?r=m:l=m
				else (a[i]<0)?l=m:r=m
			}
			if(a[i]<0) cnt+=n-r;
			else cnt+=l-i;
		}
		if(cnt<k) st=mid;
		else en=mid;
	}
	cout<<en<<endl;
	return 0;
}
