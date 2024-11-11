#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 1000 * 100 + 10;
int64_t a[N], b[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int ans = 0;
  int p1 = 0, p2 = 0;
  int sum1 = 0, sum2 = 0;
  while (p1 < n || p2 < m) {
    if (p2 == m || sum1 <= sum2) {
      sum1 += a[p1++];
    } else {
      sum2 += b[p2++];
    }
    if (sum1 == sum2) {
      ans++;
      sum1 = sum2 = 0;
    }
  }
  if (sum1 != sum2) ans = -1;
  cout << ans << endl;
  return 0;
}
