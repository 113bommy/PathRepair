#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const long long Mod = 1000000007;
long long a[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    for (int i = 0; i < n; i++) cout << i * 2 + 1 << ' ';
    cout << endl;
    return 0;
  }
  if (n < 3) {
    cout << -1 << endl;
    return 0;
  }
  int d = n - 2;
  int s = (1 + d / 2) * d / 2;
  if (d % 2) s += d / 2 + 1;
  if (s < m) {
    cout << -1 << endl;
    return 0;
  }
  a[1] = 1;
  a[2] = 2;
  s = 0;
  int p = 999999;
  for (int i = 3; i <= n; i++) {
    d = (i - 1) / 2;
    if ((s + d) > m) {
      a[i] = i + ((s + d) - m) * 2;
      p = i + 1;
      break;
    }
    s += d;
    a[i] = i;
  }
  int dd = 150001;
  for (int i = p; i <= n; i++) {
    a[i] = dd;
    dd += 10001;
  }
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
  cout << endl;
  return 0;
}
