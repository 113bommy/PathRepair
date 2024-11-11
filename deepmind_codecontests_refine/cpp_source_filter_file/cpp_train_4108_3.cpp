#include <bits/stdc++.h>
using namespace std;
int n;
long long a[123456], f[123456], ans, tmp;
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &tmp);
    a[tmp]++;
  }
}
void solve() {
  f[1] = a[1];
  ans = f[1];
  for (int i = 2; i <= 123456; i++) {
    f[i] = max(f[i - 1], f[i - 2] + a[i] * i);
    ans = max(f[i], ans);
  }
  printf("%I64d\n", ans);
}
int main() {
  init();
  solve();
}
