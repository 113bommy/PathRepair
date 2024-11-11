#include <bits/stdc++.h>
using namespace std;
template <typename T>
T qabs(T x) {
  return x < 0 ? -x : x;
}
template <typename T>
T qmin(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
T qmax(T a, T b) {
  return a < b ? b : a;
}
const int maxn = 1e5;
int a[2 * maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; ++i) scanf("%d", a + i);
  sort(a, a + 2 * n);
  long long ans = 1LL * (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  for (int i = 1; i < n; ++i)
    ans = qmin(ans, 1LL * (a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
  printf("%d", ans);
  return 0;
}
