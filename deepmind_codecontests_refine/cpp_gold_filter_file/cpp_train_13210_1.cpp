#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef double db;

#define fr first
#define sc second
#define pb push_back
#define rep(i,x) for(ll i=0;i<x;i++)
#define rep1(i,x) for(ll i=1;i<=x;i++)
#define rrep(i,x) for(ll i=x-1;i>=0;i--)
#define rrep1(i,x) for(ll i=x;i>0;i--)

ll N,M;
ll a,b,x;
ll imos[5002][5002];

int main()
{
	scanf("%lld%lld",&N,&M);
	ll H=N;
	ll W=N;
	rep(i,M){
		scanf("%lld%lld%lld",&a,&b,&x);
		a--;
		--b;
		x++;
		imos[a][b]++;
		imos[a][b+1]--;
		imos[a+x][b]--;
		imos[a+x+1][b+1]++;
		imos[a+x][b+x+1]++;
		imos[a+x+1][b+x+1]--;
	}
	rep(i,H+2) rep(j,W+2){
		if(i>0&&j>0){
			imos[i][j]+=imos[i-1][j-1];
		}
	}
	rep(i,H+2) rep(j,W+2){
		if(i>0){
			imos[i][j]+=imos[i-1][j];
		}
	}
	rep(i,H+2) rep(j,W+2){
		if(j>0){
			imos[i][j]+=imos[i][j-1];
		}
	}
	ll ans=0;
	rep(i,H) rep(j,i+1) if(imos[i][j]>0) ans++;
	cout<<ans<<endl;
}