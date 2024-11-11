#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, a[300], b[300], q1[300], q2[300];
  scanf("%d%d", &n, &l);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  for (int i = 1; i < n; ++i) q1[i] = a[i + 1] - a[i];
  for (int i = 1; i < n; ++i) q2[i] = b[i + 1] - b[i];
  q1[n] = l - a[n] + a[1];
  q2[n] = l - b[n] + b[1];
  for (int i = n + 1; i <= 2 * n; ++i) {
    q1[i] = q1[i - n];
  }
  for (int i = 1; i <= 2 * n; ++i) {
    bool flag = false;
    for (int j = 1; j <= n; ++j) {
      if (q2[j] != q1[j + i - 1]) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
