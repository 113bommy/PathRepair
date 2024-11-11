#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int sum = 0, m = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'b') {
      m++;
      m = m % mod;
    } else {
      sum = ((sum % mod) + (m % mod)) % mod;
      m = ((m % mod) * (2 % mod)) % mod;
    }
  }
  cout << sum << endl;
}
