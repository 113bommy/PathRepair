#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) { return (a) ? GCD(b % a, a) : b; }
long long LCM(long long a, long long b) { return a * b / GCD(a, b); }
long long fastpow(long long b, long long p) {
  if (!p) return 1;
  long long ret = fastpow(b, p >> 1);
  ret *= ret;
  if (p & 1) ret *= b;
  return ret;
}
string alpha = "abcdefghijklmnopqrstuvwxyz";
int divisor(int number) {
  int i;
  for (i = 2; i <= sqrt(number); i++) {
    if (number % i == 0) {
      return number / i;
    }
  }
  return 1;
}
int myXOR(int x, int y) {
  int res = 0;
  for (int i = 31; i >= 0; i--) {
    bool b1 = x & (1 << i);
    bool b2 = y & (1 << i);
    bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);
    res <<= 1;
    res |= xoredBit;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  bool firstOne = 0, zero = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (vec[i] && !firstOne) {
      firstOne = 1;
      c++;
    } else if (firstOne && vec[i]) {
      c++;
      zero = 0;
    } else if (firstOne && !zero) {
      zero = 1;
      c++;
    }
  }
  if (!vec[vec.size() - 1]) c--;
  cout << c;
}
