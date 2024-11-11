#include <bits/stdc++.h>
using namespace std;
int xx[10], yy[10], x[10], y[10], ansx[10], ansy[10], ans, a[10], used[10], px1,
    px2, py1, py2;
bool good(int &cur, int x) {
  if (cur == 1 << 29) {
    cur = x;
    return 1;
  }
  return cur == x;
}
int fy(int py1, int d) {
  int cur_res = 0, py2 = py1 + d;
  cur_res = max(abs(yy[1] - py1), cur_res);
  cur_res = max(abs(yy[2] - py1), cur_res);
  cur_res = max(abs(yy[3] - py2), cur_res);
  cur_res = max(abs(yy[4] - py2), cur_res);
  return cur_res;
}
int fx(int px1, int d) {
  int cur_res = 0, px2 = px1 + d;
  cur_res = max(abs(xx[1] - px1), cur_res);
  cur_res = max(abs(xx[2] - px1), cur_res);
  cur_res = max(abs(xx[3] - px2), cur_res);
  cur_res = max(abs(xx[4] - px2), cur_res);
  return cur_res;
}
void solve(int t1, int t2, int t3, int t4) {
  int i, d, l, r, t, p1, p2, cur_res = 0;
  for (i = 1; i <= 4; i++) {
    xx[i] = x[a[i]];
    yy[i] = y[a[i]];
  }
  px1 = px2 = py1 = py2 = 1 << 29;
  if (t1 && !good(px1, xx[1]))
    return;
  else if (!t1 && !good(py1, yy[1]))
    return;
  if (t2 && !good(px1, xx[2]))
    return;
  else if (!t2 && !good(py2, yy[2]))
    return;
  if (t3 && !good(px2, xx[3]))
    return;
  else if (!t3 && !good(py2, yy[3]))
    return;
  if (t4 && !good(px2, xx[4]))
    return;
  else if (!t4 && !good(py1, yy[4]))
    return;
  if (px1 == 1 << 29 && px2 == 1 << 29) {
    d = py2 - py1;
    if (d <= 0) return;
    l = -1000000000;
    r = 1000000000;
    while (r - l > 2) {
      t = (r - l) / 3;
      p1 = l + t;
      p2 = r - t;
      if (fx(p1, d) < fx(p2, d))
        r -= t;
      else
        l += t;
    }
    px1 = l;
    for (i = l + 1; i <= r; i++) {
      if (fx(i, d) < fx(px1, d)) px1 = i;
    }
    px2 = px1 + (py2 - py1);
  }
  if (px1 == 1 << 29) px1 = px2 - (py2 - py1);
  if (px2 == 1 << 29) px2 = px1 + (py2 - py1);
  if (py1 == 1 << 29 && py2 == 1 << 29) {
    d = px2 - px1;
    if (d <= 0) return;
    l = -1000000000;
    r = 1000000000;
    while (r - l > 2) {
      t = (r - l) / 3;
      p1 = l + t;
      p2 = r - t;
      if (fy(p1, d) < fy(p2, d))
        r -= t;
      else
        l += t;
    }
    py1 = l;
    for (i = l + 1; i <= r; i++) {
      if (fy(i, d) < fy(py1, d)) py1 = i;
    }
    py2 = py1 + (px2 - px1);
  }
  if (py1 == 1 << 29) py1 = py2 - (px2 - px1);
  if (py2 == 1 << 29) py2 = py1 + (px2 - px1);
  if (px1 >= px2 || py1 >= py2) return;
  if (px2 - px1 != py2 - py1) return;
  cur_res = max(abs(xx[1] - px1), cur_res);
  cur_res = max(abs(xx[2] - px1), cur_res);
  cur_res = max(abs(xx[3] - px2), cur_res);
  cur_res = max(abs(xx[4] - px2), cur_res);
  cur_res = max(abs(yy[1] - py1), cur_res);
  cur_res = max(abs(yy[2] - py2), cur_res);
  cur_res = max(abs(yy[3] - py2), cur_res);
  cur_res = max(abs(yy[4] - py1), cur_res);
  if (ans > cur_res) {
    ans = cur_res;
    ansx[a[1]] = px1;
    ansy[a[1]] = py1;
    ansx[a[2]] = px1;
    ansy[a[2]] = py2;
    ansx[a[3]] = px2;
    ansy[a[3]] = py2;
    ansx[a[4]] = px2;
    ansy[a[4]] = py1;
  }
}
void rec(int x, int y) {
  int i;
  a[x] = y;
  if (x == 4) {
    for (i = 0; i < 16; i++) {
      solve(i & 1, (i >> 1) & 1, (i >> 2) & 1, (i >> 3) & 1);
    }
    return;
  }
  for (i = 1; i <= 4; i++) {
    if (used[i]) continue;
    used[i] = 1;
    rec(x + 1, i);
    used[i] = 0;
  }
}
int main() {
  int t, i;
  cin >> t;
  while (t--) {
    ans = 1 << 29;
    for (i = 1; i <= 4; i++) {
      ansx[i] = ansy[i] = -1;
    }
    for (i = 1; i <= 4; i++) scanf("%d%d", &x[i], &y[i]);
    for (i = 1; i <= 4; i++) {
      used[i] = 1;
      rec(1, i);
      used[i] = 0;
    }
    if (ans == 1 << 29) {
      printf("-1\n");
    } else {
      printf("%d\n", ans);
      for (i = 1; i <= 4; i++) {
        printf("%d %d\n", ansx[i], ansy[i]);
      }
    }
  }
}
