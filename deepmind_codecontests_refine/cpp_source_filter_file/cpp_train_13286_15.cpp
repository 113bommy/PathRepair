#include <bits/stdc++.h>
using namespace std;
const long long a[5] = {0, 0, 1, 2, 9};
long long n, k;
long long C(long long x, long long y) {
  long long t;
  for (long long i = 1; i <= y; i++) t *= n - i + 1;
  for (long long i = 1; i <= y; i++) t /= i;
  return t;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  long long res = 1;
  for (long long i = 2; i <= k; i++) res += C(n, i) * a[i];
  cout << res << '\n';
  return 0;
}
