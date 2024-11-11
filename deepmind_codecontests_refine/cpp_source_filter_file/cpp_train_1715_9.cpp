#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
struct sq {
  int p, l, id;
};
int f[210000];
int p[210000];
int l[210000];
int u[210000];
sq q[210000];
int g[210000][35];
int w[210000][35];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", p + i, l + i);
  int r = 0;
  for (int i = n; i >= 1; i--) {
    int t = p[i] + l[i];
    f[i] = i;
    while (r && t >= q[r].p) {
      t = max(t, q[r].l);
      f[i] = q[r].id;
      r--;
    }
    r++;
    q[r].p = p[i];
    q[r].l = t;
    q[r].id = f[i];
    u[i] = t;
  }
  for (int i = 1; i <= n; i++) {
    int t = f[i];
    if (t + 1 <= n) {
      g[i][1] = f[t + 1];
      w[i][1] = p[t + 1] - u[t];
    } else {
      g[i][1] = n;
      w[i][1] = 0;
    }
  }
  for (int k = 2; k <= 30; k++)
    for (int i = 1; i <= n; i++) {
      int t = g[i][k - 1];
      g[i][k] = g[t][k - 1];
      w[i][k] = w[i][k - 1] + w[t + 1][k - 1];
    }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int ans = 0;
    while (x < y) {
      if (f[x] >= y) break;
      int k;
      for (k = 1; k <= 30; k++)
        if (g[x][k] >= y) break;
      if (k == 1) {
        ans += w[x][k];
        break;
      }
      ans += w[x][k - 1];
      x = g[x][k - 1];
    }
    printf("%d\n", ans);
  }
}
