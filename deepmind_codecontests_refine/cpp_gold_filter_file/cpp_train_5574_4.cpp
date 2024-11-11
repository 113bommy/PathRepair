#include <bits/stdc++.h>
using namespace std;
int n, m;
int u[100004], v[100004];
int division[100004];
int w33ha() {
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u[i], &v[i]);
    if (u[i] > v[i]) swap(u[i], v[i]);
  }
  if (m == 0) return printf("%d\n", n - 1), 0;
  for (int i = 1; i <= m; i++) {
    if ((division[u[i]] == 0) && (division[v[i]] == 0)) {
      division[u[i]] = 2;
      division[v[i]] = 1;
      continue;
    } else if ((division[u[i]] > 0) && division[v[i]] > 0) {
      if (division[u[i]] == division[v[i]]) return puts("0"), 0;
    }
    if (division[u[i]] == 0) {
      if (division[v[i]] == 1)
        division[u[i]] = 2;
      else
        return puts("0"), 0;
    }
    if (division[v[i]] == 0) {
      if (division[u[i]] == 2)
        division[v[i]] = 1;
      else
        return puts("0"), 0;
    }
  }
  int l2 = 0, l1 = n + 1;
  for (int i = 1; i <= n; i++)
    if (division[i] == 2) l2 = i;
  for (int i = n; i >= 1; i--)
    if (division[i] == 1) l1 = i;
  printf("%d\n", max(l1 - l2, 0));
  return 0;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) w33ha();
  return 0;
}
