#include <bits/stdc++.h>
const int N = 500005;
using namespace std;
inline int Getint() {
  register int x = 0, f = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int prime[N], mu[N];
bool vis[N], chk[200005];
int a[200005], cnt[N];
int main() {
  mu[1] = 1;
  for (int i = 2; i <= 5e5; i++) {
    if (!vis[i]) prime[++prime[0]] = i, mu[i] = -1;
    for (int j = 1; j <= prime[0] && i * prime[j] <= 5e5; i++) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
      mu[i * prime[j]] = -mu[i];
    }
  }
  int n = Getint(), q = Getint();
  for (int i = 1; i <= n; i++) a[i] = Getint();
  long long ans = 0;
  for (int i = 1; i <= q; i++) {
    int x = Getint(), ret = 0;
    if (!chk[x]) {
      chk[x] = 1, x = a[x];
      for (int i = 1, lim = sqrt(x); i <= lim; i++) {
        if (x % i == 0) {
          ret += mu[i] * cnt[i], cnt[i]++;
          if (i * i != x) ret += mu[x / i] * cnt[x / i], cnt[x / i]++;
        }
      }
      ans += ret;
    } else {
      chk[x] = 0, x = a[x];
      for (int i = 1, lim = sqrt(x); i <= lim; i++) {
        if (x % i == 0) {
          cnt[i]--, ret += mu[i] * cnt[i];
          if (i * i != x) cnt[x / i]--, ret += mu[x / i] * cnt[x / i];
        }
      }
      ans -= ret;
    }
    cout << ans << '\n';
  }
  return 0;
}
