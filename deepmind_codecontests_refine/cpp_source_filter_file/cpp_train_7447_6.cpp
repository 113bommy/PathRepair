#include <bits/stdc++.h>
using namespace std;
long long a[101010];
int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  int n;
  cin >> n;
  long long k, h;
  cin >> k >> h;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long v = 0;
  long long u = 0;
  for (int i = 0; i < n; i++) {
    if (h - u < a[i]) {
      long long mi = 0;
      long long ma = 1e9;
      long long f = 1e9;
      while (mi <= ma) {
        long long mid = (mi + ma) / 2;
        if (h - u + mid * k >= a[i]) {
          f = mid;
          ma = mid - 1;
        } else {
          mi = mid + 1;
        }
      }
      v += f;
      u = max(0ll, u - f * k);
    }
    u += a[i];
  }
  long long mi = 0;
  long long ma = 1e9;
  long long f = 1e9;
  while (mi <= ma) {
    long long mid = (mi + ma) / 2;
    if (h - u + mid * k >= h) {
      f = mid;
      ma = mid - 1;
    } else {
      mi = mid + 1;
    }
  }
  v += f;
  cout << v << endl;
}
