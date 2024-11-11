#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long n, m, t, k;
long long a[500005];
long long solve(long long a, long long k) {
  long long l = -1, r = a;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (a - 3 * mid * mid - 3 * mid - 1 < k) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return r;
}
bool ty_ans(long long mid) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long u = solve(a[i], mid);
    sum += u;
  }
  return sum >= k;
}
int main() {
  ios::sync_with_stdio(0);
  long long ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> a[i];
  }
  long long l = -2e18 - 5, r = 2e18 + 5;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (ty_ans(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  long long dif = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long x = solve(a[i], l);
    sum += x;
  }
  dif = sum - k;
  for (int i = 0; i < n; i++) {
    long long x = solve(a[i], l);
    long long y = x - 1;
    if (y >= 0) {
      if (a[i] - 3 * y * y - 3 * y - 1 == l) {
        if (dif > 0) {
          dif--;
          x = y;
        }
      }
    }
    cout << x << " ";
  }
  return 0;
}
