#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<bool> b(n, 0);
  vector<bool> g(m, 0);
  int x, y;
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> y;
    b[y] = 1;
  }
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> y;
    g[y] = 1;
  }
  for (int i = 0; i < n * m * m * n; i++) {
    int bi = i % n;
    int gi = i % m;
    b[bi] = b[bi] | g[gi];
    g[gi] = g[gi] | b[bi];
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == 0) {
      cout << "No";
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (g[i] == 0) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
