#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
vector<int> g[N];
int ans[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  bool has_pos = false;
  for (int i = 1; i <= n; ++i) {
    int s, r;
    cin >> s >> r;
    g[s].push_back(r);
    if (r >= 0) has_pos = true;
  }
  if (!has_pos) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < N; ++i) {
    sort(g[i].begin(), g[i].end(), greater<int>());
    for (int j = 0, sum = 0; j < int(g[i].size()); ++j) {
      sum += g[i][j];
      if (sum <= 0) break;
      ans[j + 1] += sum;
    }
  }
  cout << *max_element(ans, ans + N) << endl;
  return 0;
}
