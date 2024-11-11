#include <bits/stdc++.h>
using namespace std;
map<int, int> cnt;
int t[300005 * 4];
int a[300005];
int n, m;
struct note {
  int Type, x, y, z;
} s[300005];
void buildnew(int v, int l, int r) {
  if (l == r) {
    t[v] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  buildnew(v << 1, l, mid);
  buildnew(v << 1 | 1, mid + 1, r);
  t[v] = max(t[v << 1], t[v << 1 | 1]);
}
void change(int v, int l, int r, int x, int y) {
  if (l == r) {
    t[v] = y;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    change(v << 1, l, mid, x, y);
  else
    change(v << 1 | 1, mid + 1, r, x, y);
  t[v] = max(t[v << 1], t[v << 1 | 1]);
}
int getmax(int v, int l, int r, int x, int y) {
  if (l == x && r == y) return t[v];
  int mid = (l + r) >> 1;
  if (y <= mid)
    return getmax(v << 1, l, mid, x, y);
  else if (x > mid)
    return getmax(v << 1 | 1, mid + 1, r, x, y);
  else
    return max(getmax(v << 1, l, mid, x, mid),
               getmax(v << 1 | 1, mid + 1, r, mid + 1, y));
}
void build(int v, int l, int r) {
  t[v] = 2e9;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(v << 1, l, mid);
  build(v << 1 | 1, mid + 1, r);
}
void mntag(int v, int l, int r, int x, int y, int z) {
  if (l == x && r == y) {
    t[v] = min(t[v], z);
    return;
  }
  int mid = (l + r) >> 1;
  if (y <= mid)
    mntag(v << 1, l, mid, x, y, z);
  else if (x > mid)
    mntag(v << 1 | 1, mid + 1, r, x, y, z);
  else
    mntag(v << 1, l, mid, x, mid, z),
        mntag(v << 1 | 1, mid + 1, r, mid + 1, y, z);
}
int getmin(int v, int l, int r, int x) {
  if (l == r) return t[v];
  int mid = (l + r) >> 1;
  if (x <= mid)
    return min(t[v], getmin(v << 1, l, mid, x));
  else
    return min(t[v], getmin(v << 1 | 1, mid + 1, r, x));
}
int main() {
  scanf("%d%d", &n, &m);
  build(1, 1, n);
  memset(a, 255, sizeof(a));
  for (int i = 1; i <= m; i++) {
    int Type, x, y, z;
    scanf("%d", &Type);
    if (Type == 1) {
      scanf("%d%d%d", &x, &y, &z);
      mntag(1, 1, n, x, y, z);
    } else {
      scanf("%d%d", &x, &y);
      if (a[x] == -1) a[x] = getmin(1, 1, n, x);
    }
    s[i].Type = Type;
    s[i].x = x;
    s[i].y = y;
    s[i].z = z;
  }
  for (int i = 1; i <= n; i++)
    if (a[i] == -1) a[i] = getmin(1, 1, n, i);
  buildnew(1, 1, n);
  for (int i = 1; i <= m; i++) {
    if (s[i].Type == 1) {
      if (getmax(1, 1, n, s[i].x, s[i].y) != s[i].z) {
        puts("NO");
        return 0;
      }
    } else {
      change(1, 1, n, s[i].x, s[i].y);
    }
  }
  puts("YES");
  for (int i = 1; i <= n; i++) cnt[a[i]]++;
  if (cnt[2e9] >= 2) {
    bool fi = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != 2e9) {
        printf("%d ", a[i]);
        continue;
      }
      if (!fi) {
        fi = 1;
        a[i] = (1 << 29) - 1;
      } else
        a[i] = 1e9;
      printf("%d ", a[i]);
    }
    return 0;
  }
  int own = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0 || a[i] == 2e9) continue;
    --cnt[a[i]];
    if (cnt[a[i]] > 0) {
      int wz = 0;
      for (int j = 0; j <= 30; j++) {
        if ((1 << j) <= a[i]) wz = j;
      }
      a[i] = (1 << wz) - 1;
      own |= a[i];
    } else
      own |= a[i];
  }
  int ned = 0;
  for (int i = 30; i >= 0; i--) {
    if (own & (1 << i)) continue;
    if (ned + (1 << i) > 1e9) continue;
    ned += 1 << i;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 2e9) a[i] = ned;
    printf("%d ", a[i]);
  }
  return 0;
}
