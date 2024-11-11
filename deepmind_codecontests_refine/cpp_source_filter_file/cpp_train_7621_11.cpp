#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int inf = 1000 * 1000 * 1000;
const int mod = 998244353;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
int n;
int l[N], r[N];
vector<int> g;
int binpow(int a, int b) {
  if (b == 0) return 1;
  if (b % 2) return a * 1ll * binpow(a, b - 1) % mod;
  int t = binpow(a, b / 2);
  return t * 1ll * t % mod;
}
int dp[N][N];
int dd[N][N];
int need[N][N];
int rev[N];
int C(int n, int k) {
  if (n < k) return 0;
  int pat = 1;
  for (int i = 1; i <= k; i++) {
    pat = pat * 1ll * rev[i] % mod;
    pat = pat * 1ll * (n - i + 1) % mod;
  }
  return pat;
}
int main() {
  cin >> n;
  g.push_back(0);
  g.push_back(mod - 1);
  int Q = 1;
  for (int i = 1; i <= 200; i++) {
    rev[i] = binpow(i, mod - 2);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    l[i] = mod - 2 - l[i];
    r[i] = mod - 2 - r[i];
    swap(l[i], r[i]);
    Q = Q * 1ll * (r[i] - l[i] + 1) % mod;
    g.push_back(l[i]);
    g.push_back(r[i] + 1);
  }
  sort(g.begin(), g.end());
  g.resize(unique(g.begin(), g.end()) - g.begin());
  int seg = (int)g.size() - 1;
  for (int i = 1; i <= n; i++) {
    dd[i][1] = 1;
    for (int j = 2; j <= i; j++) {
      for (int h = j; h <= i; h++) {
        dd[i][j] += dd[h - 1][j - 1];
        dd[i][j] %= mod;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= seg; j++) {
      int len = g[j] - g[j - 1];
      for (int k = 1; k <= i; k++) {
        need[i][j] += dd[i][k] * 1ll * C(len, k) % mod;
        need[i][j] %= mod;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= seg; j++) {
      int rr = g[j] - 1, ll = g[j - 1];
      for (int h = i; h >= 1; h--) {
        if (ll >= l[h] && rr <= r[h]) {
          int val = need[i - h + 1][j];
          if (h == 1) {
            dp[i][j] += val;
            dp[i][j] %= mod;
          } else {
            for (int lst = 1; lst < j; lst++) {
              dp[i][j] += dp[i - 1][lst] * 1ll * val % mod;
              dp[i][j] %= mod;
            }
          }
        } else {
          break;
        }
      }
    }
  }
  int P = 0;
  for (int i = 1; i <= seg; i++) {
    P += dp[n][i];
    P %= mod;
  }
  Q = binpow(Q, mod - 2);
  cout << (P * 1ll * Q) % mod << endl;
  return 0;
}
