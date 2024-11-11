#include <bits/stdc++.h>
using namespace std;
const int MAXN = 131334;
int d[MAXN + 1];
const int INF = 1e9;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  d[0] = -INF;
  for (int i = 1; i <= n; ++i) d[i] = INF;
  for (int i = 0; i < n; i++) {
    int j = int(upper_bound(d, d + n, a[i]) - d);
    if (d[j - 1] < a[i] && a[i] < d[j]) d[j] = a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (d[i] != INF) ans = i;
  cout << ans;
  puts("");
  return 0;
}
