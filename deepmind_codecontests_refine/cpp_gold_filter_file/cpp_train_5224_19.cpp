#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  long long exp = 10e9;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = ((res % exp) * (a % exp)) % exp;
    a = ((a % exp) * (a % exp)) % exp;
    b >>= 1;
  }
  return res;
}
bool isprime(int x) {
  for (int d = 2; d * d <= x; d++) {
    if (x % d == 0) return false;
  }
  return true;
}
unsigned int cntsb(unsigned int n) {
  unsigned int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
int bin2dec(string n) {
  string num = n;
  int dec_value = 0;
  int base = 1;
  int len = num.length();
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') dec_value += base;
    base = base * 2;
  }
  return dec_value;
}
void solve() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a[10] = {0};
  int len = s.size();
  for (int i = 0; i < len; i++) {
    if (s[i] == 'L') {
      for (int j = 0; j < 10; j++) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    } else if (s[i] == 'R') {
      for (int j = 9; j >= 0; j--) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    } else {
      switch (s[i]) {
        case '0': {
          a[0] = 0;
          break;
        }
        case '1': {
          a[1] = 0;
          break;
        }
        case '2': {
          a[2] = 0;
          break;
        }
        case '3': {
          a[3] = 0;
          break;
        }
        case '4': {
          a[4] = 0;
          break;
        }
        case '5': {
          a[5] = 0;
          break;
        }
        case '6': {
          a[6] = 0;
          break;
        }
        case '7': {
          a[7] = 0;
          break;
        }
        case '8': {
          a[8] = 0;
          break;
        }
        case '9': {
          a[9] = 0;
          break;
        }
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << a[i];
  }
}
