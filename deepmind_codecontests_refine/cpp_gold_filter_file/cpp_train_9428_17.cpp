#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 2e5 + 10, wax = 20, inf = 4e18, mod = 1e9 + 7;
const long double pi = 3.14159265359, eps = 1e-9;
long long n;
vector<long long> g[maxn];
long long wis[2][maxn / 2];
long long dis[maxn];
deque<long long> q;
void bfs(long long source) {
  q.push_back(source);
  dis[source] = 0;
  long long v;
  while (((long long)q.size())) {
    v = q.back();
    q.pop_back();
    for (long long u : g[v]) {
      if (dis[u] > dis[v] + 1) {
        dis[u] = dis[v] + 1;
        q.push_front(u);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long v, u;
  for (int i = 0; i < n; i++) {
    g[2 * i].push_back(2 * i + 1), g[2 * i + 1].push_back(2 * i);
    cin >> v >> u;
    v--, u--;
    g[v].push_back(u), g[u].push_back(v);
    wis[0][i] = v, wis[1][i] = u;
  }
  memset(dis, 69, sizeof(dis));
  for (int i = 0; i < 2 * n; i++)
    if (dis[i] >= inf) bfs(i);
  for (int i = 0; i < n; i++)
    cout << dis[wis[0][i]] % 2 + 1 << ' ' << dis[wis[1][i]] % 2 + 1 << endl;
  return 0;
}
