#include <bits/stdc++.h>
using namespace std;
const int Lim = 1e9;
int val[1200010];
void build(int root, int l, int r) {
  val[root] = Lim + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(root << 1, l, mid);
  build(root << 1 | 1, mid + 1, r);
  return;
}
int calc(int root, int l, int r, int x) {
  if (l == r) return val[root];
  int res = val[root], mid = (l + r) >> 1;
  if (x <= mid)
    res = min(res, calc(root << 1, l, mid, x));
  else
    res = min(res, calc(root << 1 | 1, mid + 1, r, x));
  return res;
}
void change(int root, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    val[root] = min(val[root], z);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) change(root << 1, l, mid, x, y, z);
  if (y > mid) change(root << 1 | 1, mid + 1, r, x, y, z);
  return;
}
int mx[1200010];
void modify(int root, int l, int r, int x, int y) {
  if (l == r) {
    mx[root] = y;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    modify(root << 1, l, mid, x, y);
  else
    modify(root << 1 | 1, mid + 1, r, x, y);
  mx[root] = max(mx[root << 1], mx[root << 1 | 1]);
  return;
}
int query(int root, int l, int r, int x, int y) {
  if (x <= l && r <= y) return mx[root];
  int mid = (l + r) >> 1, ans = 0;
  if (x <= mid) ans = max(ans, query(root << 1, l, mid, x, y));
  if (y > mid) ans = max(ans, query(root << 1 | 1, mid + 1, r, x, y));
  return ans;
}
map<int, int> cnt;
int a[300010];
struct Madoka {
  int x, y, z;
} v[300010];
int getval(int x) {
  int s = 1;
  while (s * 2 <= x) s <<= 1;
  return s - 1;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) a[i] = -1;
  for (int i = 1; i <= m; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1)
      scanf("%d %d %d", &v[i].x, &v[i].y, &v[i].z);
    else {
      scanf("%d %d", &v[i].x, &v[i].y);
      v[i].z = -1;
    }
  }
  build(1, 1, n);
  for (int i = 1; i <= m; i++)
    if (v[i].z < 0) {
      if (a[v[i].x] == -1) a[v[i].x] = calc(1, 1, n, v[i].x);
    } else
      change(1, 1, n, v[i].x, v[i].y, v[i].z);
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1) a[i] = calc(1, 1, n, i);
    cnt[a[i]]++;
    modify(1, 1, n, i, a[i]);
  }
  for (int i = 1; i <= m; i++)
    if (v[i].z < 0)
      modify(1, 1, n, v[i].x, v[i].y);
    else if (query(1, 1, n, v[i].x, v[i].y) != v[i].z) {
      printf("NO\n");
      return 0;
    }
  if (cnt[Lim + 1] > 1) {
    bool vis = false;
    for (int i = 1; i <= n; i++)
      if (a[i] == Lim + 1) {
        if (!vis) {
          a[i] = (1 << 29) - 1;
          vis = true;
        } else
          a[i] = Lim;
      }
  } else {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt[a[i]] > 1) {
        cnt[a[i]]--;
        a[i] = getval(a[i]);
      }
      if (a[i] <= Lim) sum |= a[i];
    }
    int num = 0;
    for (int i = 29; i >= 0; i--)
      if (!(sum & (1 << i)) && (num + (1 << i)) <= Lim) num += 1 << i;
    for (int i = 1; i <= n; i++)
      if (a[i] > Lim) a[i] = num;
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
