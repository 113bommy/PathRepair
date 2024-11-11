#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges.push_back(make_pair(a, b));
  }
  if (n < 7) {
    cout << m << endl;
  } else {
    vector<int> ord = {1, 1, 2, 3, 4, 5, 6};
    int res = 0;
    do {
      int cnt = 0;
      bool used[8][8] = {};
      for (auto edge : edges) {
        int o1 = ord[edge.first - 1], o2 = ord[edge.second - 1];
        if (!used[o1][o2]) {
          cnt++;
          used[o1][o2] = true;
          used[o2][o1] = true;
        }
      }
      res = max(res, cnt);
    } while (next_permutation(ord.begin(), ord.end()));
    cout << res << endl;
  }
  return 0;
}
