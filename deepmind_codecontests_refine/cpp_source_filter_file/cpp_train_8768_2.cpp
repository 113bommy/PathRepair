#include <bits/stdc++.h>
using namespace std;
vector<int> E[1 << 18];
pair<int, int> R[1 << 18];
int dfs(int a, int p, int d) {
  int cnt = 1;
  for (auto it = (E[a]).begin(); it != (E[a]).end(); ++it) {
    int b = *it;
    if (b == p) continue;
    cnt += dfs(b, a, d + 1);
  }
  R[a] = pair<int, int>(cnt - 1 - d, a);
  return cnt;
}
int main() {
  int n, k;
  cin >> n >> k;
  int i;
  for (i = (1); i < (n); ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  dfs(0, -1, 0);
  sort(R, R + n);
  int res = 0;
  for (i = (k); i < (n); ++i) res += R[i].first;
  cout << res << endl;
  return 0;
}
