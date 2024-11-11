#include <bits/stdc++.h>
using namespace std;
int x, y, n, m, hh, tt, tot, q[1001000], d[1001000], ans, fa[1001000],
    cnt[1001000];
int find(int x) {
  if (fa[x] == x)
    return x;
  else {
    fa[x] = find(fa[x]);
    return fa[x];
  }
}
void insert(int x) {
  tt++;
  d[tt] = x;
  x = tt;
  while (x > 1 && d[x] < d[x / 2]) {
    int tmp = d[x];
    d[x] = d[x / 2];
    d[x / 2] = tmp;
    x = x / 2;
  }
}
void down(int x) {
  while ((x * 2 <= tt && d[x * 2] < d[x]) ||
         (x * 2 + 1 <= tt && d[x * 2 + 1] < d[x])) {
    if (x * 2 + 1 <= tt && d[x * 2 + 1] < d[x * 2]) {
      int tmp = d[x];
      d[x] = d[x * 2 + 1];
      d[x * 2 + 1] = tmp;
      x = x * 2 + 1;
    } else {
      int tmp = d[x];
      d[x] = d[x * 2];
      d[x * 2] = tmp;
      x = x * 2;
    }
  }
}
int main() {
  cin >> n >> m >> hh;
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    x = find(x);
    y = find(y);
    fa[x] = y;
  }
  for (int i = 1; i <= n; i++) {
    fa[i] = find(i);
    cnt[fa[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) {
      tot++;
      q[tot] = cnt[i];
    }
  }
  sort(&q[1], &q[tot + 1]);
  int p = min(hh, q[tot]);
  insert(q[tot]);
  for (int i = tot - 1; i >= 1; i--) {
    if (p) {
      p--;
      insert(q[i]);
      p += min(q[i] - 1, hh - 1);
    } else {
      int oo = d[1];
      ans++;
      if (oo < hh) p += min(hh - oo, q[i]);
      d[1] = q[i] + oo;
      down(1);
    }
  }
  cout << ans << endl;
  return 0;
}
