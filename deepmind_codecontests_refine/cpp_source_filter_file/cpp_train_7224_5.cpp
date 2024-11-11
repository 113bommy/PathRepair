#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  bool row[1001] = {0}, col[1001] = {0};
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    row[a] = 1;
    col[b] = 1;
  }
  int ans = 0;
  for (int i = 2; i <= (n + 1) / 2; i++) {
    if (i == (n + 1) / 2) {
      if (!row[i] || !col[i]) ans++;
      continue;
    }
    if (!row[i]) ans++;
    if (!row[n - i + 1]) ans++;
    if (!col[i]) ans++;
    if (!col[n - i + 1]) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
