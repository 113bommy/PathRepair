#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
long long sum[100005];
int main(int argc, const char* argv[]) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  memset(sum, 0, sizeof(sum));
  sum[0] = b[0];
  for (int i = 1; i < m; ++i) sum[i] = sum[i - 1] + b[i];
  if (b[0] < a[n - 1]) {
    cout << -1 << endl;
    return 0;
  }
  int pre_pos = m;
  long long ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    int pos = lower_bound(b, b + pre_pos, a[i]) - b;
    if (pre_pos - pos == m && b[pos] != a[i]) ++pos;
    if (pos < pre_pos) {
      ans += pos ? sum[pre_pos - 1] - sum[pos - 1] : sum[pre_pos - 1];
      ans += (m - (pre_pos - pos)) * a[i];
    } else {
      ans += m * a[i];
    }
    pre_pos = pos;
  }
  if (pre_pos == 0)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
