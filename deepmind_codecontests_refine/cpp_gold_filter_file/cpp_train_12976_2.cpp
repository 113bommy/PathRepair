#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
int main() {
  string s;
  cin >> s;
  long long ans = s.size() - 1;
  for (int(i) = (s.size() - 1); (i) >= (1); (i)--) {
    if (s[i] == '1') {
      ans += 2;
      while (i--) {
        ans += s[i] == '0';
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
