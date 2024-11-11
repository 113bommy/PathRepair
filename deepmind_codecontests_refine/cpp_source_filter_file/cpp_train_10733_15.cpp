#include <bits/stdc++.h>
using namespace std;
vector<long long> adjlist[1005];
long long vis[1005], nearest;
map<long long, long long> m1, m2;
void dfs(long long node) {
  vis[node] = 1;
  for (auto i : adjlist[node]) {
    if (vis[i] == 2) {
      nearest = i;
      return;
    } else if (!vis[i]) {
      dfs(i);
    }
  }
}
void clall() {
  for (long long i = 0; i < 1005; ++i) adjlist[i].clear();
  memset(vis, 0, sizeof vis);
  m1.clear();
  m2.clear();
}
void aska(long long node) {
  cout << "A " << node << '\n';
  fflush(stdout);
}
void askb(long long node) {
  cout << "B " << node << '\n';
  fflush(stdout);
}
void answer(long long node) {
  cout << "C " << node << '\n';
  fflush(stdout);
}
void solve() {
  clall();
  nearest = -1;
  long long n;
  cin >> n;
  for (long long i = 0; i < n - 1; ++i) {
    long long x, y;
    cin >> x >> y;
    adjlist[x].push_back(y);
    adjlist[y].push_back(x);
  }
  long long k1, k2;
  cin >> k1;
  for (long long i = 0; i < k1; ++i) {
    long long node;
    cin >> node;
    vis[node] = 2;
    m1[node]++;
  }
  cin >> k2;
  for (long long i = 0; i < k2; ++i) {
    long long node;
    cin >> node;
    m2[node]++;
  }
  askb(m2.begin()->first);
  long long resp;
  cin >> resp;
  if (m1[resp]) {
    answer(resp);
    return;
  }
  dfs(resp);
  aska(nearest);
  cin >> resp;
  if (m2[resp])
    answer(resp);
  else
    answer(-1);
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
