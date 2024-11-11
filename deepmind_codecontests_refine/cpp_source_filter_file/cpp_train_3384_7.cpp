#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int a[N], b[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  b[1] = a[1];
  b[n] = a[n];
  int ans = 0;
  for (int i = 2; i < n; ++i) {
    if (a[i - 1] != a[i] && a[i + 1] != a[i]) {
      int j = i, cnt = 0;
      while (a[j - 1] != a[j] && a[j + 1] != a[j] && j < n) {
        ++j;
        ++cnt;
      }
      if (cnt & 1) {
        for (int k = i; k <= j; ++k) b[k] = a[i - 1];
        ans = max(ans, cnt / 2 + 1);
      } else {
        int foo = cnt / 2;
        for (int k = i; k < i + foo; ++k) b[k] = a[i];
        for (int k = i + foo; k <= j; ++k) b[k] = a[j];
        ans = max(ans, foo);
      }
      i = j;
    } else
      b[i] = a[i];
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) printf("%d%c", b[i], " \n"[i == n]);
  return 0;
}
