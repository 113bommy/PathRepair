#include <bits/stdc++.h>
using namespace std;
bool isDigit(char c) { return '0' <= c && c <= '9'; }
string s;
long long ans = 0;
int get(string &s) {
  int res = 0;
  int sl = s.length();
  for (int i = 0; i < sl; i++) {
    if (isDigit(s[i])) {
      res *= 10;
      res += s[i] - '0';
    }
  }
  if (s.length() < 3 || s[s.length() - 3] != '.') {
    res *= 100;
  }
  return res;
}
string getAns(long long x) {
  string res = "";
  if (x % 100 != 0) {
    res += x % 10 + '0';
    res += x / 10 % 10 + '0';
    res += '.';
  }
  x /= 100;
  if (x == 0) {
    res += '0';
  }
  int k = 0;
  while (x != 0) {
    if (k > 0 && k % 3 == 0) {
      res += '.';
    }
    res += x % 10 + '0';
    x /= 10;
    k++;
  }
  int sl = res.length();
  for (int i = 0; i < sl / 2; i++) {
    swap(res[i], res[sl - (i + 1)]);
  }
  return res;
}
int main() {
  cin >> s;
  int sl = s.length();
  for (int i = 0; i < sl; i++) {
    if (isDigit(s[i])) {
      int j = i;
      for (j; j < sl && (isDigit(s[j]) || s[j] == '.'); j++) {
        ;
      }
      j--;
      string s0 = s.substr(i, j - i + 1);
      ans += get(s0);
      i = j;
    }
  }
  cout << getAns(ans);
  return 0;
}
