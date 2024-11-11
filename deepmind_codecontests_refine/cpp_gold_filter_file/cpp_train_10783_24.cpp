#include <bits/stdc++.h>
using namespace std;
int sol(long long a, long long b, long long c) {
  long long t = c * (c - 1) / 2;
  if (a <= b + c + t)
    return 0;
  else
    return 1;
}
int main() {
  long long n, m;
  cin >> n >> m;
  if (n <= m) {
    cout << n;
    return 0;
  }
  long long l = 1, r = 2e9, ans = r;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (sol(n, m, mid)) {
      l = mid + 1;
    } else {
      ans = mid;
      r = mid - 1;
    }
  }
  cout << m + ans;
  return 0;
}
