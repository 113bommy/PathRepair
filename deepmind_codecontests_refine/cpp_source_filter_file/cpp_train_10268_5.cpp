#include <bits/stdc++.h>
using namespace std;
int a[200200], b[200200], s[200200];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i], &b[i]);
    b[i] += a[i];
  }
  s[1] = b[1];
  for (int i = 2; i <= n; i++) s[i] = min(b[i], b[i - 1] + 1);
  for (int i = n - 1; i >= 1; i--) s[i] = min(s[i], s[i + 1] + 1);
  long long ok = 1, change = 0;
  ;
  for (int i = 1; i <= n; i++) {
    if (a[i] > s[i]) ok = 0;
    change += s[i] - a[i];
  }
  if (ok == 0) {
    printf("-1\n");
    return 0;
  }
  printf("%lld\n", change);
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%d", s[i]);
  }
  printf("\n");
  return 0;
}
