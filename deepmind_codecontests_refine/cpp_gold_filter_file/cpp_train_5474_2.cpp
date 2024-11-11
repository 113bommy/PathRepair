#include <bits/stdc++.h>
using namespace std;
long long i, n, p, q, a, b;
bool check_verybig(long long m) {
  if (m * b - q >= m * a - p && m * a - p >= 0) {
    return true;
  } else
    return false;
}
int main() {
  long long mid, l, r;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> p >> q >> a >> b;
    if (a == b && p != q) {
      cout << -1;
      if (i != n) cout << endl;
      continue;
    }
    if (p > 0 && a == 0) {
      cout << -1;
      if (i != n) cout << endl;
      continue;
    }
    l = 0, r = 1000000000;
    while (l < r) {
      mid = l + (r - l) / 2;
      if (check_verybig(mid) == true)
        r = mid;
      else
        l = mid + 1;
    }
    if (l > 1000000000) {
      cout << -1;
      if (i != n) cout << endl;
    } else {
      cout << l * b - q;
      if (i != n) cout << endl;
    }
  }
}
