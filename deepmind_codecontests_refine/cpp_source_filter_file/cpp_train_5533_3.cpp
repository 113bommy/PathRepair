#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
inline int read() {
  int x = 0, neg = 1;
  char op = getchar();
  while (!isdigit(op)) {
    if (op == '-') neg = -1;
    op = getchar();
  }
  while (isdigit(op)) {
    x = 10 * x + op - '0';
    op = getchar();
  }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 500005;
const int mod = 1e9 + 7;
vector<int> pr, d[N];
int vis[N], mu[N], inv[N];
void pre(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr.push_back(i), mu[i] = -1;
    for (auto v : pr) {
      if (i * v > n) break;
      vis[i * v] = 1;
      if (i % v == 0) break;
      mu[i * v] = -mu[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      d[j].push_back(i);
    }
  }
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  }
}
int f[N], g[N], m;
int main() {
  scanf("%d", &m);
  pre(m);
  int res = 0;
  f[1] = 0;
  for (int i = 2; i <= m; i++) {
    f[i] = m;
    for (auto T : d[i]) {
      f[i] = (f[i] + 1ll * (m / T) * g[T]) % mod;
    }
    f[i] = 1ll * f[i] * inv[m - (m / i)] % mod;
    res = (res + f[i]) % mod;
    for (int j = i; j <= m; j += i) {
      g[j] = (g[j] + 1ll * f[i] * mu[j / i]) % mod;
    }
  }
  res = 1ll * res * inv[m] % mod;
  res++;
  printf("%lld\n", (res % mod + mod) % mod);
  return 0;
}
