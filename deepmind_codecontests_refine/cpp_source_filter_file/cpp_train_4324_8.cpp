#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
vector<int> d[N];
vector<pair<int, int>> g[N];
int n, k;
void go(int cur, int u = -1, int par = -1) {
  int day = 0;
  for (auto it : g[cur])
    if (it.first != par) {
      if (day == u) ++day;
      d[day].push_back(it.second);
      if (day > k) k = day;
      go(it.first, day, cur);
      ++day;
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    --y;
    g[x].emplace_back(y, i);
    g[y].emplace_back(x, i);
  }
  go(0);
  printf("%d\n", k);
  for (int i = 0; i <= k; ++i)
    if (d[i].size() > 0) {
      printf("%d", (int)d[i].size());
      for (auto e : d[i]) printf(" %d", e + 1);
      printf("\n");
    }
  return 0;
}
