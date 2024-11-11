#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
long long mulmod(long long a, long long b, long long MOD) {
  if (b == 0) return 0;
  long long res = mulmod(a, b >> 1, MOD);
  res += res;
  res %= MOD;
  return (b & 1) ? (a + res) % MOD : res;
}
int gcd(int a, int b) {
  while (a != 0 && b != 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}
long long gcd(long long a, long long b) {
  while (a != 0 && b != 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}
int main() {
  ios::sync_with_stdio(0);
  char ch[10];
  cin.getline(ch, 10);
  int a = ((ch[0] - '0') * 10 + ch[1] - '0') * 60 +
          ((ch[3] - '0') * 10 + ch[4] - '0');
  a++;
  while (true) {
    if (a == 1440) {
      a = 0;
      break;
    }
    if (((a / 60) / 10) == a % 10 && (a / 60) % 10 == (a % 60) / 10) {
      break;
    }
    a++;
  }
  cout << (a / 60) / 10 << (a / 60) % 10 << ':' << (a % 60) / 10 << a % 10;
  return 0;
}
