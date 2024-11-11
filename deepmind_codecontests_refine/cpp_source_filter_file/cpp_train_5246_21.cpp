#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  char s[n + 1];
  for (long long i = (long long)(1); i < (long long)(n + 1); i++) cin >> s[i];
  char curr = '.';
  char last = '.';
  int start = 0;
  int fin = 0;
  int flag = 0;
  for (long long i = (long long)(1); i < (long long)(n + 1); i++) {
    if (s[i] != '.') {
      last = curr;
      curr = s[i];
    }
    if (curr == 'L' && last == 'R') {
      flag = 1;
      fin = i - 1;
      break;
    }
  }
  int flag2 = 0;
  if (flag == 1) {
    for (long long i = (long long)(1); i < (long long)(n + 1); i++) {
      if (s[i] != '.') {
        start = i;
        break;
      }
    }
  } else {
    int check = 0, check0 = 0;
    ;
    for (long long i = (long long)(1); i < (long long)(n + 1); i++) {
      if (s[i] == 'L' && s[i - 1] == '.' && check == 0) {
        fin = i;
        check = 1;
      }
      if (s[i] == '.' && s[i - 1] == 'L' && check0 == 0) {
        start = i - 1;
        check0 = 1;
      }
    }
    int check1 = 0, check2 = 0;
    for (long long i = (long long)(1); i < (long long)(n + 1); i++) {
      if (s[i] == 'R' && s[i + 1] == '.' && check1 == 0) {
        fin = i + 1;
        check = 1;
      }
      if (s[i] == 'R' && s[i - 1] == '.' && check2 == 0) {
        start = i;
        check2 = 1;
      }
    }
  }
  cout << start << " " << fin << '\n';
  return 0;
}
