#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long a[N], p[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = p[i - 1] + a[i];
  }
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    long long x = p[n] - p[i - 1];
    int lo = 0, hi = n + 1;
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (p[mid] <= x) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    if (p[lo] == x && lo < i) {
      ans = x;
    }
  }
  cout << ans;
  return 0;
}
