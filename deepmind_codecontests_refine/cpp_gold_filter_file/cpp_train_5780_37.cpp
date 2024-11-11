#include <bits/stdc++.h>
using namespace std;
struct trio {
  int x, y, z;
};
bool cmp1(trio a, trio b) { return a.x < b.x || a.x == b.x && a.y > b.y; }
bool cmp2(trio a, trio b) { return a.z < b.z; }
int n, m, k1, k2, k3;
set<pair<int, int> > s;
trio a[100002], b[100002];
bool t;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a[i].x >> a[i].y;
    a[i].z = i;
  }
  sort(a, a + m, cmp1);
  k1 = 1;
  k2 = 1;
  k3 = 3;
  for (int i = 0; i < m; ++i) {
    if (a[i].y == 1) {
      b[i].x = k1;
      b[i].y = k1 + 1;
      b[i].z = a[i].z;
      if (++k1 > n) return cout << -1, 0;
    } else {
      if (k3 > k1) return cout << -1, 0;
      b[i].x = k2;
      b[i].y = k3;
      b[i].z = a[i].z;
      if (k3 - ++k2 == 1) {
        ++k3;
        k2 = 1;
      }
    }
  }
  sort(b, b + m, cmp2);
  for (int i = 0; i < m; ++i) {
    cout << b[i].x << ' ' << b[i].y << "\n";
  }
}
