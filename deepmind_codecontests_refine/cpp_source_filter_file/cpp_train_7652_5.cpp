#include <bits/stdc++.h>
using namespace std;
string st = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string num;
int in_base;
string to_base;
inline int findIndex(char cc) {
  for (int i = 0; i < (int)(st).length(); i++) {
    if (cc == st[i]) return i;
  }
  return -1;
}
inline long long pow_(long long x, long long y) {
  long long res = 1LL;
  for (; y;) {
    if (y & 1) {
      res = res * x;
    }
    x = x * x;
    y >>= 1;
  }
  return res;
}
inline long long toDecimal(void) {
  int len = (int)(num).length();
  long long number = 0;
  for (int i = len - 1; i >= 0; i--) {
    number += findIndex(num[i]) * pow_(in_base, (len - (i + 1)));
  }
  return number;
}
inline void convert1(void) {
  string ss = "";
  long long i = toDecimal();
  int j = atoi(to_base.c_str());
  for (; i > 0; i /= j) ss += st[i % j];
  reverse((ss).begin(), (ss).end());
  string rr = "";
  bool flag = true;
  for (int i = 0; i < (int)(ss).length(); ++i) {
    if (flag && ss[i] == '0') continue;
    flag = false;
    rr += ss[i];
  }
  if (rr == "") rr = "0";
  cout << ss << "\n";
  return;
}
const char *Number_AsRomanString(long long iNumber) {
  struct RomanDigit_t {
    char *m_psString;
    long long m_iValue;
  };
  static const RomanDigit_t RomanDigits[] = {
      {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
      {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
      {"V", 5},    {"IV", 4},   {"I", 1},
  };
  static char sRomanString[20];
  sRomanString[0] = '\0';
  for (int i = 0; iNumber && i < sizeof(RomanDigits) / sizeof(RomanDigits[0]);
       i++) {
    while (RomanDigits[i].m_iValue <= iNumber) {
      strcat(sRomanString, RomanDigits[i].m_psString);
      iNumber -= RomanDigits[i].m_iValue;
    }
  }
  return sRomanString;
}
inline void input(void) {
  cin >> in_base;
  cin >> to_base;
  cin >> num;
  if (to_base != "R") {
    convert1();
  } else {
    long long x = toDecimal();
    cout << Number_AsRomanString(x) << "\n";
  }
  return;
}
int main() {
  input();
  return 0;
}
