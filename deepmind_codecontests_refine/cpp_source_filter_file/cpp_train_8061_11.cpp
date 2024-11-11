#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    c[i] = a[i];
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
    c[i + n] = b[i];
  }
  sort(c, c + m + n);
  int target = c[m - 1];
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] < target) ans += target - a[i];
  }
  for (int i = 0; i < m; ++i) {
    if (b[i] > target) ans += b[i] - target;
  }
  cout << ans << endl;
  return 0;
}
