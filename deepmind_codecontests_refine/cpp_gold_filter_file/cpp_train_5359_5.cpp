#include <bits/stdc++.h>
using namespace std;
int n, m, b, g, tmp, i, indexb, indexg, nochanges;
bool boys[105], girls[105], s;
bool Solve() {
  bool f1 = 1, f2 = 1;
  i = 0;
  while (1) {
    indexb = i % n;
    indexg = i % m;
    if (boys[indexb] == girls[indexg]) nochanges++;
    if (boys[indexb] || girls[indexg]) {
      boys[indexb] = 1;
      girls[indexg] = 1;
    }
    if (nochanges > max(n, m) * max(n + 1, m + 1)) break;
    i++;
  }
  for (int i = 0; i < n; i++) {
    if (!boys[i]) {
      f1 = 0;
      break;
    }
  }
  for (int i = 0; i < m; i++) {
    if (!girls[i]) {
      f2 = 0;
      break;
    }
  }
  return f1 && f2;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d", &b);
  for (int i = 0; i < b; i++) {
    scanf("%d", &tmp);
    boys[tmp] = 1;
  }
  scanf("%d", &g);
  for (int i = 0; i < g; i++) {
    scanf("%d", &tmp);
    girls[tmp] = 1;
  }
  s = Solve();
  if (s)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
