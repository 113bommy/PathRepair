#include <bits/stdc++.h>
using namespace std;
int n, m;
int nm;
int q;
int a[4000005];
int b[4000005];
int max1[4000005];
int add[4000005];
bool flag;
int ans;
void pushup(int id, int lson, int rson) {
  max1[id] = max(max1[lson], max1[rson]);
}
void pushdown(int id, int lson, int rson) {
  add[lson] += add[id];
  add[rson] += add[id];
  max1[lson] += add[id];
  max1[rson] += add[id];
  add[id] = 0;
}
void update(int s, int id, int l, int r, int x, int y) {
  int lson = id * 2;
  int rson = id * 2 + 1;
  int mid = (l + r) / 2;
  if (l > r || x > y || x > r || l > y) return;
  if (x <= l && r <= y) {
    if (s == 1) {
      add[id]++;
      max1[id]++;
    } else {
      add[id]--;
      max1[id]--;
    }
    return;
  }
  pushdown(id, lson, rson);
  update(s, lson, l, mid, x, y);
  update(s, rson, mid + 1, r, x, y);
  pushup(id, lson, rson);
}
void query(int id, int l, int r) {
  if (flag) return;
  int lson = id * 2;
  int rson = id * 2 + 1;
  int mid = (l + r) / 2;
  pushdown(id, lson, rson);
  if (l == r) {
    ans = l;
    flag = 1;
    return;
  }
  if (max1[rson] >= 1)
    query(rson, mid + 1, r);
  else
    query(lson, l, mid);
  pushup(id, lson, rson);
}
int main() {
  int i, j;
  int s, x;
  int temp;
  memset(max1, 0, sizeof(max1));
  memset(add, 0, sizeof(add));
  scanf("%d%d", &n, &m);
  nm = max(n, m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    update(1, 1, 1, 1000005 - 5, 1, a[i]);
  }
  for (i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    update(2, 1, 1, 1000005 - 5, 1, b[i]);
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d", &s, &i, &x);
    if (s == 1) {
      update(2, 1, 1, 1000005 - 5, 1, a[i]);
      update(1, 1, 1, 1000005 - 5, 1, x);
      a[i] = x;
    } else {
      update(1, 1, 1, 1000005 - 5, 1, b[i]);
      update(2, 1, 1, 1000005 - 5, 1, x);
      b[i] = x;
    }
    flag = 0;
    if (max1[1] + add[1] <= 0)
      ans = -1;
    else
      query(1, 1, 1000005 - 5);
    printf("%d\n", ans);
  }
}
