#include <bits/stdc++.h>
using namespace std;
int n, m, k, s, t1, t2, t3, ans[5005][5005];
struct st {
  int z, a, num, x;
} b[100005], r[5005], c[5005];
bool comp(st p, st q) {
  if (p.x != q.x) return p.x < q.x;
}
int main() {
  int i, j;
  cin >> n >> m >> k;
  for (i = 1; i <= k; i++) {
    scanf("%d %d %d", &t1, &t2, &t3);
    if (t1 == 1) {
      r[t2].z = 1;
      r[t2].a = t2;
      r[t2].num = t3;
      r[t2].x = i;
    } else {
      c[t2].z = 2;
      c[t2].a = t2;
      c[t2].num = t3;
      c[t2].x = i;
    }
  }
  for (i = 1; i <= n; i++) {
    if (r[i].x == 0) continue;
    b[s].z = 1;
    b[s].a = r[i].a;
    b[s].num = r[i].num;
    b[s++].x = r[i].x;
  }
  for (i = 1; i <= m; i++) {
    if (c[i].x == 0) continue;
    b[s].z = 2;
    b[s].a = c[i].a;
    b[s].num = c[i].num;
    b[s++].x = c[i].x;
  }
  sort(b, b + s, comp);
  for (i = 0; i < s; i++) {
    if (b[i].z == 1) {
      for (j = 1; j <= m; j++) {
        ans[b[i].a][j] = b[i].num;
      }
    } else {
      for (j = 1; j <= n; j++) {
        ans[j][b[i].a] = b[i].num;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
