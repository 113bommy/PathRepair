#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=360;
const ll mod=1e9+7;
ll n; ll K;
ll a[maxn];
struct node{ ll b,c; }b[maxn];

void chkmin(ll& x,ll y){ if(x>y) x=y; }
void chkmax(ll& x,ll y){ if(x<y) x=y; }

bool cmp1(node A,node B){ return A.c<B.c; }
bool cmp2(node A,node B){ return A.b<B.b || (A.b==B.b && A.c<B.c); }

map<vector<ll>, vector<node> > mp; typedef map<vector<ll>, vector<node> >::iterator it;

ll popmin(ll l,ll r){
	if(l>r) return maxn;
	ll ret=0;
	for(ll i=60;i>=0;i--){
		if((l & (1ll<<i)) ^ (r & (1ll<<i))){
			if(l & ((1ll<<i)-1)) ret++;
			break;
		}
		if(l & (1ll<<i)) ret++;
	}
	return ret;
}

void add(ll x,ll k){
	if(k<0) return;
	vector<ll> vec;
	vec.resize(n);
	ll Min=b[1].b-(1<=x);
	for(ll i=1;i<=n;i++){
		vec[i-1]=b[i].b-(i<=x);
		chkmin(Min, vec[i-1]);
	}
	if(Min<0) return;
	for(ll i=0;i<n;i++) vec[i]-=Min;
	sort(vec.begin(), vec.end());
	mp[vec].push_back( (node){max(Min-k,0ll), Min} );
	// for(int i=0;i<n;i++) printf("%d ", vec[i]); puts("");
	// printf("Min = %d Max = %d\n", max(Min-k, 0ll) ,Min);
}

int main(){

	T=1;
	while(T--){
		mp.clear();
		scanf("%d%lld", &n, &K);
		for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
		for(ll i=0;i<=60;i++){
			for(ll j=1;j<=n;j++){
				b[j].b=a[j]>>i;
				b[j].c=a[j] & ((1ll<<i)-1);
			}
			sort(b+1,b+1+n,cmp1);
			ll Next, l=0, r=0;
			for(ll j=1;j<=n;j=Next+1,l=r+1){
				Next=j;
				while(Next<n && b[Next+1].c==b[j].c) Next++;
				r=b[j].c;
				add(j-1,K-popmin(l,r)-i);
			}
		}

		ll ans=0;
		for(it it=mp.begin();it!=mp.end();it++){
			vector<node> vec=it->second;
			sort(vec.begin(), vec.end(), cmp2);
			ll l=0, r=-1;
			// puts("");
			for(ll i=0;i<vec.size();i++){
				// printf("l = %d r = %d\n", vec[i].b, vec[i].c);
				if(vec[i].b>r){
					l=vec[i].b; r=vec[i].c;
					ans=(ans+r-l+1)%mod;
				}else{
					ans=(ans+vec[i].c-r)%mod;
					r=vec[i].c;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}