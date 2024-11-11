#include <bits/stdc++.h>
using namespace std;
long long n, red = 0, blue = 0, good = 0;
long long color[300005];
vector<long long> adj[300005];
pair<long long, long long> dfs(long long curr, long long par) {
  pair<long long, long long> curr_cnt = {(color[curr] == 1),
                                         (color[curr] == 2)};
  for (long long child : adj[curr]) {
    if (child == par) continue;
    pair<long long, long long> temp = dfs(child, curr);
    curr_cnt.first += temp.first;
    curr_cnt.second += temp.second;
  }
  if ((curr_cnt.first == red && curr_cnt.second == 0) ||
      (curr_cnt.first == 0 && curr_cnt.second == blue))
    good++;
  return curr_cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> color[i];
    if (color[i] == 1)
      red++;
    else if (color[i] == 2)
      blue++;
  }
  for (long long u, v, i; i < n - 1; i++) {
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }
  dfs(0, -1);
  cout << good;
  return 0;
}
