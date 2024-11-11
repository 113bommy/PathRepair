#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= mod) a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= mod) res %= mod;
    a = a * a;
    if (a >= mod) a %= mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, c, d, num0, num1;
  cin >> a >> b >> c >> d;
  int flag = 0;
  long long i, j;
  for (i = 0; i <= 1000000; i++) {
    long long temp = (i * (i - 1)) / 2;
    if (temp > a) {
      flag = 1;
      break;
    }
    if (temp == a) {
      num0 = i;
      break;
    }
  }
  for (i = 0; i <= 1000000; i++) {
    long long temp = (i * (i - 1)) / 2;
    if (temp > d) {
      flag = 1;
      break;
    }
    if (temp == d) {
      num1 = i;
      break;
    }
  }
  if (flag == 1) {
    cout << "Impossible";
    return 0;
  } else if (a + b + c + d == 0) {
    cout << "0";
  } else if (a == 0 && b == 0 && c == 0) {
    for (i = 0; i < num1; i++) cout << "1";
  } else if (b == 0 && c == 0 && d == 0) {
    for (i = 0; i < num0; i++) cout << "0";
  } else {
    long long num0110 = num0 * num1;
    if (b + c != num0110) {
      cout << "Impossible";
      return 0;
    }
    long long end = c / num0;
    long long rem = c % num0;
    long long last = num1 - end - 1;
    if (rem == 0) last++;
    for (i = 0; i < end; i++) cout << "1";
    for (i = 0; i < num0 - rem; i++) cout << "0";
    if (rem != 0) cout << "1";
    for (i = num0 - rem; i < num0; i++) cout << "0";
    for (i = 0; i < last; i++) cout << "1";
  }
}
