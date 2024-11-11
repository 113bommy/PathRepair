#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, m;
  scanf("%d%d", &n, &d);
  int ar[n + 1];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
  }
  scanf("%d", &m);
  int rub = 0;
  if (m > n) {
    rub -= d * (m - n);
    m = n;
  }
  sort(ar + 1, ar + n + 1);
  for (int i = 1; i <= m; i++) {
    rub += ar[i];
  }
  printf("%d", rub);
  return 0;
}
