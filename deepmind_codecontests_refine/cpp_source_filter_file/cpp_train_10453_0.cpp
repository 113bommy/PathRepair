#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r, ql, qr;
  cin >> n >> l >> r >> ql >> qr;
  vector<int> w(n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    p[i + 1] = p[i] + w[i];
  }
  long long ans = 1e16;
  for (int i = 0; i < n; ++i) {
    long long temp = l * p[i] + r * (p[n] - p[i]);
    int left = i, right;
    right = n - left;
    if (left < right)
      temp += qr * max(right - left - 1, 0);
    else
      temp += ql * max(left - right - 1, 0);
    ans = min(ans, temp);
  }
  cout << ans << endl;
  return 0;
}
