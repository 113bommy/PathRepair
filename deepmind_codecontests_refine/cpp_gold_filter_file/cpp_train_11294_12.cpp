#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
int n, m, t, j, i, l, h, k, q1, q2, q, a[200500];
void solve() {
  scanf("%d", &n);
  for (j = 1; j <= n; j++) {
    scanf("%d", &a[j]);
    a[j] = a[j] - (n - j);
  }
  sort(a + 1, a + n + 1);
  for (j = 1; j < n; j++) {
    if (a[j] == a[j + 1]) {
      printf(":(\n");
      return;
    }
  }
  for (j = 1; j <= n; j++) {
    printf("%d ", a[j] + (n - j));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(3333);
  solve();
  return 0;
}
