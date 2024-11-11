#include <bits/stdc++.h>
using namespace std;
int strtoint(string a) {
  if (a.length() == 1) return (int(a[0] - '0'));
  return (int(a[0] - '0') * 10 + (int(a[1] - '0')));
}
long long a, b;
string sa, sb, sx;
string s1, s2;
int main() {
  cin >> a;
  cin >> sb;
  cin >> sx;
  long long x = 0;
  long long cur = 1;
  int len = sx.length();
  for (int i = len - 1; i >= 0; i--) {
    int dig;
    if (sx[i] >= '0' && sx[i] <= '9')
      dig = int(sx[i] - '0');
    else
      dig = int(sx[i] - 'A') + 10;
    x += (dig * cur);
    cur *= a;
  }
  string ans = "";
  if (sb == "R") {
    while (x > 1000) {
      ans += 'M';
      x -= 1000;
    }
    if (x >= 900) {
      ans += "CM";
      x -= 900;
    } else if (x >= 800) {
      ans += "DCCC";
      x -= 800;
    } else if (x >= 700) {
      ans += "DCC";
      x -= 700;
    } else if (x >= 600) {
      ans += "DC";
      x -= 600;
    } else if (x >= 500) {
      ans += 'D';
      x -= 500;
    } else if (x >= 400) {
      ans += "CD";
      x -= 400;
    } else if (x >= 300) {
      ans += "CCC";
      x -= 300;
    } else if (x >= 200) {
      ans += "CC";
      x -= 200;
    } else if (x >= 100) {
      ans += 'C';
      x -= 100;
    };
    if (x >= 90) {
      ans += "XC";
      x -= 90;
    } else if (x >= 80) {
      ans += "LXXX";
      x -= 80;
    } else if (x >= 70) {
      ans += "LXX";
      x -= 70;
    } else if (x >= 60) {
      ans += "LX";
      x -= 60;
    } else if (x >= 50) {
      ans += 'L';
      x -= 50;
    } else if (x >= 40) {
      ans += "XL";
      x -= 40;
    } else if (x >= 30) {
      ans += "XXX";
      x -= 30;
    } else if (x >= 20) {
      ans += "XX";
      x -= 20;
    } else if (x >= 10) {
      ans += 'X';
      x -= 10;
    };
    if (x >= 9) {
      ans += "IX";
      x -= 9;
    } else if (x >= 8) {
      ans += "VIII";
      x -= 8;
    } else if (x >= 7) {
      ans += "VII";
      x -= 7;
    } else if (x >= 6) {
      ans += "VI";
      x -= 6;
    } else if (x >= 5) {
      ans += 'V';
      x -= 5;
    } else if (x >= 4) {
      ans += "IV";
      x -= 4;
    } else if (x >= 3) {
      ans += "III";
      x -= 3;
    } else if (x >= 2) {
      ans += "II";
      x -= 2;
    } else if (x >= 1) {
      ans += 'I';
      x -= 1;
    };
    cout << ans;
    return 0;
  }
  b = strtoint(sb);
  if (x == 0) ans = "0";
  while (x > 0) {
    char ch;
    int symb = x % b;
    if (symb < 10) {
      ch = char(symb) + '0';
    } else {
      ch = char(symb - 10) + 'A';
    }
    ans = ch + ans;
    x /= b;
  }
  cout << ans;
  return 0;
}
