#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
bool used[N];
struct Point {
  long long x, y, id;
} p[N], q[N];
int n, m, tt[N];
long long ans;
bool cmpx(const Point &a, const Point &b) { return a.x < b.x; }
bool cmpy(const Point &a, const Point &b) { return a.y < b.y; }
void calc() {
  long long x1, x2, y1, y2;
  for (int i = 1; i <= n; i++) {
    if (!used[p[i].id]) {
      x1 = p[i].x;
      break;
    }
  }
  for (int i = n; i >= 1; i--)
    if (!used[p[i].id]) {
      x2 = p[i].x;
      break;
    }
  for (int i = 1; i <= n; i++)
    if (!used[q[i].id]) {
      y1 = q[i].y;
      break;
    }
  for (int i = n; i >= 1; i--)
    if (!used[q[i].id]) {
      y2 = q[i].y;
      break;
    }
  long long dx = x2 - x1;
  long long dy = y2 - y1;
  if (dx % 2 == 1) dx++;
  if (dy % 2 == 1) dy++;
  if (dx == 0) dx += 2;
  if (dy == 0) dy += 2;
  long long s = dx * dy;
  if (ans == -1 || s < ans) ans = s;
}
void check(int t1, int t2, int t3) {
  int t4 = m - t1 - t2 - t3;
  int num = 0;
  int zz;
  zz = 1;
  while (t1) {
    if (!used[p[zz].id]) {
      used[p[zz].id] = 1;
      tt[++num] = p[zz].id;
      t1--;
    }
    zz++;
  }
  zz = n;
  while (t2) {
    if (!used[p[zz].id]) {
      used[p[zz].id] = 1;
      tt[++num] = p[zz].id;
      t2--;
    }
    zz--;
  }
  zz = 1;
  while (t3) {
    if (!used[q[zz].id]) {
      used[q[zz].id] = 1;
      tt[++num] = q[zz].id;
      t3--;
    }
    zz++;
  }
  zz = n;
  while (t4) {
    if (!used[q[zz].id]) {
      used[q[zz].id] = 1;
      tt[++num] = q[zz].id;
      t4--;
    }
    zz--;
  }
  calc();
  for (int i = 1; i <= num; i++) used[tt[i]] = 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    p[i].x = x1 + x2;
    p[i].y = y1 + y2;
    p[i].id = i;
    q[i] = p[i];
  }
  sort(p + 1, p + n + 1, cmpx);
  sort(q + 1, q + n + 1, cmpy);
  ans = -1;
  for (int i = 0; i <= m; i++)
    for (int j = 0; i + j <= m; j++)
      for (int k = 0; i + j + k <= m; k++) check(i, j, k);
  cout << ans / 4 << endl;
  return 0;
}
