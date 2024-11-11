#include <bits/stdc++.h>
const int N = 110;
using namespace std;
void SOLVE() {
  int ans = 0;
  int n, m, k, x, y;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &x, &y);
    int U = x - 1, D = n - x;
    int L = y - 1, R = m - y;
    if (U <= 4 || L <= 4 || R <= 4 || D <= 4) ans = 1;
  }
  if (ans)
    printf("YES\n");
  else
    printf("NO\n");
}
int main() {
  SOLVE();
  return 0;
}
