#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int x, s;
int a[200010], b[200010], c[200010], d[200010];
int bin_search(int expected, int left, int right) {
  while (left < right) {
    int mid = (left + right) / 2;
    if (d[mid] >= expected) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return max(left - 1, 0);
}
int main() {
  cin >> n >> m >> k;
  cin >> x >> s;
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 1; i <= k; i++) cin >> c[i];
  for (int i = 1; i <= k; i++) cin >> d[i];
  a[m] = x;
  b[m] = 0;
  c[0] = 0;
  d[0] = 0;
  long long ans = 1LL * n * x;
  for (int i = 0; i <= m; i++) {
    if (b[i] > s) continue;
    int pos = bin_search(s - b[i], 0, k + 1);
    ans = min(ans, 1LL * a[i] * (n - c[pos]));
  }
  cout << ans << endl;
  return 0;
}
