#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int kMaxN = 420;
int t, p;
int nops[kMaxN];
int bad[kMaxN];
int good[kMaxN];
int fact[kMaxN];
int dp_nops[kMaxN][kMaxN];
int dp_fact[kMaxN][kMaxN];
void Preproc() {
  fact[0] = 1;
  for (int i = 1; i < kMaxN; ++i) {
    fact[i] = (ll)fact[i - 1] * i % p;
  }
  for (int n = 1; n < kMaxN; ++n) {
    nops[n] = fact[n];
    for (int k = 1; k < n; ++k) {
      nops[n] = (nops[n] - (ll)nops[k] * fact[n - k]) % p;
      if (nops[n] < 0) {
        nops[n] += p;
      }
    }
  }
  dp_nops[0][0] = 1;
  for (int cnt = 1; cnt < kMaxN; ++cnt) {
    for (int n = cnt; n < kMaxN; ++n) {
      for (int i = 1; i <= n; ++i) {
        dp_nops[cnt][n] =
            (dp_nops[cnt][n] + (ll)dp_nops[cnt - 1][n - i] * nops[i]) % p;
      }
    }
  }
  dp_fact[0][0] = 1;
  for (int cnt = 1; cnt < kMaxN; ++cnt) {
    for (int n = cnt; n < kMaxN; ++n) {
      for (int i = 1; i <= n; ++i) {
        dp_fact[cnt][n] =
            (dp_fact[cnt][n] + (ll)dp_fact[cnt - 1][n - i] * fact[i]) % p;
      }
    }
  }
  good[1] = 1;
  bad[2] = 2;
  for (int n = 3; n < kMaxN; ++n) {
    int order_factor = 0;
    for (int cnt = 2; cnt <= n; ++cnt) {
      order_factor = (order_factor + dp_nops[cnt][n]) % p;
    }
    order_factor = (order_factor * 2) % p;
    int unorder_factor = 0;
    for (int k = 2; k < n; ++k) {
      unorder_factor = (unorder_factor + (ll)good[k] * dp_fact[k][n]) % p;
    }
    bad[n] = (order_factor + unorder_factor) % p;
    good[n] = (p + fact[n] - bad[n]) % p;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> t >> p;
  Preproc();
  while (t--) {
    int n;
    cin >> n;
    cout << good[n] << "\n";
  }
}
