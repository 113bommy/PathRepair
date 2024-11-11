#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
};
struct Circle {
  int r, x, y;
};
Point K[1005];
Circle C[1005];
bitset<1005> contain[1005];
inline long long sq(long long x) { return x * x; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> K[i].x >> K[i].y;
  }
  for (int i = 0; i < m; ++i) {
    cin >> C[i].r >> C[i].x >> C[i].y;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (sq(K[i].x - C[i].x) + sq(K[i].y - C[i].y) <= sq(C[i].r))
        contain[i][j] = 1;
    }
  }
  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    cout << contain[a].count() + contain[b].count() -
                2 * (contain[a] & contain[b]).count()
         << '\n';
  }
  return 0;
}
