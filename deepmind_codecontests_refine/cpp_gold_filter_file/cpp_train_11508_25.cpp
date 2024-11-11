#include <bits/stdc++.h>
using namespace std;
int n, d, h;
int main() {
  cin >> n >> d >> h;
  if (2 * h < d) {
    cout << "-1\n";
    return 0;
  }
  int rem = d - h;
  int at = 1;
  int st = 1;
  if (rem == 0) {
    st = 2;
    rem = 1;
    if (h < 2 && n > 2) {
      cout << "-1\n";
      return 0;
    }
  }
  for (int i = 1; i <= h; ++i) cout << i << " " << (i + at) << "\n";
  at += h + 1;
  while (at <= n) {
    cout << st << " " << at << "\n";
    for (int i = 1; at + i <= n && i < rem; ++i)
      cout << at + i - 1 << " " << at + i << "\n";
    at += rem;
  }
  return 0;
}
