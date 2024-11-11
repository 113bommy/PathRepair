#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long n, k;
long long a[100005], b[100005];
bool check(long long x) {
  long long sum = 0;
  for (int i = 1; i < n + 1; i++) {
    int l = 0, r = a[i] + 1;
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      if (a[i] - 3ll * mid * (mid - 1) - 1 >= x) {
        l = mid;
      } else {
        r = mid;
      }
    }
    b[i] = l;
    sum += b[i];
  }
  return sum >= k;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  long long l = -8e18, r = 1e9;
  while (r - l > 1) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  check(l);
  long long sum = 0, rem = 0;
  for (int i = 1; i < n + 1; i++) {
    sum += b[i];
  }
  rem = sum - k;
  for (int i = 1; i < n + 1; i++) {
    if (rem && a[i] - 3ll * b[i] * (b[i] - 1) - 1 == l) {
      rem--, b[i]--;
    }
  }
  for (int i = 1; i < n + 1; i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}
