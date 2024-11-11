#include <bits/stdc++.h>
using namespace std;
int checkmax(int n) {
  int x = n, m = 0;
  while (x != 0) m = max(m, x % 10), x /= 10;
  return m;
}
string to(int n, int b) {
  string ret;
  int tmp;
  if (n == 0) return "0";
  while (n != 0) {
    tmp = n % 10;
    ret += char(tmp + '0');
    n /= 10;
  }
  return ret;
}
string convert(string a, string b, int base) {
  int i = 0, j = 0, n1, n2, sum, tmp, carry = 0;
  string res;
  while (i < a.length() && j < b.length()) {
    n1 = int(a[i]) - 48;
    n2 = int(b[j]) - 48;
    sum = n1 + n2;
    tmp = (carry + sum) % base;
    res = char(tmp + '0') + res;
    carry = (carry + sum) / base;
    i++, j++;
  }
  while (i < a.length()) {
    n1 = int(a[i]) - 48;
    tmp = (carry + n1) % base;
    res = char(tmp + '0') + res;
    carry = (carry + n1) / base;
    i++;
  }
  while (j < b.length()) {
    n2 = int(b[j]) - 48;
    tmp = (carry + n2) % base;
    res = char(tmp + '0') + res;
    carry = (carry + n2) / base;
    j++;
  }
  if (carry) res = char(carry + '0') + res;
  return res;
}
int main() {
  int a, b, maxx;
  scanf("%d%d", &a, &b);
  maxx = max(checkmax(a), checkmax(b));
  cout << convert(to(a, maxx + 1), to(b, maxx + 1), maxx + 1).length();
}
