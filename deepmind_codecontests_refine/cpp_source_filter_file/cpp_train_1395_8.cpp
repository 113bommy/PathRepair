#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int pow(long long int a, long long int b) {
  long long int c = mod;
  long long int x = 1, y = a % c;
  while (b > 0) {
    if (b % 2 == 1) x = (x * y) % c;
    y = (y * y) % c;
    b /= 2;
  }
  return x % c;
}
int main() {
  long long int t, k = 0, i, j, c, m, n, h, w;
  string s;
  cin >> s;
  n = 0;
  for (i = s.length() - 1, j = 0; i >= 0; i--, j++)
    if (s[i] == '1')
      k = (2 * k + pow(2LL, 2 * j));
    else
      k = (k * 2) % mod;
  cout << k;
  return 0;
}
