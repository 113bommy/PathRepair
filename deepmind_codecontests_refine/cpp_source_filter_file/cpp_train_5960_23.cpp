#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e5 + 5;
vector<int> G[Nmax];
bool vis[Nmax], mar[Nmax];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  while (k--) {
    int first, second, z, t;
    cin >> first >> second >> z >> t;
  }
  string ans;
  for (int i = 1; i < m; ++i) ans.push_back('R');
  for (int i = 1; i < n; ++i) ans.push_back('U');
  bool c = 1;
  for (int i = k; i <= n; ++i) {
    c ^= 1;
    if (!c) {
      for (int j = 1; j < m; ++j) ans.push_back('L');
    } else {
      for (int j = 1; j < m; ++j) ans.push_back('R');
    }
    if (i < n) ans.push_back('D');
  }
  cout << ans.size() << '\n' << ans;
  return 0;
}
