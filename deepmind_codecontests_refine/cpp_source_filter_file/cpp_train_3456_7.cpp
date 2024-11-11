#include <bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 5;
vector<int> g[NR];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &x, &y);
      g[x].push_back(y);
    }
    long long ans = 0;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = n - 1; i >= 0; i--) {
      for (unsigned int j = 0; j < g[i].size(); j++) {
        q.push(g[i][j]);
      }
      while (i > n - (int)q.size()) {
        ans += 1ll * q.top();
        q.pop();
      }
    }
    printf("--%lld\n", ans);
  }
  return 0;
}
