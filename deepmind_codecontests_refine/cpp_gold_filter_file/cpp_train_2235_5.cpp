#include <bits/stdc++.h>
using namespace std;
int getnumber(char c) {
  if (c >= '0' && c <= '9') return (int)c - (int)'0';
  if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
}
char getchr(int i) {
  if (i < 10)
    return i + '0';
  else
    return i - 10 + 'A';
}
int getsys(string s) {
  int max1 = 0;
  for (int i = 0; i < s.length(); i++) {
    max1 = max(max1, getnumber(s[i]) + 1);
  }
  if (max1 < 2) max1 = 2;
  return max1;
}
int fromsto10(string s, int st) {
  int mult = 1;
  int res = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    res += getnumber(s[i]) * mult;
    mult *= st;
  }
  return res;
}
string from10tos(int res, int sys) {
  string result = "";
  while (res > 0) {
    int mod = res % sys;
    result.push_back(getchr(mod));
    res /= sys;
  }
  reverse(result.begin(), result.end());
  return result;
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int syst1 = getsys(s1);
  int syst2 = getsys(s2);
  int sysr = max(syst1, syst2);
  int add1 = fromsto10(s1, sysr);
  int add2 = fromsto10(s2, sysr);
  int sum = add1 + add2;
  string answ = from10tos(sum, sysr);
  printf("%d\n", answ.length());
}
