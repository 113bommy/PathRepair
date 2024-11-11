#include <bits/stdc++.h>
using namespace std;
long long g[200010], f[200010];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int main() {
  int L = read(), n = read();
  int p = read(), t = read();
  g[0] = -t;
  int l = 1, r = 1;
  for (int i = 1; i <= n; i++) {
    long long x = read(), y = read();
    f[i] = f[i - 1], g[i] = g[i - 1];
    --l;
    while (l <= r && g[l] + t <= y) {
      long long a = max(g[l] + t, x), b = f[l] + (y - a) / p,
                c = y - (y - a) % p;
      if (b > f[i] || b == f[i] && c < g[i]) f[i] = b, g[i] = c;
      l++;
    }
    r++;
  }
  cout << f[n] << endl;
  return 0;
}
