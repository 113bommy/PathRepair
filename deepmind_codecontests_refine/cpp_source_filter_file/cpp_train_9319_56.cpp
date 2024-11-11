#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  long long x, y, res = 0;
  for (int i = 0; i < n - 1; ++i) {
    x = a[i];
    y = b[i];
    for (int j = i + 1; j < n; ++j) {
      x |= a[j];
      y |= b[j];
      if (x + y > res) res = x + y;
    }
  }
  cout << res << endl;
}
