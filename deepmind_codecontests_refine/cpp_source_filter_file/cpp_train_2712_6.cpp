#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

const int N = 125252;
const int B = 252;
const int C = (N+B-1)/B;
const ll INF = 1ll<<60;

ll a[N];
ll b[C];
void update(int i, ll v){
	a[i] = v;
	int id = i/B;
	b[id] = INF;
	REP(j,B){
		b[id] = min(b[id], a[id*B+j]);
	}
}
ll qmin(int l, int r){
	ll ret = INF;
	if(r-l<=B){
		REP(i,r-l)ret = min(ret,a[l+i]);
		return ret;
	}
	while(l%B>0)ret = min(ret, a[l++]);
	while(r-l>=B){
		ret = min(ret, b[l/B]);
		l += B;
	}
	while(l<r)ret = min(ret, a[l++]);
	return ret;
}

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	REP(i,n)a[i] = 2147483647ll;
	REP(i,C)b[i] = 2147483647ll;
	while(q--){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==0){
			update(x,y);
		}else{
			printf("%lld\n",qmin(l,r+1));
		}
	}
	return 0;
}
