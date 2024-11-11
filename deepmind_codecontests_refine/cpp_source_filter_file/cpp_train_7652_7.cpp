#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, d;
  char r;
  long k;
  long long n = 0;
  string c, s = "";
  cin >> a >> r;
  if (r != 'R') {
    b = r - '0';
    cin.get(r);
    if (r != '\n') b = b * 10 + r - '0';
  }
  cin >> c;
  {
    k = 1;
    for (int i = c.length() - 1; i >= 0; i--, k *= a) {
      if (c[i] >= '0' && c[i] <= '9')
        n += (c[i] - '0') * k;
      else
        n += k * (c[i] - 'A' + 10);
    }
  }
  if (n == 0) {
    cout << 0;
    return 0;
  }
  if (r != 'R') {
    s = "";
    while (n) {
      int q = n % b;
      n /= b;
      s = char((q < 10) ? (q + '0') : (q - 10 + 'A')) + s;
    }
  } else {
    d = n % 10;
    n = n / 10;
    switch (d) {
      case 0:
        s = "";
        break;
      case 1:
        s = "I";
        break;
      case 2:
        s = "II";
        break;
      case 3:
        s = "III";
        break;
      case 4:
        s = "IV";
        break;
      case 5:
        s = "V";
        break;
      case 6:
        s = "VI";
        break;
      case 7:
        s = "VII";
        break;
      case 8:
        s = "VIII";
        break;
      case 9:
        s = "IX";
        break;
    }
    d = n % 10;
    n = n / 10;
    switch (d) {
      case 0:
        s = "" + s;
        break;
      case 1:
        s = "X" + s;
        break;
      case 2:
        s = "XX" + s;
        break;
      case 3:
        s = "XXX" + s;
        break;
      case 4:
        s = "XL" + s;
        break;
      case 5:
        s = "L" + s;
        break;
      case 6:
        s = "LX" + s;
        break;
      case 7:
        s = "LXX" + s;
        break;
      case 8:
        s = "LXXX" + s;
        break;
      case 9:
        s = "XC" + s;
        break;
    }
    d = n % 10;
    n = n / 10;
    switch (d) {
      case 0:
        s = "" + s;
        break;
      case 1:
        s = "C" + s;
        break;
      case 2:
        s = "CC" + s;
        break;
      case 3:
        s = "CCC" + s;
        break;
      case 4:
        s = "CD" + s;
        break;
      case 5:
        s = "D" + s;
        break;
      case 6:
        s = "DC" + s;
        break;
      case 7:
        s = "DCC" + s;
        break;
      case 8:
        s = "DCCC" + s;
        break;
      case 9:
        s = "CM" + s;
        break;
    }
    d = n % 10;
    switch (d) {
      case 0:
        s = "" + s;
        break;
      case 1:
        s = "M" + s;
        break;
      case 2:
        s = "MM" + s;
        break;
      case 3:
        s = "MMM" + s;
        break;
    }
  }
  cout << s;
  return 0;
}
