#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int a[maxn], b[maxn], posb[maxn];
struct node {
  int x, y;
  node(int a = 0, int b = 0) : x(a), y(b) {}
} p[maxn];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i]);
      posb[b[i]] = i;
    }
    int res, nu;
    res = nu = 0;
    for (int i = 1; i <= n; i++) {
      int val = a[i];
      int x = i;
      for (int j = i - 1; j >= 1; --j) {
        int nxt = a[j];
        if (posb[nxt] >= x && posb[val] <= j) {
          swap(a[x], a[j]);
          res += abs(x - j);
          p[nu++] = node(x, j);
          x = j;
        }
      }
    }
    printf("%d\n%d\n", res, nu);
    for (int i = 0; i < nu; i++) printf("%d %d\n", p[i].x, p[i].y);
  }
  return 0;
}
