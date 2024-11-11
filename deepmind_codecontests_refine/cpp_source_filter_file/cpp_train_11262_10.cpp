#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int n, m;
int ind[MAXN];
int outd[MAXN];
long long a, b, c;
long long q;
long long p;
vector<vector<int>> graph(MAXN);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> c >> b;
    if (c > b) {
      graph[b].push_back(c);
      outd[c] += 1;
      ind[b] += 1;
    } else {
      graph[c].push_back(b);
      outd[b] += 1;
      ind[c] += 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    a += 1LL * outd[i] * ind[i];
  }
  cout << a << endl;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> p;
    a -= 1LL * outd[p] * ind[p];
    for (int x = 0; x < graph[p].size(); x++) {
      a -= 1LL * outd[graph[p][x]] * ind[graph[p][x]];
      graph[graph[p][x]].push_back(p);
      ind[graph[p][x]] += 1;
      outd[graph[p][x]] -= 1;
      a += 1LL * outd[graph[p][x]] * ind[graph[p][x]];
    }
    graph[p].clear();
    outd[p] += ind[p];
    ind[p] = 0;
    cout << a << endl;
  }
  return 0;
}
