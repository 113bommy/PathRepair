#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, q;
struct Q {
  int type, x, y;
  void input() { scanf("%d%d%d", &type, &x, &y); }
} t[N];
int a[N];
int qry(int x) {
  for (int i = q; i; --i) {
    if (t[i].x > x || t[i].y < x) continue;
    if (t[i].type == 1) {
      --x;
      if (x < t[i].x) x = t[i].y;
    } else
      x = t[i].x + t[i].y - x;
  }
  return a[x];
}
int main() {
  scanf("%d%d%d", &n, &q, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= q; ++i) t[i].input();
  for (int x, i = 1; i <= m; ++i) {
    scanf("%d", &x);
    printf("%d%c", qry(x), i == m ? '\n' : ' ');
  }
  return 0;
}
