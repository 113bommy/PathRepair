#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
const int maxl = 610;
int n;
char ss[8];
struct node {
  int no;
  int id;
  int x;
  bool operator<(const node a) const { return x > a.x; }
} d[maxn], s[maxn];
int scnt, pre[maxn], last[2010];
int ans[maxl], mi[2001][maxl];
int p[2010];
void add(int *a, int *b) {
  if (a[0] < b[0]) a[0] = b[0];
  for (int i = 1; i <= a[0]; i++) a[i] += b[i];
  for (int i = 1; i <= a[0]; i++) {
    a[i + 1] += a[i] / 10;
    a[i] %= 10;
  }
  if (a[a[0] + 1]) a[0]++;
}
int main() {
  ans[0] = 1;
  mi[0][0] = mi[0][1] = 1;
  for (int i = 1; i <= 2000; i++) {
    add(mi[i], mi[i - 1]);
    add(mi[i], mi[i - 1]);
  }
  memset(last, 0xff, sizeof(last));
  memset(pre, 0xff, sizeof(pre));
  memset(p, 0xff, sizeof(p));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s%d", ss, &d[i].x);
    d[i].no = i;
    if (ss[0] == 'w') {
      d[i].id = 0;
      pre[i] = last[d[i].x];
      last[d[i].x] = i;
    } else {
      d[i].id = 1;
      s[scnt++] = d[i];
      p[d[i].x] = i;
    }
  }
  sort(s, s + scnt);
  for (int i = 0; i < scnt; i++) {
    int cur = last[s[i].x];
    while (cur != -1 && cur > s[i].no) cur = pre[cur];
    while (cur != -1 && d[cur].id != 0) cur = pre[cur];
    if (cur != -1) {
      add(ans, mi[s[i].x]);
      for (int j = 0; j < s[i].no; j++) {
        if (p[d[j].x] > s[i].no) d[j].id = 2;
      }
    }
  }
  for (int i = ans[0]; i; i--) printf("%d", ans[i]);
  printf("\n");
  return 0;
}
