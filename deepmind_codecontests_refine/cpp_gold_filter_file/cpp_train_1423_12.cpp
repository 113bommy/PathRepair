#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5) + 5;
const int inf = (int)1e9 + 9;
int n;
int f[N], a[N];
int ans[N];
int has[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    for (int j = 2; j * 1ll * j <= abs(a[i]) * 1ll; ++j) {
      while (a[i] % (j * j) == 0) {
        a[i] /= j * j;
      }
    }
  }
  int sz = 0;
  for (int i = 1; i <= n; ++i) {
    if (!f[i]) {
      f[i] = ++sz;
      for (int j = i; j <= n; ++j) {
        if (a[i] == a[j]) {
          f[j] = f[i];
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = i; j <= n; ++j) {
      if (a[j] != 0 && !has[f[j]]) {
        has[f[j]] = 1;
        ++cnt;
      }
      ans[max(1, cnt)]++;
    }
    for (int j = i; j <= n; ++j) {
      has[f[j]] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}
