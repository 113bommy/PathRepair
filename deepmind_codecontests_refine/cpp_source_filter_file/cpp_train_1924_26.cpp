#include <bits/stdc++.h>
using namespace std;
long long n, m, dap;
int a[7];
void func(int o) {
  if (o == m) {
    for (int i = 1; i <= n; i++) {
      for (int y = i; y <= n; y++) {
        if (a[i] > a[y]) dap++;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      for (int y = i; y <= n; y++) {
        reverse(a + i, a + y + 1);
        func(o + 1);
        reverse(a + i, a + y + 1);
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  func(0);
  double cnt = (double)n * (double)(n - 1) / 2;
  double sum = 1.0;
  for (int i = 0; i < m; i++) sum *= cnt;
  double x = (double)dap;
  printf("%.12lf", x / sum);
}
