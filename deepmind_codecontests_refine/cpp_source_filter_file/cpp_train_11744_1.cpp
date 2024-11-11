#ifndef UTIL_INCLUDED
#define UTIL_INCLUDED

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
#define DEBUGGING

template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
template <typename T, typename U> using P = pair<T, U>;
using ll = int64_t;
using PLL = P<ll, ll>;

template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename Head, typename... Tail> const Head& var_min(const Head &head, const Tail&... tail) { return min(head, var_min(tail...)); }
template <typename Head, typename... Tail> const Head& var_max(const Head &head, const Tail&... tail) { return max(head, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }

namespace __init {

struct InitIO {
    InitIO() {
        cin.tie(0);
        ios_base::sync_with_stdio(false);
        cout << fixed << setprecision(30);
    }
} init_io;

}

#ifndef DEBUG_FILE
#ifdef DEBUGGING
#include "../debug.cpp"
#else
#define DEBUG(...) 0
#endif
#endif

#endif

const ll MOD = 998244353;

class Combination {
private:
    template <typename T> using V = vector<ll>;
    ll N;
    ll MOD;
    V<ll> factv, rfactv;

public:
    /*
     * MOD must be a prime number.
     */
    Combination(ll N, ll MOD)
        : N(N), 
          MOD(MOD),
          factv(N + 1, 1),
          rfactv(N + 1)
    {
        for(ll i = 1; i <= N; i++) {
            factv[i] = factv[i - 1] * i % MOD;
        }
        for(ll i = 0; i <= N; i++) {
            rfactv[i] = pow(factv[i], MOD - 2);
        }
    }

    ll fact(ll n) {
        return factv[n];
    }

    ll rfact(ll n) {
        return rfactv[n];
    }

    ll pow(ll a, ll b) {
        return b ? (b & 1 ? a : 1) * pow(a * a % MOD, b / 2) % MOD : 1;
    }

    ll comb(ll n, ll k) {
        return factv[n] * rfactv[n - k] % MOD * rfactv[k] % MOD;
    }
};

int main() {
    ll N, X;
    cin >> N >> X;

    Combination comb(1e5, MOD);
    ll ans = 0;
    for(ll one = 0; one <= N; one++) {
        for(ll two = 0; one + two <= N; two++) {
            ll cells = one + two;
            ll sum = one + 2 * two;
            if(sum == X) continue;
            if(sum < X) {
                ll tmp = comb.comb(N, cells) * comb.comb(cells, two) % MOD;
                (ans += tmp) %= MOD;
            }
            if(sum > X) {
                ll rest = sum - X;
                if(rest % 2 == 0) continue;
                ll tmp;
                if(one == 0) {
                    tmp = comb.comb(N, cells) % MOD;
                } else { 
                    ll cnt = rest / 2 + 1;
                    if(cnt * 2 > two) continue;
                    tmp = comb.comb(N, cells) * comb.comb(cells - 2 * cnt, two - 2 * cnt) % MOD;
                }
                (ans += tmp) %= MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
