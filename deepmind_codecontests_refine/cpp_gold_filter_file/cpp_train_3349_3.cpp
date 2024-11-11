#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int NN = 1000500;
int p[NN];
pii edge[NN];
int deg[NN];
int fl[NN];
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  srand(time(0));
  int n, m;
  cin >> n >> m;
  vector<pii> ans;
  int cnt = (n + m + 1) / 2;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[i] = pii(u, v);
    deg[u]++;
    deg[v]++;
  }
  for (int i = 1; i <= n; i++) {
    deg[i] = (deg[i] + 1) / 2;
  }
  vector<int> p(m);
  for (int i = 0; i < m; i++) p[i] = i;
  shuffle(p.begin(), p.end(), rng);
  shuffle(p.begin(), p.end(), rng);
  for (int i = m; i-- && cnt;) {
    int u = edge[p[i]].first;
    int v = edge[p[i]].second;
    if (deg[u] > 0 && deg[v] > 0) {
      cnt--;
      deg[u]--;
      deg[v]--;
      fl[p[i]] = 1;
      ans.push_back(pii(u, v));
    }
  }
  for (int i = m; i-- && cnt;) {
    int u = edge[p[i]].first;
    int v = edge[p[i]].second;
    if (deg[u] <= 0 && deg[v] <= 0) continue;
    if (fl[p[i]]) continue;
    ans.push_back(pii(u, v));
    deg[u]--;
    deg[v]--;
    cnt--;
  }
  cout << ans.size() << endl;
  for (auto p : ans) printf("%d %d\n", p.first, p.second);
  return 0;
}
