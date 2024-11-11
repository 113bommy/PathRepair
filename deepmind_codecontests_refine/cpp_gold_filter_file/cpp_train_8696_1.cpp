#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to;
  int c;
  Edge(int to_, int c_) : to(to_), c(c_) {}
};
int N;
vector<int> A;
vector<vector<Edge> > v;
vector<bool> check;
int dfs(int node, int dis) {
  if (check[node]) return 0;
  check[node] = true;
  if (dis > A[node]) return 0;
  int res = 1;
  for (auto &e : v[node]) {
    res += dfs(e.to, max(dis + e.c, 0));
  }
  return res;
}
signed main(void) {
  cin >> N;
  A.resize(N);
  v.resize(N);
  check.resize(N);
  for (auto &a : A) cin >> a;
  for (int i = 1; i < N; ++i) {
    int p, c;
    cin >> p >> c;
    --p;
    v[i].emplace_back(p, c);
    v[p].emplace_back(i, c);
  }
  cout << N - dfs(0, 0) << endl;
  return 0;
}
