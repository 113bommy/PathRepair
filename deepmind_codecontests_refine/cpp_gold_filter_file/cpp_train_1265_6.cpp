#include <bits/stdc++.h>
using namespace std;
long long n, k, len;
signed main() {
  cin >> n >> k;
  if (n == k) {
    for (long long i = 1; i <= n; i++) cout << '0';
    return puts(""), 0;
  }
  len = (n - k) / 2;
  long long p = 0;
  for (p = len + 1; p <= n; p += len + 1) {
    for (long long i = 1; i <= len; i++) cout << '0';
    cout << '1';
  }
  p -= len + 1;
  for (long long i = p + 1; i <= n; i++) cout << '0';
  return puts(""), 0;
}
