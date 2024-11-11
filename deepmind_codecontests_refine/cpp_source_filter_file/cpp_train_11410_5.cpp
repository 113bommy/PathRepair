#include <bits/stdc++.h>
using namespace std;
vector<int> edge[100500];
int beav[100500], root, n;
pair<long long, int> dfs(int v, int prev = 0) {
  int cur = beav[v] - (v != root);
  long long ret = (v != root);
  vector<int> order;
  long long residual = 0;
  for (int &to : edge[v]) {
    if (to == prev) continue;
    pair<long long, int> cur = dfs(to, v);
    order.push_back(cur.first);
    residual += cur.second;
  }
  sort(order.rbegin(), order.rend());
  int limit = min((int)order.size(), cur);
  for (int i = 0; i < limit; i++) {
    ret += order[i] + 1;
    cur--;
  }
  long long val = min(residual, static_cast<long long>(cur));
  cur -= val;
  ret += 2 * val;
  return make_pair(ret, cur);
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> beav[i];
  for (int i = 1; i < n; i++) {
    int from, to;
    cin >> from >> to;
    edge[from].push_back(to);
    edge[to].push_back(from);
  }
  cin >> root;
  cout << dfs(root).first << endl;
  return 0;
}
