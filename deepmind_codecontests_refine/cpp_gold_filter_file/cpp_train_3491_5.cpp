#include <bits/stdc++.h>
#pragma GCC target("sse4.2")
using namespace std;
bool home = 1;
signed realMain();
signed main() {
  home = 0;
  if (home) {
    freopen("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
  realMain();
}
const int M = (int)1e9 + 7;
int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}
int mul(int a, int b) { return a * (long long)b % M; }
int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}
int dv(int a, int b) { return mul(a, pw(b, M - 2)); }
const int N = (int)1e5 + 7;
const int K = 1;
int q, n, fact[N], ifact[N], memo[N][K], p25[N], p26[N], now[N];
string s;
int comb(int n, int k) { return mul(fact[n], mul(ifact[k], ifact[n - k])); }
signed realMain() {
  p25[0] = 1;
  p26[0] = 1;
  for (int i = 1; i < N; i++) p25[i] = mul(p25[i - 1], 25);
  for (int i = 1; i < N; i++) p26[i] = mul(p26[i - 1], 26);
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
  for (int len = 1; len < N; len++) {
    for (int n = 1; n < K; n++) {
      memo[len][n] = add(mul(26, memo[len - 1][n]),
                         mul(comb(len - 1, n - 1), p25[len - n]));
    }
  }
  cin >> q >> s;
  n = (int)s.size();
  if (n >= K) {
    for (int len = 1; len < N; len++) {
      now[len] =
          add(mul(26, now[len - 1]), mul(comb(len - 1, n - 1), p25[len - n]));
    }
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      cin >> s;
      n = (int)s.size();
      if (n >= K) {
        for (int len = 1; len < N; len++) {
          now[len] = add(mul(26, now[len - 1]),
                         mul(comb(len - 1, n - 1), p25[len - n]));
        }
      }
    } else {
      int len;
      cin >> len;
      cout << now[len] << "\n";
    }
  }
  return 0;
}
