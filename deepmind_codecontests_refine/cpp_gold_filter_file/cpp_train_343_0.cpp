#include <bits/stdc++.h>
using namespace std;
int n, m, N, k;
struct Node {
  int c, id;
  bool operator<(const Node &b) const { return c > b.c; }
} p[1005], q[1005];
int ans[1001][1001], r[1001], mi[1001];
int main() {
  while (~scanf("%d%d", &N, &k)) {
    n = m = 0;
    double sum = 0.0;
    for (int i = 1; i <= N; i++) {
      int c, t;
      scanf("%d%d", &c, &t);
      sum += (double)c;
      if (t == 1) {
        p[n].c = c;
        p[n++].id = i;
      } else {
        q[m].c = c;
        q[m++].id = i;
      }
    }
    sort(p, p + n);
    sort(q, q + m);
    memset(r, 0, sizeof(r));
    int hav = min(k, n);
    for (int i = 0; i < hav; i++) {
      ans[i][r[i]++] = p[i].id;
      mi[i] = p[i].c;
    }
    if (k < n) {
      for (int i = k; i < n; i++) {
        ans[k - 1][r[k - 1]++] = p[i].id;
        mi[k - 1] = p[i].c;
      }
    } else {
      for (int i = n; i < k; i++) {
        ans[i][r[i]++] = q[m - 1].id;
        mi[i] = q[--m].c;
      }
    }
    int tp = 0;
    for (int i = 0; i < m; i++) {
      int f = 0;
      for (int j = 0; j < k; j++) {
        if (q[i].c >= mi[j]) {
          f = 1;
          ans[j][r[j]++] = q[i].id;
          break;
        }
      }
      if (!f) {
        ans[k - 1][r[k - 1]++] = q[i].id;
        mi[k - 1] = q[i].c;
      }
    }
    for (int i = 0; i < min(k, n); i++) sum -= 0.5 * (double)mi[i];
    printf("%.1f\n", sum);
    for (int i = 0; i < k; i++) {
      printf("%d", r[i]);
      for (int j = 0; j < r[i]; j++) printf(" %d", ans[i][j]);
      puts("");
    }
  }
}
