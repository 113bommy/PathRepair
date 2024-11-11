#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r, p, q, w[100000], ans = 500000000000000, sum = 0, sub = 0;
  cin >> n >> l >> r >> p >> q;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    sum += w[i];
  }
  for (int i = 0; i <= n; i++) {
    int ret = sum * r + sub * l;
    if (i <= n - i) {
      ret += max(0, n - i - i - 1) * q;
    } else {
      ret += max(0, i - n + i - 1) * p;
    }
    if (ret < ans) ans = ret;
    if (i != n) {
      sum -= w[i];
      sub += w[i];
    }
  }
  cout << ans << endl;
}
