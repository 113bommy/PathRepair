#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000010;
const int N = 403;
int a[N];
int n;
int calc(int* g, int x) {
  int c = 0;
  for (int i = 1; i <= n; ++i) {
    g[i] = x / a[i];
    c += g[i];
    x %= a[i];
  }
  return c;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  int best = INF;
  for (int i = 1; i < n; ++i) {
    int g[N];
    int c = calc(g, a[i] - 1);
    int x = a[i] - 1;
    for (int j = n; j > 1; --j) {
      int h[N];
      if (c + 1 < calc(h, x + a[j]) && best > x + a[j]) best = x + a[j];
      x -= g[i] * a[i];
      c -= g[i];
    }
  }
  if (best < INF)
    printf("%d\n", best);
  else
    puts("-1");
  return 0;
}
