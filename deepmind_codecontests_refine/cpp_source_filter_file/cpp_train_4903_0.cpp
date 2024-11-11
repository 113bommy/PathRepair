#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
int eps = 2000000000;
int inf = -10;
int mark = 0;
vector<vector<int> > A;
vector<int> Mark;
void dfs(int i) {
  Mark[i] = mark;
  for (int j = 0; j < A[i].size(); j++) {
    if (Mark[A[i][j]] == 0) {
      dfs(A[i][j]);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  A.resize(n + m + 1);
  Mark.resize(n + m + 1);
  for (int i = 0; i < q; i++) {
    int first, second;
    cin >> first >> second;
    A[first].push_back(second + n);
    A[second].push_back(first);
  }
  for (int i = 1; i <= n + m; i++) {
    if (Mark[i] == 0) {
      mark++;
      dfs(i);
    }
  }
  cout << mark - 1;
  return 0;
}
