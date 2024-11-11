#include <bits/stdc++.h>
using namespace std;
const long long a = 1e9 + 7;
long long power(long long n, long long m, long long p) {
  int res = 1;
  while (m > 0) {
    if (n & 1) {
      res = (res * n) % p;
    }
    n = (n * n) % p;
    m >>= 1;
  }
  return res % p;
}
bool prime(long long b) {
  for (long long i = 2; i <= sqrt(b); i++) {
    if (b % i == 0) return false;
  }
  return true;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long decide = 0, cnt1 = 0, cnt = 0, decide2 = 0, ans = -1;
    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        if (s[i] == '1')
          cnt1++;
        else if (s[i] == '?')
          decide++;
      } else {
        if (s[i] == '1')
          cnt++;
        else if (s[i] == '?')
          decide2++;
      }
      if (cnt1 + decide > cnt + (10 - i) / 2 ||
          cnt + decide2 > cnt1 + (10 - i) / 2) {
        ans = i + 1;
        break;
      }
    }
    if (ans == -1)
      cout << 10 << "\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
