#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[120][120];
int t[120], now[120];
int blocked[120];
void pre() {
  for (int i = 0; i <= m; i++) now[i] = 0;
}
void f(int i, int j, int x) {
  if (t[i] || !x) return;
  if (blocked[x]) {
    t[i] = j;
    return;
  }
  now[x]++;
}
void check(int j) {
  for (int i = 1; i <= n; i++) {
    if (!t[i] && now[a[i][j]] > 1) {
      t[i] = j;
      blocked[a[i][j]] = 1;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int j = 1; j <= m; j++) {
    pre();
    for (int i = 1; i <= n; i++) f(i, j, a[i][j]);
    check(j);
  }
  for (int i = 1; i <= n; i++) printf("%d\n", t[i]);
}
