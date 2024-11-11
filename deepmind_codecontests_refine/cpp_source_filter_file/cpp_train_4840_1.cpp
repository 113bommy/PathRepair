#include <bits/stdc++.h>
using namespace std;
int md = 1e9 + 7;
int a[110][110];
void solve(int n) {
  int i, j, l, q, w, z, x, r, m, k;
  vector<int> ans;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) {
    x = 0;
    for (j = 0; j < n; j++)
      if (a[i][j] == 1 || a[i][j] == 3) x = 1;
    if (x == 0) ans.push_back(i + 1);
  }
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  printf("\n");
}
int main() {
#pragma comment(linker, "/STACK:1073741824")
  int n, m, k, i;
  while (scanf("%d", &n) != EOF) solve(n);
  return 0;
}
