#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 1e5 + 5;
int cnt = 0, vis[maxn], prime[maxn], mu[maxn];
int f[55][maxn], l[55], r[55], l1[55], r1[55];
void init(int n) {
  vis[1] = mu[1] = 1;
  for (int i = (2); i <= (n); i++) {
    if (!vis[i]) prime[++cnt] = i, mu[i] = -1;
    for (int j = (1); j <= (cnt); j++) {
      if (i * prime[j] > n) break;
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      }
      mu[i * prime[j]] = -mu[i];
    }
  }
}
int n, m;
int calc(int x) {
  long long sum = 0;
  for (int i = (1); i <= (n); i++) {
    l[i] = (l1[i] - 1) / x + 1;
    r[i] = r1[i] / x;
    sum += l[i];
    if (i == 1)
      for (int j = (l[i]); j <= (r[i]); j++) f[1][j] = 1;
    else {
      for (int j = (sum); j <= (m / x); j++) {
        int L = max(1, j - r[i]), R = j - l[i];
        f[i][j] = ((f[i - 1][R] - f[i - 1][L - 1]) % mod + mod) % mod;
      }
    }
    for (int j = (1); j <= (m / x); j++) (f[i][j] += f[i][j - 1]) %= mod;
  }
  return f[n][m / x];
}
int main() {
  init(1e5);
  scanf("%d", &n);
  scanf("%d", &m);
  int mnr = 1e9;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &l1[i]), scanf("%d", &r1[i]);
    mnr = min(mnr, r1[i]);
  }
  long long ans = 0;
  for (int x = (1); x <= (mnr); x++) {
    ans = ((ans + calc(x) * mu[x]) % mod + mod) % mod;
  }
  cout << ans;
}
