#include <bits/stdc++.h>
using namespace std;
vector<int> E[100005];
int cnt[100005], L[100005], n;
void dfs(int x, int h = 0, int p = -1) {
  ++cnt[h];
  for (auto i = E[x].begin(); i != E[x].end(); ++i) {
    if (*i == p) continue;
    dfs(*i, h + 1, x);
  }
}
int main() {
  int M, K, P;
  scanf("%d%d%d", &M, &K, &P);
  for (int i = 1; i < M; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    E[a].push_back(b);
    E[b].push_back(a);
  }
  dfs(1);
  for (int i = 1; i <= M; ++i) {
    for (int j = 0; j < cnt[i]; ++j) L[++n] = i;
  }
  int cost = 0, p = 1, ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i > 1 && L[i] != L[i - 1]) cost += i - p + 1;
    while (cost > P) {
      cost -= L[i] - L[p];
      ++p;
    }
    ans = max(ans, i - p + 1);
  }
  printf("%d\n", min(ans, K));
}
