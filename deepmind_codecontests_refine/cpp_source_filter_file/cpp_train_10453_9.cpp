#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int l, r, ql, qr;
  cin >> l >> r >> ql >> qr;
  int v[n];
  int ac[n + 1];
  ac[0] = 0;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 1; i < n + 1; i++) {
    ac[i] = ac[i - 1] + v[i - 1];
  }
  long long a, b, cost, ans = 10000000000000009;
  for (int i = 0; i < n; i++) {
    a = i;
    b = n - i;
    cost = ac[i] * l + (ac[n] - ac[i]) * r;
    if (a - b > 1) {
      cost += ql * (a - b - 1);
    }
    if (b - a > 1) {
      cost += qr * (b - a - 1);
    }
    ans = min(ans, cost);
  }
  cout << ans << endl;
}
