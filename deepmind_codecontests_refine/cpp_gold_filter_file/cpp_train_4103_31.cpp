#include <bits/stdc++.h>
using namespace std;
int A[1050];
int main() {
  int i, m, n;
  int a, b;
  int total;
  int ans = 0;
  scanf("%d%d%d", &n, &m, &total);
  for (i = 1; i <= m; i++) A[i] = 1000050;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    if (b < A[a]) A[a] = b;
  }
  for (i = 1; i <= m; i++) {
    if (A[i] != 1000050) ans += A[i];
  }
  if (ans > total) ans = total;
  printf("%d", ans);
  return 0;
}
