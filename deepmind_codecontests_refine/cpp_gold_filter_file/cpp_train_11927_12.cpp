#include <bits/stdc++.h>
using namespace std;
const int N = 2005, M = 1e6 + 5;
int n, m, k, Q, len[N], _q[N], tp, sta[N];
long long ans[N], val[N][N];
char ch[10];
struct node {
  int x, y, w;
} p[N][N];
struct ask {
  int op, x1, y1, x2, y2;
  ask(int op = 0, int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)
      : op(op), x1(x1), y1(y1), x2(x2), y2(y2) {}
} q[M];
struct bit {
  long long t[N][N];
  bit() { memset(t, 0, sizeof(t)); }
  void add(int x, int y, int v) {
    for (int i = x; i <= n; i += i & -i)
      for (int j = y; j <= m; j += j & -j) t[i][j] += v;
  }
  long long qry(int x, int y) {
    long long s = 0;
    for (int i = x; i; i -= i & -i)
      for (int j = y; j; j -= j & -j) s += t[i][j];
    return s;
  }
} T;
long long qry(int x1, int y1, int x2, int y2) {
  return T.qry(x2, y2) - T.qry(x1 - 1, y2) - T.qry(x2, y1 - 1) +
         T.qry(x1 - 1, y1 - 1);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (1); i <= (k); i++) {
    scanf("%d", &len[i]);
    for (int j = (1); j <= (len[i]); j++)
      scanf("%d%d%d", &p[i][j].x, &p[i][j].y, &p[i][j].w);
  }
  scanf("%d", &Q);
  for (int i = (1); i <= (Q); i++) {
    int x, x1, y1, x2, y2;
    scanf("%s", ch);
    if (ch[0] == 'S')
      scanf("%d", &x), q[i] = ask(0, x);
    else
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2), q[i] = ask(1, x1, y1, x2, y2),
                                             _q[++tp] = i;
  }
  for (int i = (1); i <= (k); i++) {
    for (int j = (1); j <= (len[i]); j++)
      T.add(p[i][j].x, p[i][j].y, p[i][j].w);
    for (int j = (1); j <= (tp); j++) {
      int t = _q[j];
      val[i][j] = qry(q[t].x1, q[t].y1, q[t].x2, q[t].y2);
    }
    for (int j = (1); j <= (len[i]); j++)
      T.add(p[i][j].x, p[i][j].y, -p[i][j].w);
  }
  tp = 0;
  for (int i = (1); i <= (k); i++) sta[i] = 1;
  for (int i = (1); i <= (Q); i++)
    if (q[i].op == 0)
      sta[q[i].x1] ^= 1;
    else {
      long long ans = 0;
      ++tp;
      for (int j = (1); j <= (k); j++)
        if (sta[j]) ans += val[j][tp];
      printf("%lld\n", ans);
    }
  return 0;
}
