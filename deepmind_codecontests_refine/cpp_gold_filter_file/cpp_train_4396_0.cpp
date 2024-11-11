#include <bits/stdc++.h>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ') {
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
const int N = 1e5 + 5;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int n, m, mu[N], cnt[N], sign[N], s[N], top;
vector<int> d[N];
long long ans = 1;
int estimate(int n) {
  int ret = 0;
  for (int i = 0; i < d[n].size(); ++i) ret += cnt[d[n][i]] * mu[d[n][i]];
  return ret;
}
void update(int n, int v) {
  for (int i = 0; i < d[n].size(); ++i) cnt[d[n][i]] += v;
}
int main() {
  m = read();
  for (int i = 1, a; i <= m; ++i) sign[a = read()] = 1, n = max(a, n);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) d[j].push_back(i);
    if (i == 1)
      mu[i] = 1;
    else
      mu[i] = -(i / d[i][1] % d[i][1] != 0) * mu[i / d[i][1]];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = i << 1; j <= n; j += i) sign[i] |= sign[j];
  for (int i = n; i; --i)
    if (sign[i]) {
      m = estimate(i);
      while (m) {
        if (gcd(s[top], i) == 1) ans = max(ans, 1ll * i * s[top]), --m;
        update(s[top--], -1);
      }
      update(s[++top] = i, 1);
    }
  printf("%lld\n", ans);
  return 0;
}
