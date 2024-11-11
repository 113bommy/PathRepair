#include <bits/stdc++.h>
using namespace std;
struct wp {
  int a, b, c;
};
struct xq {
  wp p[107];
} q[12];
struct node {
  int num;
  int len;
} t[107];
int n, m, k;
int cmp(node a, node b) { return a.len > b.len; }
int solve(int x, int y) {
  int i;
  for (i = 0; i < m; ++i) {
    t[i].num = i;
    t[i].len = q[y].p[i].b - q[x].p[i].a;
  }
  sort(t, t + n, cmp);
  int sum = 0;
  i = 0;
  int ct = k;
  while (i < m) {
    if (q[x].p[t[i].num].c < k && t[i].len > 0) {
      sum += t[i].len * (q[x].p[t[i].num].c);
      ct -= q[x].p[t[i].num].c;
    } else
      break;
    i++;
  }
  if (k > 0 && t[i].len > 0) sum += t[i].len * (ct);
  return sum;
}
int main() {
  int i, j;
  char s[12];
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    for (i = 0; i < n; ++i) {
      scanf("%s", s);
      for (j = 0; j < m; ++j) {
        scanf("%d%d%d", &q[i].p[j].a, &q[i].p[j].b, &q[i].p[j].c);
      }
    }
    int ans = -999999;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        if (i == j) continue;
        int tmp = solve(i, j);
        if (ans < tmp) ans = tmp;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
