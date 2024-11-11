#include <bits/stdc++.h>
//#include <math.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define BIT(x,n) bitset<n>(x)
#define PI 3.14159265358979323846

typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,P> PP;

//-----------------------------------------------------------------------------

int n,p;
vector<ll> v;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n>>p;
	ll sum=0;
	REP(i,n) {
		ll w,b;cin>>w>>b;
		sum+=(-p)*b;
		v.pb(w*(100-p)+p*b));
	}
	sort(ALL(v));reverse(ALL(v));
	REP(i,n) {
		sum+=v[i];
		if(sum>=0) {
			cout<<i+1<<endl;
			return 0;
		}
	}

	return 0;
}
