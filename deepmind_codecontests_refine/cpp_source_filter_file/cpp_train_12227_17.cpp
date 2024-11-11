#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int node[510];
vector<pair<int, double> > edge[510];
void addedge(int from, int to, int val) {
  edge[from].push_back(make_pair(to, 1.0 * val));
}
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", node + i);
  }
  for (int i = 0; i < m; i++) {
    int u, v, l;
    scanf("%d %d %d", &u, &v, &l);
    addedge(u, v, l);
  }
  double ans = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < edge[i].size(); j++) {
      ans = max(ans,
                1.0 * (node[i] + node[edge[i][j].first]) / edge[i][j].second);
    }
  }
  printf("%.10f", ans);
}
