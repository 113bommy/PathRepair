#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int> > A;
vector<char> C;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  A.resize(n + 1);
  C.resize(n + 1, false);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    A[x].push_back(y);
    A[y].push_back(x);
  }
  bool ind = true;
  int cnt = 0;
  while (ind) {
    ind = false;
    vector<int> V;
    for (int i = 1; i <= n; i++) {
      if (!C[i]) {
        int cur = 0;
        for (int j = 0; j < A[i].size(); j++) {
          if (!C[A[i][j]]) {
            cur++;
          }
        }
        if (cur < 2) {
          ind = true;
          V.push_back(i);
        }
      }
    }
    if (ind) {
      cnt++;
      while (!V.empty()) {
        C[V.back()] = true;
        V.pop_back();
      }
    }
  }
  cout << cnt;
  return 0;
}
