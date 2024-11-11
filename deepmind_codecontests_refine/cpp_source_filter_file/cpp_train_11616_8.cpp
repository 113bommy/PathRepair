#include <bits/stdc++.h>
using namespace std;
const int maxn = 200009;
const long long int ninf = -1e17;
int n, dfstime[maxn], until[maxn], weight[maxn];
long long int sumweight[maxn], st[maxn];
vector<vector<int> > g;
void fillsumw(int u, int par, int& curtime) {
  sumweight[u] = weight[u];
  dfstime[u] = curtime;
  ++curtime;
  for (int adj : g[u]) {
    if (adj == par) continue;
    fillsumw(adj, u, curtime);
    sumweight[u] += sumweight[adj];
  }
  until[u] = curtime;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  scanf("%d", &n);
  g = vector<vector<int> >(n, vector<int>());
  for (int i = 0; i < n; ++i) scanf("%d", &weight[i]);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int curtime = 0;
  fillsumw(0, -1, curtime);
  for (int i = 0; i < n; ++i) {
    st[dfstime[i]] = sumweight[i];
  }
  for (int i = n - 2; i > 0; --i) st[i] = max(sumweight[i], st[i + 1]);
  long long int ans = ninf;
  for (int i = 0; i < n; ++i) {
    int start = until[i];
    if (start >= n) continue;
    ans = max(ans, sumweight[i] + st[start]);
  }
  if (ans == ninf) {
    cout << "Impossible" << endl;
  } else {
    cout << ans << endl;
  }
}
