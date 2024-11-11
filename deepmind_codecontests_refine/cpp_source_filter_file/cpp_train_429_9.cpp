#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const long long mod2 = mod * 1LL * mod;
const int N = 3005;
int n, c, a[N], dp[N][N], g[N][N], freq[N], mul[N], imul[N], pw[N], cnt[N];
int dp2[N][1 << 13];
int inverse(int n) {
  if (n == 1) return 1;
  return inverse(mod % n) * 1LL * (mod - mod / n) % mod;
}
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void solve1() {
  for (int i = 1; i <= n; i++) {
    a[i]--;
  }
  int m = n / c;
  memset(dp2, 0, sizeof(dp2));
  dp2[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int p = 0; p <= m; p++) {
      int tsum = 0;
      for (int mask = (1 << c) - 1; mask >= 0; mask--) {
        int nmask = mask | (1 << a[i]);
        if (nmask + 1 == (1 << c)) {
          add(tsum, dp2[p][mask]);
        } else {
          add(dp2[p][nmask], dp2[p][mask]);
        }
      }
      add(dp2[p][0], sum);
      sum = tsum;
    }
  }
  memset(cnt, 0, sizeof(cnt));
  for (int p = 0; p <= n; p++) {
    for (int mask = 0; mask + 1 < (1 << c); mask++) {
      add(cnt[p], dp2[p][mask]);
    }
  }
  add(cnt[0], mod - 1);
  for (int i = 0; i <= n; i++) {
    cout << cnt[i] << " ";
  }
  cout << '\n';
}
void solve2() {
  mul[0] = 0;
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    mul[i] = mul[i - 1] + mul[i - 1] + 1;
    if (mul[i] >= mod) mul[i] -= mod;
    imul[i] = inverse(mul[i]);
    pw[i] = mul[i] + 1;
  }
  int m = n / c;
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    long long prd = 0;
    memset(freq, 0, sizeof(freq));
    for (int j = i; j <= n; j++) {
      if (freq[a[j]] == 0) {
        cnt++;
        freq[a[j]]++;
        if (cnt == c) {
          prd = 1;
          for (int k = 1; k <= c; k++) {
            (prd *= mul[freq[k]]) %= mod;
          }
        }
      } else {
        if (prd) (prd *= imul[freq[a[j]]]) %= mod;
        freq[a[j]]++;
      }
      if (prd) (prd *= mul[freq[a[j]]]) %= mod;
      if (cnt == c) {
        g[i][j] = prd * imul[freq[a[j]]] % mod;
      }
    }
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int p = 1; p <= m; p++) {
    for (int i = p * c; i <= n; i++) {
      long long sum = 0;
      for (int j = (p - 1) * c; j + c <= i; j++) {
        sum += dp[p - 1][j] * 1LL * g[j + 1][i];
        if (sum >= mod2) sum -= mod2;
      }
      dp[p][i] = sum % mod;
    }
  }
  memset(cnt, 0, sizeof(cnt));
  for (int p = 1; p <= m; p++) {
    for (int i = 1; i <= n; i++) {
      cnt[p] += dp[p][i] * 1LL * pw[n - i] % mod;
      if (cnt[p] >= mod) cnt[p] -= mod;
    }
  }
  cnt[0] = mul[n] + mod - cnt[1];
  if (cnt[0] >= mod) cnt[0] -= mod;
  for (int p = 1; p <= n; p++) {
    cnt[p] += mod - cnt[p + 1];
    if (cnt[p] >= mod) cnt[p] -= mod;
  }
  for (int i = 0; i <= n; i++) {
    cout << cnt[i] << " ";
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (c > 14 || n <= (1 << c)) {
    solve1();
  } else {
    solve2();
  }
  return 0;
}
