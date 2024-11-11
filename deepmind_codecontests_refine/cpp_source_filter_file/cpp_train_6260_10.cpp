#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
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
const int maxi = (1 << 21) - 1;
int cnt[2][maxi];
int main() {
  int n;
  cin >> n;
  int a;
  int x = 0;
  cnt[1][0] = 1;
  long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    x = x ^ a;
    ans += cnt[i % 2][x];
    cnt[i % 2][x]++;
  }
  cout << ans;
  return 0;
}
void scan(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
