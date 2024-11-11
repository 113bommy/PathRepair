#include <bits/stdc++.h>
using namespace std;
int timer, n;
long long a[200020], H[200020], cost[200020];
int P[200020][20], answer[200020];
vector<int> G[200020];
void bld(int v) {
  H[v] += cost[v];
  for (int i = 1; i < 20; ++i) P[v][i] = P[P[v][i - 1]][i - 1];
  int x = v;
  for (int i = 19; i >= 0; --i) {
    int u = P[x][i];
    if (H[v] - H[u] <= a[v]) x = u;
  }
  answer[P[x][0]]--;
  answer[P[v][0]]++;
  for (int i = 0; i < G[v].size(); ++i) {
    int to = G[v][i];
    if (to == P[v][0]) continue;
    H[to] = H[v];
    bld(to);
    answer[v] += answer[to];
  }
}
int main() {
  scanf("%d", &n);
  H[0] = -2e9;
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  for (int i = 2; i <= n; ++i) {
    scanf("%d %I64d", &P[i][0], &cost[i]);
    G[P[i][0]].push_back(i);
  }
  bld(1);
  for (int i = 1; i <= n; ++i) printf("%d ", answer[i]);
}
