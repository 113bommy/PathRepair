#include <bits/stdc++.h>
using namespace std;
struct point {
  long long int x, y;
} data[1000006];
long long int cnt[1000006];
int n, m;
long long int xmult(const long long int x1, const long long int y1,
                    const long long int x2, const long long int y2) {
  return (x1 * y2 - x2 * y1);
}
long long int cross(const point &p1, const point &p2, const point &q1,
                    const point &q2) {
  return xmult(p2.x - p1.x, p2.y - p1.y, q2.x - q1.x, q2.y - q1.y);
}
bool law(const point &p, const point &q) {
  if (p.y == q.y) return false;
  if (p.x == q.x && (p.x < 1 || p.x > n)) return false;
  long long int x = (q.x - p.x) * (-p.y) / (q.y - p.y) + p.x;
  if (xmult(x - p.x, -p.y, q.x - p.x, q.y - p.y) != 0) return false;
  if (x < 1 || x > n) return false;
  return true;
}
long long int get_point(const point &p, const point &q) {
  if (p.x == q.x) return p.x;
  long long int x = (q.x - p.x) * (-p.y) / (q.y - p.y) + p.x;
  return x;
}
bool on_line(const point &p1, const point &p2, const point &q) {
  if (cross(p1, p2, p1, q) == 0) return true;
  return false;
}
void check(int j, int k) {
  long long int ans = 2;
  for (int i(0); i < n; ++i) {
    if (i == k || i == j) continue;
    if (on_line(data[j], data[k], data[i])) ++ans;
  }
  if (!law(data[j], data[k])) return;
  int x = get_point(data[j], data[k]);
  cnt[x] = max(cnt[x], ans);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i(0); i < 1000006; ++i) cnt[i] = 1;
  for (int i(0); i < m; ++i) {
    scanf("%I64d%I64d", &data[i].x, &data[i].y);
  }
  for (int i(0); i < n; ++i) {
    for (int j(i + 1); j < n; ++j) {
      check(i, j);
    }
  }
  long long int ans = 0;
  for (int i(1); i <= n; ++i) {
    ans += cnt[i];
  }
  cout << ans << endl;
  return 0;
}
