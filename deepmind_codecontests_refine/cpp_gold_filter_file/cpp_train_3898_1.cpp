#include <bits/stdc++.h>
using namespace std;
int m, k, p;
int a, b;
int dep[100005];
long long _sum[100005];
long long *sum = _sum + 1;
vector<int> T[100005];
void dfs(int n, int dad = -1, int d = 0) {
  dep[n] = d;
  for (int i = 0; i < T[n].size(); ++i) {
    int c = T[n][i];
    if (c == dad) continue;
    dfs(c, n, d + 1);
  }
}
int main(void) {
  scanf("%d%d%d", &m, &k, &p);
  for (int i = 0; i < m - 1; ++i) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  dfs(0);
  sort(dep, dep + m);
  for (int i = 0; i < m; ++i) sum[i] = sum[i - 1] + dep[i];
  int sol = 0;
  for (int i = 1; i < m; ++i) {
    int lo = 1, hi = min(i, k), mid;
    while (lo < hi) {
      mid = (lo + hi + 1) / 2;
      if ((long long)mid * dep[i] - sum[i] + sum[i - mid] <= p)
        lo = mid;
      else
        hi = mid - 1;
    }
    sol = max(sol, lo);
  }
  printf("%d\n", sol);
  return 0;
}
