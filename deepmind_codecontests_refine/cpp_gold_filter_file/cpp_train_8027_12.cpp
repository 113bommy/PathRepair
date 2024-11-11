#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int f[N], a[N];
int sum, n, k, cnt;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
  if (sum % k) {
    cout << "No";
    return 0;
  }
  int tmp = sum / k;
  int res = 0;
  int ok = 0;
  for (int i = 1; i <= n; ++i) {
    res += a[i];
    ++ok;
    if (res == tmp) {
      f[++cnt] = ok;
      res = 0;
      ok = 0;
    }
    if (res > tmp) {
      cout << "No";
      return 0;
    }
  }
  if (res != 0 || cnt < k) {
    cout << "No";
    return 0;
  }
  cout << "Yes\n";
  for (int i = 1; i <= cnt; ++i) cout << f[i] << " ";
}
