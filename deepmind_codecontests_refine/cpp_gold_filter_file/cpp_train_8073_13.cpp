#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int L, n, p, t, f[N], g[N];
int main() {
  scanf("%d%d%d%d", &L, &n, &p, &t);
  g[0] = -t;
  for (int i = 1, j = 0; i <= n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (j) j--;
    while (j < i && g[j] + t <= r) {
      l = max(l, g[j] + t);
      if (f[j] + (r - l) / p > f[i]) {
        f[i] = f[j] + (r - l) / p;
        g[i] = l + (r - l) / p * p;
      } else if (f[j] + (r - l) / p == f[i]) {
        g[i] = min(g[i], l + (r - l) / p * p);
      }
      j++;
    }
    if (f[i - 1] > f[i]) {
      f[i] = f[i - 1];
      g[i] = g[i - 1];
    } else if (f[i - 1] == f[i]) {
      g[i] = min(g[i], g[i - 1]);
    }
  }
  cout << f[n] << endl;
}
