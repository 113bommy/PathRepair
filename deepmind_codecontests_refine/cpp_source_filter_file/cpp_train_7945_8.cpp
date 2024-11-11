#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e2 + 5;
const long long MOD = 1e9 + 7;
int n, res = 0;
struct point {
  int x, y;
} a[SIZE];
bool l, r, u, d;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  for (int i = 1; i < n; i++) {
    l = r = u = d = false;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (a[i].x == a[j].x && a[i].y > a[j].y) d = true;
      if (a[i].x == a[j].x && a[i].y < a[j].y) u = true;
      if (a[i].y == a[j].y && a[i].x < a[j].x) r = true;
      if (a[i].y == a[j].y && a[i].x > a[j].x) l = true;
    }
    if (l && r && u && d) res++;
  }
  cout << res;
  cout << '\n';
  return 0;
}
