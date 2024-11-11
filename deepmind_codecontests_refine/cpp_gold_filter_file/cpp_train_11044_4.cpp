#include <bits/stdc++.h>
using namespace std;
int bl_size;
int n, nq, tot = 0;
int a[500000 + 10];
bool ok[500000 + 10];
int bl[1000];
int d[500000 + 10];
struct Query {
  int l, r, id;
};
Query q[500000 + 10];
bool cmp(Query a, Query b) {
  if (a.l / bl_size != b.l / bl_size) return a.l < b.l;
  if (a.l / bl_size & 1)
    return a.r < b.r;
  else
    return a.r > b.r;
}
inline void add(int x) {
  d[x]++;
  if (d[x] == 1) {
    ok[x] = true;
    bl[x / bl_size]++;
    tot++;
  } else if (d[x] == 2) {
    ok[x] = false;
    bl[x / bl_size]--;
    tot--;
  }
}
inline void rem(int x) {
  d[x]--;
  if (d[x] == 1) {
    ok[x] = true;
    bl[x / bl_size]++;
    tot++;
  } else if (d[x] == 0) {
    ok[x] = false;
    bl[x / bl_size]--;
    tot--;
  }
}
int get() {
  if (tot == 0) return 0;
  for (int i = 0; i <= bl_size; i++)
    if (bl[i]) {
      for (int j = i * bl_size;; ++j)
        if (ok[j]) return j;
    }
  return 0;
}
int main() {
  scanf("%d", &n);
  bl_size = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &nq);
  for (int i = 1; i <= nq; i++) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
  sort(q + 1, q + nq + 1, cmp);
  int ans[500000 + 10];
  memset(ok, false, sizeof(ok));
  memset(d, 0, sizeof(d));
  memset(bl, 0, sizeof(bl));
  memset(ans, 0, sizeof(ans));
  int cur_l = 1, cur_r = 0;
  for (int i = 1; i <= nq; i++) {
    while (cur_r < q[i].r) {
      cur_r++;
      add(a[cur_r]);
    }
    while (cur_r > q[i].r) {
      rem(a[cur_r]);
      cur_r--;
    }
    while (cur_l > q[i].l) {
      cur_l--;
      add(a[cur_l]);
    }
    while (cur_l < q[i].l) {
      rem(a[cur_l]);
      cur_l++;
    }
    ans[q[i].id] = get();
  }
  for (int i = 1; i <= nq; i++) printf("%d\n", ans[i]);
}
