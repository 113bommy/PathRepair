#include <bits/stdc++.h>
using namespace std;
string filll(char c, int n) {
  string a;
  int i;
  for (i = 0; i < n; i++) a += c;
  return a;
}
string toRoman(int n) {
  if (n < 4) return filll('I', n);
  if (n < 6) return filll('I', 5 - n) + "V";
  if (n < 9) return string("V") + filll('I', n - 5);
  if (n < 11) return filll('I', 10 - n) + "X";
  if (n < 40) return filll('X', n / 10) + toRoman(n % 10);
  if (n < 60) return filll('X', 5 - n / 10) + 'L' + toRoman(n % 10);
  if (n < 90) return string("L") + filll('X', n / 10 - 5) + toRoman(n % 10);
  if (n < 110) return filll('X', 10 - n / 10) + "C" + toRoman(n % 10);
  if (n < 400) return filll('C', n / 100) + toRoman(n % 100);
  if (n < 600) return filll('C', 5 - n / 100) + 'D' + toRoman(n % 100);
  if (n < 900) return string("D") + filll('C', n / 100 - 5) + toRoman(n % 100);
  if (n < 1100) return filll('C', 10 - n / 100) + "M" + toRoman(n % 100);
  if (n < 4000) return filll('M', n / 1000) + toRoman(n % 1000);
  return "?";
}
string b, c;
long long val(char c) {
  if (isdigit(c)) return c - 48;
  return c - 55;
}
long long convert(string a, long long b) {
  long long sum = 0, i;
  for (i = 0; i < a.size(); i++) {
    sum = sum * b + val(a[i]);
  }
  return sum;
}
char todg(int a) {
  if (a < 10) return a + 48;
  return a + 55;
}
string tobase(long long a, long long b) {
  string res;
  do {
    res += todg(a % b);
    a /= b;
  } while (a);
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  long long cc, a, bb;
  while (cin >> a >> b >> c) {
    cc = convert(c, a);
    if (b == "R") {
      cout << toRoman(cc) << endl;
      ;
    } else {
      sscanf(b.c_str(), "%lld", &bb);
      cout << tobase(cc, bb) << endl;
    }
  }
  return 0;
}
