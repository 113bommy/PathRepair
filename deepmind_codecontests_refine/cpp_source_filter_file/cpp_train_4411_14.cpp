#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50, mod = 1000000007;
int n, m;
vector<int> vect[N];
vector<pair<int, int>> graph[N];
bool vis[N];
int modd(int a, int m) { return ((a % m) + m) % m; }
void min_self(int& a, int b) { a = min(a, b); }
void max_self(int& a, int b) { a = max(a, b); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int x, y, c;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> c;
    graph[x].push_back({y, c});
    graph[y].push_back({x, c});
  }
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    while (x--) {
      cin >> y;
      vect[i].push_back(y);
    }
  }
  priority_queue<pair<long long, int>> pq;
  pq.push({0, 1});
  pair<long long, int> tmp;
  long long ans = -1;
  int node;
  while (pq.size()) {
    tmp = pq.top();
    pq.pop();
    if (tmp.second == n) {
      ans = -tmp.first;
      break;
    }
    if (vis[tmp.second]) continue;
    vis[tmp.second] = true;
    node = tmp.second;
    int ind = lower_bound(vect[node].begin(), vect[node].end(), tmp.first) -
              vect[node].begin();
    while (ind < vect[node].size() && vect[node][ind] == -tmp.first) {
      ++ind;
      --tmp.first;
    }
    for (auto to : graph[node]) {
      pq.push({tmp.first - to.second, to.first});
    }
  }
  cout << ans;
  return 0;
}
