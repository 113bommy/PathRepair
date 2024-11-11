#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 15;
int n, k;
vector<int> g[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0, ggd = n; i < ggd; i++) {
    int x;
    cin >> x;
    for (int j = 0; true; j++) {
      g[x].push_back(j);
      if (!x) break;
      x = x / 2;
    }
  }
  int ans = 1e9;
  for (int i = 0, ggd = N; i < ggd; i++) {
    if (((int)(g[i]).size()) >= k) {
      sort(g[i].begin(), g[i].end());
      int res = 0;
      for (int j = 0, ggd = k; j < ggd; j++) res += g[i][j];
      ans = min(ans, res);
    }
  }
  cout << ans << endl;
}
