#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cout << v << " ";
    return *this;
  }
} dbg;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int a[111];
int main() {
  int t = 0, z = 0, len;
  int n = 0, k = 0, m = 0;
  int ans = 0;
  ans = INT_MAX;
  scanf("%d %d", &n, &k);
  for (int l = 0; l < n; l++) scanf("%d", &a[l]);
  sort(a, a + n);
  for (int l = 0; l < n; l++) {
    if (!(k % a[l])) ans = min(ans, (k / a[l]));
  }
  printf("%d", ans);
  return 0;
}
