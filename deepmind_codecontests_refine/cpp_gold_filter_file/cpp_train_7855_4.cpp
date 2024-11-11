#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= M;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % M;
    a = a * a % M;
  }
  return res % M;
}
int main() {
  string s;
  cin >> s;
  string sss = s;
  reverse(sss.begin(), sss.end());
  if (sss == s) {
    if (s.size() % 2 == 0) {
      for (int i = 0; i < s.size() / 2; ++i) {
        printf("%c", s[i]);
      }
      printf("a");
      for (int i = s.size() / 2; i < s.size(); ++i) printf("%c", s[i]);
    } else {
      int i;
      for (i = 0; i < s.size() / 2; ++i) {
        printf("%c", s[i]);
      }
      printf("%c", s[i]);
      printf("%c", s[i]);
      for (int i = s.size() / 2 + 1; i < s.size(); ++i) printf("%c", s[i]);
    }
  } else {
    int s1 = s.size();
    string ss;
    int i;
    for (i = 0; i < s1 / 2; ++i) {
      if (s[i] != s[s1 - i - 1]) {
        ss += s[i];
        break;
      }
    }
    string x;
    for (int j = 0; j <= s1 - i - 1; ++j) x += s[j];
    x += s[i];
    for (int j = s1 - i; j < s.size(); ++j) x += s[j];
    string y;
    for (int j = 0; j < i; ++j) y += s[j];
    y += s[s1 - i - 1];
    for (int j = i; j < s.size(); ++j) y += s[j];
    string xx = x, yy = y;
    reverse(xx.begin(), xx.end());
    reverse(yy.begin(), yy.end());
    if (xx == x) {
      cout << x << endl;
    } else if (yy == y) {
      cout << y << endl;
    } else
      puts("NA");
  }
  return 0;
}
