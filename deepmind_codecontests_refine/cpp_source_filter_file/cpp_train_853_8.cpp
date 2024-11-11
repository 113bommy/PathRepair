#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const int maxn = 510000;
int c[maxn], ts[maxn], has[10];
struct node {
  int x[3];
} p[maxn];
int cmp(node a, node b) { return a.x[0] < b.x[0]; }
int n, m;
int lowbit(int t) { return t & -t; }
int min(int a, int b) { return a < b ? a : b; }
int sum(int p) {
  int ret = INF;
  while (p) {
    ret = min(ret, c[p]);
    p -= lowbit(p);
  }
  return ret;
}
void add(int p, int d) {
  while (p <= n) {
    c[p] = min(c[p], d);
    p += lowbit(p);
  }
}
void make(int j) {
  int i;
  for (i = 0; i < m; i++) ts[i] = p[i].x[j];
  sort(ts, ts + m);
  has[j] = unique(ts, ts + m) - ts;
  for (i = 0; i < m; i++) {
    p[i].x[j] = lower_bound(ts, ts + has[j], p[i].x[j]) - ts;
    p[i].x[j] = has[j] - p[i].x[j];
  }
}
int main() {
  int i, j, k;
  while (scanf("%d", &m) > 0) {
    for (i = 0; i <= m; i++) c[i] = INF;
    for (j = 0; j < 3; j++)
      for (i = 0; i < m; i++) scanf("%d", &p[i].x[j]);
    for (j = 0; j < 3; j++) make(j);
    sort(p, p + m, cmp);
    n = has[1] + 1;
    int cnt = 0;
    for (i = 0; i < m;) {
      j = i;
      while (p[j].x[0] == p[i].x[0]) {
        int temp = sum(p[j].x[1]);
        if (temp < p[j].x[2]) cnt++;
        j++;
      }
      j = i;
      while (p[j].x[0] == p[i].x[0]) {
        add(p[j].x[1], p[j].x[2]);
        j++;
      }
      i = j;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
