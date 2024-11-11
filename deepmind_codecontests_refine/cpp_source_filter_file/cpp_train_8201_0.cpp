#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005
#define MAX_RANK 60;

ll hakidashi(vector<ll> a){
    int n = a.size();
    ll rank = 0;
    int j = 0;
	for (int i = MAX_RANK - 1; i >= 0; i--) {
		for (j = rank; j < n; j++) {
			if (a[j] & (1LL << i)) break;
		}
		if (j == n) {
			continue;
		}

		if (j > rank) a[rank] ^= a[j];
		for (j = rank + 1; j < n; j++) {
			a[j] = min(a[j], a[j] ^ a[rank]);
		}

		rank++;
	}
	ll x = 0;
	for (int i = 0; i < n; i++) {
		x = max(x, x ^ a[i]);
	}

    return x;
}

int main(void){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];

	ll allxor = 0;
	rep(i,n) allxor ^= a[i];
	rep(i,n) a[i] &= ~allxor;

	ll ans = (hakidashi(a) * 2) + allxor;
    cout << ans << endl;
	return 0;
}
