#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 100 * 1000 + 5;
struct point {
  long long x, y;
  bool operator<(const point& p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
} p[maxn], v[maxn], convex[maxn], s[maxn];
int n;
int m;
long long cross(point& o, point& p, point& q) {
  return (p.x - o.x) * (q.y - o.y) - (p.y - o.y) * (q.x - o.x);
}
int convexHull() {
  int k = 0, i, t, r = m + n;
  sort(p, p + r);
  for ((i) = 0; (i) < (r); (i)++) {
    while (k >= 2 && cross(convex[k - 2], convex[k - 1], p[i]) < 0LL) k--;
    convex[k++] = p[i];
  }
  for (i = r - 2, t = k + 1; i >= 0; i--) {
    while (k >= t && cross(convex[k - 2], convex[k - 1], p[i]) < 0LL) k--;
    convex[k++] = p[i];
  }
  return k;
}
int main() {
  int i, k;
  ios::sync_with_stdio(false);
  cin >> n;
  for ((i) = 0; (i) < (n); (i)++) cin >> v[i].x >> v[i].y;
  cin >> m;
  for ((i) = 0; (i) < (m); (i)++) {
    cin >> p[i].x >> p[i].y;
    s[i] = p[i];
  }
  for ((i) = (m); (i) < (m + n); (i)++) p[i] = v[i - m];
  sort(s, s + m);
  sort(v, v + n);
  k = convexHull();
  sort(convex, convex + k);
  bool flag = true;
  for ((i) = 0; (i) < (k); (i)++) {
    if (binary_search(s, s + m, convex[i])) {
      flag = false;
      break;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
