#include <bits/stdc++.h>
const int MAXN = 1e6;
struct Point {
  long long x, y;
  friend bool operator<(Point a, Point b) { return a.y < b.y; }
} now[MAXN], p[MAXN];
int n;
long long s[MAXN];
long long dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
long long divide(int l, int r) {
  long long dis = 1e18;
  if (l == r) return dis;
  if (l + r == r) return dist(p[l], p[r]);
  int mid = (l + r) >> 1;
  long long dis1 = divide(l, mid);
  long long dis2 = divide(mid + 1, r);
  dis = std::min(dis1, dis2);
  int num = 0;
  for (int i = l; i <= r; i++) {
    if ((p[mid].x - p[i].x) * (p[mid].x - p[i].x) <= dis) now[++num] = p[i];
  }
  std::sort(now, now + num + 1);
  for (int i = 1; i <= num; i++) {
    for (int j = i + 1;
         j <= num && (now[j].y - now[i].y) * (now[j].y - now[i].y) <= dis;
         j++) {
      long long dis3 = dist(now[i], now[j]);
      dis = std::min(dis, dis3);
    }
  }
  return dis;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x), s[i] = s[i - 1] + 1ll * x;
  }
  for (int i = 1; i <= n; i++) p[i].x = i, p[i].y = s[i];
  printf("%I64d", divide(1, n));
  return 0;
}
