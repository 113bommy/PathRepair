#include <bits/stdc++.h>
using namespace std;
bool is(long long mid, long long m, long long &ans) {
  for (long long i = 2; i * i * i <= mid; i++) {
    long long x = i * i * i;
    ans += mid / x;
  }
  if (ans >= m) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long m;
  cin >> m;
  long long i = 1, j = pow(10, 16);
  long long ans = pow(10, 16);
  long long val = pow(10, 16);
  while (i <= j) {
    long long mid = (i + j) / 2;
    long long x = 0;
    if (is(mid, m, x)) {
      if (x == m) ans = min(ans, mid);
      j = mid - 1;
    } else
      i = mid + 1;
  }
  if (ans == val) ans = -1;
  cout << ans << endl;
  return 0;
}
