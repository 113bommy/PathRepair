#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
const int INF = 1e9 + 7;
const int MAXN = int(3e5 + 7);
struct pt {
  int x, y;
} p[MAXN];
long long dist(pt a, pt b) {
  return 1ll * (a.x - b.x) * (a.x - b.x) + 1ll * (a.y - b.y) * (a.y - b.y);
}
long long area(pt a, pt b, pt c) {
  long long d =
      1ll * (b.x - a.x) * (c.y - a.y) - 1ll * (b.y - a.y) * (c.x - a.x);
  return abs(d);
}
int n, ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  long long d = dist(p[1], p[2]);
  int a = 1, b = 2, c;
  for (int i = 2; i <= n; i++) {
    if (dist(p[a], p[i]) < d) {
      d = dist(p[a], p[i]);
      b = i;
    }
  }
  double ar = 6e18;
  for (int i = 2; i <= n; i++) {
    if (b == i) continue;
    if (area(p[a], p[b], p[i]) < ar && area(p[a], p[b], p[i]) != 0) {
      ar = area(p[a], p[b], p[i]);
      c = i;
    }
  }
  cout << a << " " << b << " " << c << endl;
  return 0;
}
