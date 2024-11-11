#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  string s;
  long long n;
  cin >> n;
  for (long long i = 1; i <= 10000; i++) {
    s += to_string(i);
  }
  cout << s[n - 1] << endl;
}
