#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<bool> b(n), g(m);
  int bb, gg;
  cin >> bb;
  for (int i = 0; i < bb; ++i) {
    int x;
    cin >> x;
    b[x] = true;
  }
  cin >> gg;
  for (int i = 0; i < gg; ++i) {
    int x;
    cin >> x;
    g[x] = true;
  }
  for (int i = 0; i < m * m * n * n; ++i) {
    if (b[i % n] || g[i % m]) {
      b[i % n] = true;
      g[i % m] = true;
    }
  }
  bool c = true;
  for (int i = 0; i < n; ++i)
    if (!b[i]) {
      c = false;
      break;
    }
  for (int i = 0; i < m; ++i)
    if (!g[i]) {
      c = false;
      break;
    }
  if (c)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
