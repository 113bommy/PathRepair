#include <bits/stdc++.h>
using namespace std;
using std::string;
string add(string a, string b) {
  while (a.length() < b.length()) a = "0" + a;
  while (a.length() > b.length()) b = "0" + b;
  string res = "";
  int n = 0, s;
  for (int i = a.length() - 1; i >= 0; i--) {
    s = (a[i] + b[i] - '0' - '0') + n;
    n = s / 10;
    res = (char)(s % 10 + '0') + res;
  }
  if (n != 0) res = "1" + res;
  return res;
}
string sub(string a, string b) {
  while (a.length() < b.length()) a = "0" + a;
  while (a.length() > b.length()) b = "0" + b;
  if (a < b) return "-" + sub(b, a);
  string res = "";
  int n = 0, s;
  for (int i = a.length() - 1; i >= 0; i--) {
    s = (a[i] - b[i] - n);
    if (s < 0) {
      s += 10;
      n = 1;
    } else
      n = 0;
    res = (char)(s + '0') + res;
  }
  return res;
}
string mul(string a, int b) {
  if (b == 0)
    return "0";
  else if (b == 1)
    return a;
  string res = "";
  int n = 0, s;
  for (int i = a.length() - 1; i >= 0; i--) {
    s = (a[i] - '0') * b + n;
    n = s / 10;
    res = (char)(s % 10 + '0') + res;
  }
  if (n > 0) res = (char)(n + '0') + res;
  return res;
}
string mul2(string a, string b) {
  string c = "", t, res = "0";
  if (b.length() > a.length()) {
    c = a;
    a = b;
    b = c;
  }
  for (int i = b.length() - 1; i >= 0; i--) {
    t = mul(a, b[i] - '0');
    res = add(res, t + c);
    c += "0";
  }
  return res;
}
string pow(string a, int b) {
  if (b == 0)
    return "1";
  else if (b == 1)
    return a;
  if (b % 2 == 0)
    return pow(mul2(a, a), b / 2);
  else
    return mul2(pow(mul2(a, a), b / 2), a);
}
string int2str(int a) {
  string sa = "";
  while (a > 0) {
    sa = (char)(a % 10 + '0') + sa;
    a /= 10;
  }
  return sa;
}
int ucln(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return ucln(b, a % b);
}
int sumDigits(int a) {
  int res = 0;
  while (a > 0) {
    res += a % 10;
    a /= 10;
  }
  return res;
}
int main() {
  int n, m, a, r;
  scanf("%d%d%d", &n, &m, &a);
  printf("%d ", a / m);
  r = m - a % m;
  for (int i = 1; i < n; i++) {
    scanf("%d", &a);
    if (a <= r) {
      printf("0 ");
      r -= a;
    } else {
      a -= r;
      printf("%d ", a / m + 1);
      r = m - a % m;
    }
  }
  return 0;
}
