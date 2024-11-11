#include <bits/stdc++.h>
using namespace std;
bool check(int x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  int n, m;
  cin >> n >> m;
  int e = m;
  vector<pair<int, int>> g[n + 1];
  int prime = 0;
  for (int i = 1;; i++) {
    if (check(i + n - 1)) {
      prime = i;
      break;
    }
  }
  for (int i = 2; i <= n; i++) {
    g[1].push_back({i, 1});
  }
  if (n != 2) {
    g[1][n - 2].second = 2;
    g[1][0].second = prime;
  } else
    g[1][n - 1].second = 2;
  int mst = n - 1 + prime;
  cout << 2 << " " << mst << endl;
  m = m - (n - 1);
  for (int i = 2; i <= n; i++) {
    for (int j = i + 1; j <= n and m > 0; j++) {
      g[i].push_back({j, prime + 1});
      m--;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      cout << i << " " << g[i][j].first << " " << g[i][j].second << endl;
    }
  }
}
