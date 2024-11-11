#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> A;
vector<int> vis;
long long k = 1;
void dfs(int a) {
  vis[a] = 1;
  for (int i : A[a]) {
    if (vis[i] == 0) {
      k *= 2;
      dfs(i);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  A.resize(n + 1);
  vector<int> B;
  vis.assign(n + 1, 0);
  for (long long i = (0); i < (m); i++) {
    int a, b;
    cin >> a >> b;
    A[a].push_back(b);
    A[b].push_back(a);
    B.push_back(a);
  }
  for (long long i = (0); i < (m); i++) {
    if (vis[B[i]] == 0) {
      dfs(B[i]);
    }
  }
  cout << k;
}
