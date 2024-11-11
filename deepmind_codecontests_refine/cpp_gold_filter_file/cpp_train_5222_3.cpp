#include <bits/stdc++.h>
using namespace std;
const long long sz = 2e5 + 5;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct point {
  int x, l, r;
};
void solve() {
  int n, h, m;
  cin >> n >> h >> m;
  vector<point> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].l >> v[i].r >> v[i].x;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int temp = INT_MAX;
    int f = 0;
    for (int j = 0; j < m; j++) {
      if (i + 1 >= v[j].l && i + 1 <= v[j].r) {
        temp = min(temp, v[j].x);
        f = 1;
      }
    }
    if (f == 0) temp = h;
    ans += temp * temp;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
