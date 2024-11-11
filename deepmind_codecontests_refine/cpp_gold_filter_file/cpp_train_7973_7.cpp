#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int M = 1e6;
const double eps = 1e-9;
const double PI(acos(-1.0));
int q;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  for (int i = 0; i < (q); i++) {
    long long n, ans = 0;
    cin >> n;
    long long l = 1, r = n - 1, k;
    while (l <= r) {
      k = l + r >> 1;
      long long tmp = k * (k - 1) / 2;
      if (tmp < n - k) {
        ans = max(ans, tmp + n - k);
        l = k + 1;
      } else {
        ans = max(ans, n - k + n - k);
        r = k - 1;
      }
    }
    cout << ans << endl;
  }
}
