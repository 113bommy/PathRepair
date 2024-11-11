#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
string s;
int n;
int main() {
  long long a = 0, b = 0, c = 0, x = 1;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      a++;
    } else if (s[i] == 'b') {
      b += a;
      b %= MOD;
    } else if (s[i] == 'c') {
      c += b;
      c %= MOD;
    } else {
      c = (c * 3 + b) % MOD;
      b = (b * 3 + a) % MOD;
      a = (a * 3 + x) % MOD;
      x = (x * 3) % MOD;
    }
  }
  cout << c;
}
