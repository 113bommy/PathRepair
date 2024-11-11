#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int a[MAXN], b[MAXN];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 1) {
    a[0] = 1;
  } else if (n == 2) {
    a[0] = 3;
    a[1] = 4;
  } else if (n & 1) {
    a[0] = 2;
    for (int i = 1; i < n - 1; i++) a[i] = 1;
    a[n - 1] = (n + 1) / 2;
  } else {
    for (int i = 0; i < n - 1; i++) a[i] = 1;
    a[n - 1] = (n - 2) / 2;
  }
  if (m == 1) {
    b[0] = 1;
  } else if (m == 2) {
    b[0] = 3;
    b[1] = 4;
  } else if (m & 1) {
    b[0] = 2;
    for (int i = 1; i < m - 1; i++) b[i] = 1;
    b[m - 1] = (m + 1) / 2;
  } else {
    for (int i = 0; i < m - 1; i++) b[i] = 1;
    a[m - 1] = (m - 2) / 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d ", a[i] * b[j]);
    puts("");
  }
  return 0;
}
