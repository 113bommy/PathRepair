#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005], b[100005];
long long k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long l = -1e18, r = 1e18;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    long long Move = 0;
    for (int i = 1; i <= n; i++) {
      long long ll = 0, rr = a[i];
      while (ll < rr) {
        long long midd = (ll + rr + 1) >> 1;
        if (mid > a[i] - 3 * midd * midd + 3 * midd - 1) {
          rr = midd - 1;
        } else {
          ll = midd;
        }
      }
      Move += ll;
    }
    if (Move < k) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  for (int i = 1; i <= n; i++) {
    long long ll = 0, rr = a[i];
    while (ll < rr) {
      long long midd = (ll + rr + 1) >> 1;
      if (l > a[i] - 3 * midd * midd + 3 * midd - 1) {
        rr = midd - 1;
      } else {
        ll = midd;
      }
    }
    b[i] = ll;
    k -= ll;
  }
  for (int i = 1; i <= n; i++) {
    while (k < 0 && b[i] > 0 && a[i] - 3 * b[i] * b[i] + 3 * b[i] - 1 == l) {
      --b[i];
      ++k;
    }
    cout << b[i] << ' ';
  }
}
