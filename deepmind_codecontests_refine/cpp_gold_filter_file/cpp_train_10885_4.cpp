#include <bits/stdc++.h>
using namespace std;
string s;
long long dolars = 0, cents = 0, i;
void count() {
  int dots = 0, j, l;
  for (j = i; j < s.length(); ++j) {
    if ((s[j] < '0' || s[j] > '9') && (s[j] != '.')) break;
    if (s[j] == '.') ++dots;
  }
  l = j;
  if (dots == 0) {
    long long res = 0;
    for (j = i; j < l; ++j) {
      res *= 10;
      res += s[j] - '0';
    }
    dolars += res;
  } else {
    if (s[l - 3] != '.') {
      long long res = 0;
      for (j = i; j < l; ++j) {
        if (s[j] != '.') {
          res *= 10;
          res += s[j] - '0';
        }
      }
      dolars += res;
    } else {
      long long res = 0;
      for (j = i; j < l - 3; ++j) {
        if (s[j] != '.') {
          res *= 10;
          res += s[j] - '0';
        }
      }
      dolars += res;
      res = 0;
      for (j = l - 2; j < l; ++j) {
        res *= 10;
        res += s[j] - '0';
      }
      cents += res;
    }
  }
  i = l;
}
int main() {
  getline(cin, s);
  for (i = 0; i < s.length(); ++i) {
    if (s[i] >= '0' && s[i] <= '9') count();
  }
  s = "";
  dolars += cents / 100;
  if (dolars != 0) {
    while (dolars != 0) {
      s.insert(0, 1, (dolars % 10) + '0');
      dolars /= 10;
    }
    for (i = s.length() - 1; i > 0; --i) {
      ++dolars;
      if (dolars % 3 == 0) {
        s.insert(i, 1, '.');
        continue;
      }
    }
  } else
    s = "0";
  for (i = 0; i < s.length(); ++i) printf("%c", s[i]);
  if (cents % 100 != 0)
    printf(".%I64d%I64d ", (cents % 100) / 10, (cents % 100) % 10);
  return 0;
}
