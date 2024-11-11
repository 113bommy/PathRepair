#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int maxn = 1e6 + 10;
bool g[maxn];
int s[maxn];
int f(int x) {
  if (x == 0) return 1;
  long long a = f(x / 2);
  if (x & 1)
    return (a * a * 2) % M;
  else
    return (a * a) % M;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int l = 0, r = n - k - 2, tl = 0, tr = n;
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (y - x != 1 && y - x != k + 1) {
      printf("0\n");
      return 0;
    }
    if (y - x == k + 1) {
      g[x - 1] = true;
      l = max(l, x - k - 1);
      r = min(r, y - 2);
      tl = max(tl, x - 1);
      tr = min(tr, y - 1);
    }
  }
  if (tl > r || tr < l) {
    printf("0\n");
    return 0;
  }
  s[0] = !g[0];
  for (int i = 1; i < n; ++i) {
    s[i] = s[i - 1] + !g[i];
  }
  long long ans = 1;
  for (int i = l; i <= r; ++i) {
    if (!g[i]) ans += f(s[min(i + k, r)] - s[i]);
    ans %= M;
  }
  printf("%d\n", (int)ans);
  return 0;
}
