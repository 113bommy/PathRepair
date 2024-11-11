#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

signed main(){

	lli n,x;
	cin>>n>>x;

	lli a[n],c[n];

	lli ans=0;
	for(lli i=0;i<n;i++){
		cin>>a[i];
		c[i] = a[i];
		ans += a[i];
	}

	for(lli t=1;t<n;t++){
		lli cost = t*x;
		for(lli i=0;i<n;i++){
			c[i] = min(c[i],a[(i+n-t)%n]);
			cost += c[i];
		}
		ans = min(ans,cost);
	}
	cout<<ans<<endl;

	return 0;
}