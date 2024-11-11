#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int a[100100], b[100100];
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n;
  m = n / 2 + 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  if (n & 1) {
    cout << "NO\n";
  } else {
    int x = a[1] + a[m];
    int y = b[1] + b[m];
    int f = 1;
    m--;
    for (int i = 2; i <= m; i++) {
      long long xx = a[i] + a[i + m];
      long long yy = b[i] + b[i + m];
      if (xx != x || yy != y) {
        f = 0;
      }
    }
    if (!f)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
