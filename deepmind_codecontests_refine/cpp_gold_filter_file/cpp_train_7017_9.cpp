#include <bits/stdc++.h>
using namespace std;
using namespace std;
void solve() {
  long n, m, x, y, z;
  cin >> n >> m;
  vector<long> a[m];
  vector<long> color(n + 1, 0);
  for (long i = 0; i < m; i++) {
    cin >> x >> y >> z;
    a[i].push_back(x);
    a[i].push_back(y);
    a[i].push_back(z);
    long cx, cy, cz;
    if (color[x] != 0) {
      cx = color[x];
      cy = (cx + 1) % 3;
      cz = (cx + 2) % 3;
      if (cy == 0) cy = 3;
      if (cz == 0) cz = 3;
      color[y] = cy;
      color[z] = cz;
    } else if (color[y] != 0) {
      cy = color[y];
      cx = (cy + 1) % 3;
      cz = (cy + 2) % 3;
      if (cz == 0) cz = 3;
      if (cx == 0) cx = 3;
      color[x] = cx;
      color[z] = cz;
    } else if (color[z] != 0) {
      cz = color[z];
      cx = (cz + 1) % 3;
      cy = (cz + 2) % 3;
      if (cx == 0) cx = 3;
      if (cy == 0) cy = 3;
      color[x] = cx;
      color[y] = cy;
    } else {
      color[x] = 1;
      color[y] = 2;
      color[z] = 3;
    }
  }
  bool flag = true;
  for (auto it : color) {
    if (flag)
      flag = false;
    else
      cout << it << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  solve();
}
