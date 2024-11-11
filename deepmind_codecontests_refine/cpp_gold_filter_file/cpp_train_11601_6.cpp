#include <bits/stdc++.h>
using namespace std;
void path(array<int, 2> &p) {
  array<int, 2> curr = {0, 0};
  while (true) {
    cout << "(" << curr[0] + 1 << "," << curr[1] + 1 << ") ";
    if (curr == p) break;
    if (curr[1] < p[1])
      curr[1]++;
    else
      curr[0]++;
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<array<int, 2>> nodes(k);
  vector<vector<array<int, 2>>> diag(n + m);
  for (int i = 0; i < (int)n; i++)
    for (int j = 0; j < (int)m; j++) diag[i + j].push_back({i, j});
  int ans = 0;
  for (int s = 0; s < (int)n + m; s++) {
    for (auto &i : diag[s]) {
      if (!k) break;
      ans += s + 1;
      k--;
      nodes[k] = i;
    }
  }
  cout << ans << '\n';
  for (auto &i : nodes) path(i);
}
