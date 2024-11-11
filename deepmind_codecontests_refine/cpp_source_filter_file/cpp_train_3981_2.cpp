#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(nullptr));
long long n, m, sq;
vector<vector<long long> > graph;
vector<long long> used, depth, cur_ans, in_ans, cur_road;
void dfs(long long v, long long d) {
  used[v] = 1;
  depth[v] = d;
  cur_road.push_back(v);
  for (long long to : graph[v]) {
    if (!used[to])
      dfs(to, d + 1);
    else {
      if (d - depth[to] + 1 >= sq) {
        cout << "1\n";
        cout << d - depth[to] + 1 << "\n";
        while (cur_road.back() != to) {
          cout << cur_road.back() + 1 << " ";
          cur_road.pop_back();
        }
        cout << to + 1 << " ";
        exit(0);
      }
    }
  }
  if ((long long)graph[v].size() < sq) {
    bool fl = true;
    for (long long to : graph[v]) {
      if (in_ans[to]) fl = false;
    }
    if (fl) {
      in_ans[v] = 1;
      cur_ans.push_back(v);
    }
  }
  cur_road.pop_back();
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  long long l = 0, r = 1e5;
  while (r - l > 1) {
    long long mid = (r + l) >> 1;
    if (mid * mid >= n)
      r = mid;
    else
      l = mid;
  }
  sq = r;
  used.resize(n);
  depth.resize(n);
  graph.resize(n);
  in_ans.resize(n);
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs(0, 0);
  cout << "2\n";
  for (long long i = 0; i < sq; i++) cout << cur_ans[i] + 1 << " ";
  cout << "\n";
  return 0;
}
