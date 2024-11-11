#include <bits/stdc++.h>
using namespace std;
struct node {
  long double x, y;
  node(long double X = 0.0, long double Y = 0.0) { x = X, y = Y; }
} que[200005];
int n, k;
int t[200005], head, tail;
long double s[200005], a[200005], b[200005], f[2][200005];
long double K(node, node);
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", t + i);
    s[i] = s[i - 1] + t[i];
    a[i] = a[i - 1] + s[i] / t[i];
    b[i] = b[i - 1] + 1.0 / t[i];
  }
  int now = 1, lst = 0;
  for (int i = 1; i <= n; ++i) f[now][i] = 9999999999999999;
  for (int p = 1; p <= k; ++p) {
    swap(now, lst);
    head = tail = 0;
    que[tail++] = node(0, 0);
    for (int i = 1; i <= n; ++i) {
      while (head + 1 < tail)
        if (K(que[head], que[head + 1]) < b[i])
          ++head;
        else
          break;
      f[now][i] = que[head].y - que[head].x * b[i] + a[i];
      node tmp(s[i], f[lst][i] - a[i] + s[i] * b[i]);
      while (head < tail - 1)
        if (K(que[tail - 1], que[tail - 2]) > K(que[tail - 2], tmp))
          --tail;
        else
          break;
      que[tail++] = tmp;
    }
  }
  printf("%.10lf", (double)f[now][n]);
  return 0;
}
long double K(node x, node y) { return (x.y - y.y) / (x.x - y.x); }
