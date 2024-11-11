#include <bits/stdc++.h>
using namespace std;
const int mN = 2e5;
int n[mN], N;
vector<int> g[mN];
void dfs(int i, int p) {
  n[i] = n[p] + 1;
  for (int j : g[i])
    if (j != p) dfs(j, i);
}
int main() {
  scanf("%d", &N);
  for (int i = 1, x, y; i < N; ++i) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  double r = 0;
  for (int i = 1; i <= N; ++i) r += 1.0 / n[i];
  printf(".12f", r);
}
