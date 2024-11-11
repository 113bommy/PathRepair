#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5;
vector<int> ans, vec[MAX], adj[MAX];
int N, M, X, Y;
int mark[MAX], capital[MAX], not_capital[MAX];
void dfs(int node) {
  mark[node] = 1;
  capital[node] = 1;
  ans.push_back(node);
  for (auto A : adj[node]) {
    if (mark[A]) continue;
    dfs(A);
  }
}
int main() {
  cin >> N >> M;
  for (int A = 1; A <= N; A++) {
    cin >> X;
    while (X--) {
      cin >> Y;
      vec[A].push_back(Y);
    }
  }
  for (int A = 1; A < N; A++) {
    for (int B = 0; B < vec[A].size(); B++) {
      if (B == vec[A + 1].size())
        return cout << "No", 0;
      else if (vec[A][B] < vec[A + 1][B]) {
        adj[vec[A + 1][B]].push_back(vec[A][B]);
        break;
      } else if (vec[A][B] > vec[A + 1][B]) {
        capital[vec[A][B]] = 1;
        not_capital[vec[A + 1][B]] = 1;
        break;
      }
    }
  }
  for (int A = 1; A <= M; A++) {
    if (mark[A] == 0 && capital[A] == 1) dfs(A);
  }
  for (int A = 1; A <= M; A++) {
    if (capital[A] && not_capital[A]) return cout << "No", 0;
  }
  cout << "Yes\n";
  cout << ans.size() << "\n";
  for (auto A : ans) cout << A << " ";
  return 0;
}
