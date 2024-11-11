#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using namespace std;
void work() {
  long long a, b, n, m;
  cin >> a >> b >> n >> m;
  if (a + b < n + m) {
    cout << "No"
         << "\n";
    return;
  }
  if (a > b) {
    long long dif = max(a - b, n);
    a -= dif;
    n -= dif;
  } else if (a < b) {
    long long dif = max(b - a, n);
    b -= dif;
    n -= dif;
  }
  long long x = min(n, m);
  a -= x;
  b -= x;
  n -= x;
  m -= x;
  if (a < 0 || b < 0) {
    cout << "No"
         << "\n";
    return;
  }
  if (m == 0) {
    if (a + b < n) {
      cout << "No"
           << "\n";
      return;
    }
  }
  if (n == 0) {
    if (m > min(a, b)) {
      cout << "No"
           << "\n";
      return;
    }
  }
  cout << "Yes"
       << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long caeshi = 1;
  cin >> caeshi;
  for (long long z = 0; z < caeshi; ++z) work();
  return 0;
}
