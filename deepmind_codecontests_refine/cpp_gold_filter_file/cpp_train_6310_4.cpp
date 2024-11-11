#include <bits/stdc++.h>
using namespace std;
const long long INF = 100000000000000000ll;
const int N = 210;
struct P {
  int x, y;
  P() {}
  P(int x, int y) : x(x), y(y) {}
  P operator+(P p) { return P(x + p.x, y + p.y); }
  P operator-(P p) { return P(x - p.x, y - p.y); }
  long long det(P p) { return 1ll * x * p.y - 1ll * y * p.x; }
  bool operator<(P p) { return x < p.x || (x == p.x && y < p.y); }
};
P a[N], p[N];
bool cmp(P p1, P p2) { return p1.det(p2) > 0; }
struct E {
  P p;
  int id;
  E() {}
  E(P p, int id) : p(p), id(id) {}
};
E ea[N], eb[N];
bool cmp1(E e1, E e2) { return e1.p.det(e2.p) > 0; }
int n, K;
long long dp[N][N][N];
long long now[N];
long long ans;
int ok[N][N];
void work(int id) {
  int tot = 0;
  int ca = 0, cb = 0;
  int i, j, k, l;
  P tmp;
  for (i = 1; i <= n; i++)
    if (a[id] < a[i]) {
      p[++tot] = a[i] - a[id];
    }
  if (tot < 2) return;
  sort(p + 1, p + 1 + tot, cmp);
  p[0] = P(0, 0);
  for (i = 0; i <= tot; i++) {
    tmp = P(0, 0);
    for (j = i + 1; j <= tot; j++) {
      if ((p[j] - p[i]).det(tmp) > 0) {
        ok[i][j] = 0;
      } else {
        ok[i][j] = 1;
        tmp = p[j] - p[i];
      }
      ok[j][i] = ok[i][j];
    }
  }
  for (i = 0; i <= tot; i++)
    for (j = i + 1; j <= tot; j++)
      for (k = 0; k <= K; k++) dp[i][j][k] = -INF;
  for (i = 1; i <= tot; i++) dp[0][i][1] = 0;
  for (i = 1; i <= tot; i++) {
    ca = 0;
    cb = 0;
    for (j = 0; j <= i - 1; j++) {
      if (ok[j][i]) {
        ea[++ca] = E(p[j] - p[i], j);
      }
    }
    for (j = i + 1; j <= tot; j++) {
      if (ok[i][j]) {
        eb[++cb] = E(p[j] - p[i], j);
      }
    }
    sort(ea + 1, ea + 1 + ca, cmp1);
    sort(eb + 1, eb + 1 + cb, cmp1);
    for (l = 1; l <= K; l++) now[l] = -INF;
    k = 0;
    for (j = 1; j <= cb; j++) {
      while (k < ca && ea[k + 1].p.det(eb[j].p) < 0) {
        k++;
        for (l = 1; l <= K; l++) now[l] = max(now[l], dp[ea[k].id][i][l]);
      }
      for (l = 1; l <= K; l++)
        dp[i][eb[j].id][l + 1] = now[l] + p[i].det(p[eb[j].id]);
    }
  }
  for (i = 0; i <= tot; i++)
    for (j = i + 1; j <= tot; j++) ans = max(ans, dp[i][j][K - 1]);
}
int main() {
  int i;
  ans = -INF;
  scanf("%d%d", &n, &K);
  for (i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  for (i = 1; i <= n; i++) work(i);
  ans = max(ans, 0ll);
  if (ans & 1) {
    printf("%I64d.50\n", ans >> 1);
  } else
    printf("%I64d.00\n", ans >> 1);
}
