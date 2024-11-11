#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long k;
  cin >> k;
  if (k < 10) {
    cout << k << '\n';
    return 0;
  }
  long long m = 9, d = 1, cnt = 9;
  while (k > cnt) {
    m *= 10;
    d++;
    cnt += (m + d);
  }
  cnt = 0;
  m /= 10;
  long long j = 1;
  for (long long i = 9; i <= m; i *= 10) {
    cnt += (i * j);
    j++;
  }
  long long q = (k - cnt) / d;
  long long r = (k - cnt) % d;
  j--;
  long long x = 0, n;
  while (j > 1) {
    x = (x * 10) + 9;
    j--;
  }
  m += x;
  if (!r) {
    n = m + q;
    cout << n % 10 << '\n';
    return 0;
  }
  n = m + q + 1;
  r = d - r;
  while (r--) n /= 10;
  cout << n % 10 << '\n';
  return 0;
}
