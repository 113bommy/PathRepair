#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) - 1;
const long long linf = (1ll << 62) - 1;
const int N = 2100;
const int M = 1e9 + 7;
int h, w, n;
int r[N], c[N];
long long dp[N];
long long fact[300500], ifact[300500];
long long cnk(int n, int k) {
  return (((1ll * fact[n] * ifact[k]) % M) * ifact[n - k]) % M;
}
long long power(long long a, int b) {
  if (b == 0) {
    return 1;
  }
  int res = power(a, b / 2);
  res = (1ll * res * res) % M;
  if (b & 1) {
    res = (1ll * res * a) % M;
  }
  return res;
}
long long inv(long long x) { return power(x, M - 2); }
int s[N];
int cmp(int a, int b) { return r[a] + c[a] < r[b] + c[b]; }
int main() {
  cin >> h >> w >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &r[i], &c[i]);
    r[i]--, c[i]--;
  }
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < 300500; i++) {
    fact[i] = (1ll * fact[i - 1] * i) % M;
    ifact[i] = inv(fact[i]);
  }
  for (int i = 0; i < n; i++) {
    s[i] = i;
  }
  sort(s, s + n, cmp);
  for (int t = 0; t < n; t++) {
    int i = s[t];
    dp[i] = cnk(r[i] + c[i], r[i]);
    for (int j = 0; j < n; j++) {
      if (j != i && r[i] >= r[j] && c[i] >= c[j]) {
        dp[i] = (dp[i] -
                 1ll * dp[j] * cnk(r[i] - r[j] + c[i] - c[j], r[i] - r[j])) %
                M;
        if (dp[i] < 0) {
          dp[i] += M;
        }
      }
    }
  }
  long long ans = cnk(h + w - 2, h - 1);
  for (int i = 0; i < n; i++) {
    ans = (ans - 1ll * dp[i] * cnk(h + w - r[i] - c[i] - 2, w - c[i] - 1)) % M;
    if (ans < 0) {
      ans += M;
    }
  }
  cout << ans << endl;
  return 0;
}
