#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000007.;
long long int inf = 1e15;
void scan(int &x);
long long int powermod(long long int _a, long long int _b, long long int _m) {
  long long int _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a) % _m;
    _b /= 2;
    _a = (_a * _a) % _m;
  }
  return _r;
}
long long int string_to_number(string s) {
  long long int x = 0;
  stringstream convert(s);
  convert >> x;
  return x;
}
long long int add(long long int a, long long int b) {
  long long int x = (a + b) % MOD;
  return x;
}
long long int mul(long long int a, long long int b) {
  long long int x = (a * b) % MOD;
  return x;
}
long long int sub(long long int a, long long int b) {
  long long int x = (a - b + MOD) % MOD;
  return x;
}
long long int divi(long long int a, long long int b) {
  long long int x = a;
  long long int y = powermod(b, MOD - 2, MOD);
  long long int res = (x * y) % MOD;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string str;
  cin >> str;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      cnt++;
    } else {
      if (str[i] == 'R') {
        if (str[i + 1] == 'U') {
          i++;
        }
      }
      if (str[i] == 'U') {
        if (str[i + 1] == 'R') {
          i++;
        }
      }
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
