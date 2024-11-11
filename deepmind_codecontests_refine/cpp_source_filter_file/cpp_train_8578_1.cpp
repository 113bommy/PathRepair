#include <bits/stdc++.h>
using namespace std;
int n, f[3005][3];
int a[3005], b[3005], c[3005];
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
}
void work() {
  f[1][0] = 0;
  f[1][1] = -0x3f3f3f3f;
  for (int i = 2; i <= n; i++) {
    f[i][0] = max(f[i - 1][1] + a[i - 1], f[i - 1][0] + b[i - 1]);
    f[i][1] = max(f[i - 1][0] + c[i - 1], f[i - 1][1] + b[i - 1]);
  }
  printf("%d\n", max(f[n][0] + a[n], f[n][1] + b[n]));
  return;
}
int main() {
  init();
  work();
  return 0;
}
