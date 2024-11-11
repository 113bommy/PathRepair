#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
int a[110];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i)
      ans += a[i];
    else
      ans -= a[i];
  }
  printf("%d\n", ans);
}
