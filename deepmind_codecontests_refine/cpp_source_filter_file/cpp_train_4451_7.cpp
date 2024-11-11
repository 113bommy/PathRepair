#include <bits/stdc++.h>
using namespace std;
long long n, m;
bool check(long long mid) {
  long long x = (1 + mid) * mid / 2;
  if (mid >= m) x = x + (mid - 1 + m) * (mid - m) / 2;
  return (x > n ? 0 : 1);
}
int main() {
  cin >> n >> m;
  long long l = 1, r = 200000000, ans;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  long long x = (1 + ans) * ans / 2;
  if (ans >= m) x = x + (ans - 1 + m) * (ans - m) / 2;
  n -= x;
  long long tot = ans;
  if (ans >= m) tot = tot + ans - m;
  if (n % ans == 0)
    tot += n / ans;
  else
    tot += n / ans + 1;
  cout << tot;
}
