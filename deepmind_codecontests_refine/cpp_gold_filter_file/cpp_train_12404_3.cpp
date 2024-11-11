#include <bits/stdc++.h>
using namespace std;
long long t, a, b, x, y, k, ans, mi = 100000, mx, n, m, r;
map<int, int> us;
int main() {
  cin >> n >> m >> r;
  for (int i = 0; i < n; i++) {
    cin >> a;
    mi = min(mi, a);
  }
  for (int i = 0; i < m; i++) {
    cin >> b;
    mx = max(mx, b);
  }
  cout << max(r, r / mi * mx + r % mi);
}
