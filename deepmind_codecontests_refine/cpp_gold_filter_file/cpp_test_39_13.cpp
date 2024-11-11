#include <bits/stdc++.h>
using namespace std;
const long long N = 1000004;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long inf = 1000000000;
long long n, m, k, z, t, ans, x, y, pat, a[N], b[N];
int main() {
  cin >> n;
  a[n - 1] = 1;
  for (int x = 2; x <= n; x++) {
    cout << "? ";
    for (int j = 1; j < n; ++j) cout << 1 << " ";
    cout << x << endl;
    cin >> k;
    if (k == 0) {
      a[n - 1] = n - x + 2;
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (i == a[n - 1]) continue;
    cout << "? ";
    if (i < a[n - 1]) {
      for (int j = 1; j < n; ++j) cout << a[n - 1] - i + 1 << " ";
      cout << 1 << endl;
    } else {
      for (int j = 1; j < n; ++j) cout << 1 << " ";
      cout << i - a[n - 1] + 1 << endl;
    }
    cin >> k;
    a[k - 1] = i;
  }
  cout << "! ";
  for (int i = 0; i < n; ++i) cout << a[i] << " ";
  cout << endl;
  return 0;
}
