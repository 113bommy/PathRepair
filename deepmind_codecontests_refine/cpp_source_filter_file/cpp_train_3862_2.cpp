#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-15;
int toInt(string s) {
  int sm;
  stringstream second(s);
  second >> sm;
  return sm;
}
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
const long long M = 2e5 + 100;
set<long long> v[M];
long long vis[M];
long long d[M];
vector<long long> order;
void dfs(long long s) {
  vis[s] = 1;
  order.push_back(s);
  for (auto child : v[s]) {
    if (!vis[child]) dfs(child);
  }
}
long long dfc(long long s) {
  vis[s] = 1;
  long long ctr = 1;
  for (auto child : v[s]) {
    if (!vis[child]) {
      ctr += dfc(child);
    }
  }
  d[s] = ctr;
}
int main() {
  long long n, q;
  cin >> n >> q;
  for (long long i = 2; i <= n; i++) {
    long long x;
    cin >> x;
    v[x].insert(i);
  }
  dfs(1);
  memset(vis, 0, sizeof(vis));
  dfc(1);
  map<long long, long long> parin;
  for (long long i = 0; i < order.size(); i++) parin[order[i]] = i;
  while (q--) {
    long long u, k;
    cin >> u >> k;
    long long sind = parin[u];
    if (d[u] >= k)
      cout << order[sind + k - 1] << endl;
    else
      cout << "-1\n";
  }
  return 0;
}
