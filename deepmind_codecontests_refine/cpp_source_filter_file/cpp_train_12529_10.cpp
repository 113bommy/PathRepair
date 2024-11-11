#include <bits/stdc++.h>
using namespace std;
int x[101], y[101], z[101];
int n, s = 0;
void dfs(int i) {
  z[i] = 1;
  for (int j = 0; j < n; ++j) {
    if (z[j] != 1 && (x[i] == x[j] || y[i] == y[j])) dfs(j);
  }
}
int main() {
  memset(z, 0, sizeof(z));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
  for (int i = 0; i < n; ++i) {
    if (z[i] != 1) {
      dfs(i);
      s++;
    }
  }
  scanf("%d\n", s - 1);
  return 0;
}
