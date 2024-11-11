#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = int(A); I < int(B); ++I)
const ll INF=1e16+7;
int main(){
	ll N,A[3],ans=INF,K=1;
	cin >> N >> A[0] >> A[1] >> A[2];
	vector<ll> L(N);
	FOR(i,0,N)cin>>L[i];
	FOR(i,0,N)K*=4;
	FOR(t,0,K){
		vector<P> a={{0,0},{0,0},{0,0}};
		ll p = t;
		FOR(i,0,N){
			if(p%4!=3){
				a[p%4].first+=L[i];
				a[p%4].second++;
			}
			p /= 4;
		}
		FOR(i,0,3)p+=abs(a[i].first-A[i])
		FOR(i,0,3)p+=(a[i].second-1)*10;
		FOR(i,0,3)if(a[i].second==0)p=INF;
		ans = min(ans,p);
	}
	cout << ans << endl;
}