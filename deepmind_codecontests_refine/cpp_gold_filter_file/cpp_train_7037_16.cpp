#include <bits/stdc++.h>
using namespace std;
long long n;
vector<pair<long long, long long> > G[105];
void dfs(int v, int p, double t) {
  t += 1;
  while (t >= 2) t -= 2;
  long long deg = G[v].size();
  for (auto e : G[v]) {
    long long u = e.first, id = e.second;
    if (u == p) continue;
    t += 2.0 / deg;
    while (t >= 2) t -= 2;
    cout << 1 << " " << id << " ";
    if (t <= 1) {
      cout << u << " " << v << " ";
      printf("%.11f\n", 1 - t);
    } else {
      cout << v << " " << u << " ";
      printf("%.11f\n", 2 - t);
    }
    dfs(u, v, t);
  }
}
int main(void) {
  cin >> n;
  long long u, v;
  for (long long(i) = (1); (i) <= (n - 1); (i)++) {
    cin >> u >> v;
    G[u].push_back(pair<long long, long long>(v, i));
    G[v].push_back(pair<long long, long long>(u, i));
  }
  cout << n - 1 << endl;
  dfs(1, -1, 0);
  return 0;
}
