#include <bits/stdc++.h>
using namespace std;
const long double epsilon = 1e-9;
const long long MOD = 1e9 + 7;
bool comp(long long a, long long b) { return (a > b); }
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
bool isSPalin(string s) {
  long long i = 0, j = s.length() - 1;
  bool flag = 1;
  while (i <= j) {
    if (s[i] == 'b') {
      if (s[j] != 'd') {
        flag = 0;
        break;
      }
    } else if (s[i] == 'd') {
      if (s[j] != 'b') {
        flag = 0;
        break;
      }
    } else if (s[i] == 'p') {
      if (s[j] != 'q') {
        flag = 0;
        break;
      }
    } else if (s[i] == 'q') {
      if (s[j] != 'p') {
        flag = 0;
        break;
      }
    } else if (s[i] == 'A' || s[i] == 'H' || s[i] == 'I' || s[i] == 'M' ||
               s[i] == 'O' || s[i] == 'T' || s[i] == 'U' || s[i] == 'V' ||
               s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'o' ||
               s[i] == 'v' || s[i] == 'w' || s[i] == 'x') {
      if (s[j] != s[i]) {
        flag = 0;
        break;
      }
    } else {
      flag = 0;
      break;
    }
    i++;
    j--;
  }
  return flag;
}
void runcase() {
  string s;
  cin >> s;
  if (isSPalin(s))
    cout << "TAK\n";
  else
    cout << "NIE\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  long long tests = 1;
  while (tests--) {
    runcase();
  }
  return 0;
}
