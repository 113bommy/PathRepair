#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double eps = (1e-10);
int isGreater(long double x, long double y) {
  if (abs(x - y) < eps) return 0;
  if (x > y) return 1;
  return -1;
}
int get(int mn, int mx, const vector<int> &b, int st) {
  int l = lower_bound(b.begin() + st + 1, b.end(), mn) - b.begin();
  int r = upper_bound(b.begin() + st + 1, b.end(), mx) - b.begin() - 1;
  return max(0, r - l + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int ans = 0;
  vector<int> b;
  for (int k = 0; k <= 25; ++k) {
    b.resize(n);
    int p = (1 << k);
    for (int i = 0; i < n; ++i) b[i] = a[i] & (2 * p - 1);
    int cnt = 0;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
      cnt += get(p - b[i], 2 * p - 1 - b[i], b, i);
      cnt += get(p + 2 * p - b[i], p * 2 * 2 - 2 - b[i], b, i);
      cnt &= 2;
    }
    if (cnt & 1) ans |= p;
  }
  cout << ans;
  return 0;
}
