#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1003], b[1003];
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((a[i] - b[j]) <= 1 && (a[i] - b[j]) >= -1) {
        cnt++;
        b[j] = -10;
        break;
      }
    }
  }
  printf("%d", cnt);
  return 0;
}
