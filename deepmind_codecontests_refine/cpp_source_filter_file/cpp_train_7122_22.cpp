#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[1010] = {0};
  int x, y, z;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    a[x] += z;
    a[y] -= z;
  }
  int Ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) Ans += a[i];
  }
  printf("%d\n", Ans);
}
int main(void) {
  Solve();
  return 0;
}
