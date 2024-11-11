#include <bits/stdc++.h>
using namespace std;
int N;
int visit[200005];
queue<int> Q;
vector<int> X[200005];
int bfs(int s) {
  for (int i = 1; i <= N; i++) visit[i] = 0;
  Q.push(s);
  int ans = s;
  visit[s] = 1;
  while (!Q.empty()) {
    int q = Q.front();
    Q.pop();
    ans = q;
    for (auto x : X[q])
      if (!visit[x]) {
        visit[x] = 1;
        Q.push(x);
      }
  }
  return ans;
}
void dfs(int s, int par, int t) {
  if (s == t) {
    visit[s] = 1;
    return;
  }
  for (auto x : X[s])
    if (x != par) {
      dfs(x, s, t);
      visit[s] |= visit[x];
    }
}
pair<int, int> solve(int s, int par) {
  pair<int, int> pr = make_pair(1, s);
  for (auto x : X[s])
    if (x != par) {
      pair<int, int> curr = solve(x, s);
      if (curr.first + 1 > pr.first) {
        pr = curr;
        pr.first++;
      }
    }
  return pr;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N - 1; i++) {
    int u, v;
    cin >> u >> v;
    X[u].push_back(v);
    X[v].push_back(u);
  }
  int x1 = bfs(1);
  int x2 = bfs(x1);
  memset(visit, 0, sizeof(visit));
  dfs(x1, 0, x2);
  int ans = 0, curr = 0, x3 = 1;
  while (x3 == x1 || x3 == x2) x3++;
  for (int i = 1; i <= N; i++) {
    if (!visit[i]) continue;
    ans++;
    for (auto x : X[i]) {
      if (visit[x]) continue;
      pair<int, int> pr = solve(x, i);
      if (pr.first >= curr) curr = pr.first, x3 = x;
    }
  }
  cout << ans - 1 + curr << "\n";
  cout << x1 << " " << x2 << " " << x3 << "\n";
  return 0;
}
