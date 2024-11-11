#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define ALL(v) v.begin(), v.end()

vvi mult(vvi a, vvi b, ll MOD) {
    int l = a[0].size();
    int m = a.size(), n = b[0].size();
    vvi res(m, vi(n));
    REP (i, m) REP (j, n) REP (k, l) {
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] %= MOD;
    }
    return res;
}

vvi pow(vvi a, ll k, ll MOD) {
    int n = a.size();
    vvi res(n, vi(n));
    REP (i, n) res[i][i] = 1;r
    while(k) {
        if (k&1) res = mult(res,a,MOD);
        a = mult(a,a,MOD);
        k >>= 1;
    }
    return res;
}

ll L, A, B, MOD;
ll digit[19];

ll s(ll n) {
    return A + B * n;
}

int solve() {
    ll k = 1;
    REP (i, 18) {
        ll lo = -1, hi = L;
        while (hi - lo > 1ll) {
            ll mid = (hi+lo)/2;
            if (s(mid) >= k*10) hi = mid;
            else lo = mid;
        }
        digit[i] = hi;
        k *= 10;
    }
    digit[18] = L;
    FORR (i, 1, 19) digit[i] = digit[i] - digit[i-1];
    REP (i, 19) assert(digit[i] >= 0);

    vvi X(3, vi(1));
    X[0][0] = A % MOD;
    X[1][0] = A % MOD;
    X[2][0] = 1;
    k = 1;
    bool f = true;
    REP (i, 19) {
        k *= 10;
        k %= MOD;
        vvi C(3, vi(3));
        C[0][0] = k;
        C[0][1] = 1;
        C[0][2] = B % MOD;
        C[1][0] = 0;
        C[1][1] = 1;
        C[1][2] = B % MOD;
        C[2][0] = 0;
        C[2][1] = 0;
        C[2][2] = 1;
        ll n = digit[i];
        if (n == 0) continue;
        if (f) {
            C = pow(C, n-1, MOD);
        }
        else C = pow(C, n, MOD);
        f = false;
        X = mult(C, X, MOD);
    }
    return X[0][0] % MOD;
}

int main() {
    cin >> L >> A >> B >> MOD;
    cout << solve() << endl;
}