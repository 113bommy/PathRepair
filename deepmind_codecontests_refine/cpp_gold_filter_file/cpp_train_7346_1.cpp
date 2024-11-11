#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[501];
void solve() {
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n' << 1;
    return;
  }
  long long t = n / 2 + 1;
  while (t) {
    long long k = n, i = 1;
    for (i = 1; i <= t; i++) {
      if (i == t) {
        a[i] = k;
        if (k <= a[i - 1]) {
          i--;
          break;
        }
      } else {
        a[i] = i;
        k -= i;
      }
      if (k == 0) break;
    }
    if (i < t) {
      t--;
      continue;
    }
    cout << t << '\n';
    for (long long i = 1; i <= t; i++) cout << a[i] << " ";
    return;
  }
}
int main() {
  solve();
  return 0;
}
