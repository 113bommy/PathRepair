#include <bits/stdc++.h>
using namespace std;
long long a[100100], b[100100], n, m;
long long f(long long x) {
  long long cur = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < x) {
      cur += (x - a[i]);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (b[i] > x) {
      cur += (b[i] - x);
    }
  }
  return cur;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  long long l = 0, r = 1e9 + 1;
  while (r - l > 3) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    if (f(m1) > f(m2)) {
      l = m2;
    } else {
      r = m1;
    }
  }
  cout << min(f(r - 1), min(f(r - 2), f(r)));
}
