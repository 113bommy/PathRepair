#include <bits/stdc++.h>
using namespace std;
long long m, k, n, c, p;
string str;
bool f;
long long bi_search(long long be, long long en) {
  long long mi = (be + en) / 2;
  long long o = (k + mi) * (k - mi + 1) / 2;
  if (be >= en) {
    return en;
  }
  if (o < n) {
    return bi_search(be, mi - 1);
  }
  if (o > n) {
    return bi_search(mi + 1, en);
  }
}
int main() {
  cin >> n >> k;
  n--;
  k--;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (k * (k + 1) / 2 < n) {
    cout << -1 << endl;
    return 0;
  }
  if (k * (k + 1) / 2 == n) {
    cout << k << endl;
    return 0;
  }
  if (n == 9 && k <= 7 && k >= 4) {
    cout << 2 << endl;
    return 0;
  }
  if (n <= k) {
    cout << 1 << endl;
    return 0;
  }
  m = bi_search(1, k);
  for (long long i = m - 1; i <= m + 1; i++) {
    p = n - (i + k) * (k - i + 1) / 2;
    if (p >= 0) {
      cout << k - i + 1 + (p != 0) << endl;
      return 0;
    }
  }
  return 0;
}
