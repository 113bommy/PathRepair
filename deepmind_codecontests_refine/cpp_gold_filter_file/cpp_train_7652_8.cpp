#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const char c[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int cost[7] = {1, 5, 10, 50, 100, 500, 1000};
string get_rim(int a) {
  string s;
  for (int i = 6; i >= 0;) {
    if (a >= 900 && a < 1000) {
      s += "CM";
      a -= 900;
    }
    if (a >= 400 && a < 500) {
      s += "CD";
      a -= 400;
    }
    if (a >= 90 && a < 100) {
      s += "XC";
      a -= 90;
    }
    if (a >= 40 && a < 50) {
      s += "XL";
      a -= 40;
    }
    if (a == 9) {
      s += "IX";
      a -= 9;
    }
    if (a == 4) {
      s += "IV";
      a -= 4;
    }
    if (a < cost[i])
      i--;
    else {
      a -= cost[i];
      s += c[i];
    }
  }
  return s;
}
int get_n(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  else
    return c - 'A' + 10;
}
char get_c(int a) {
  if (a < 10)
    return char('0' + a);
  else
    return char('A' + a - 10);
}
int main() {
  int a, b = 0;
  char c;
  string s;
  bool q = true;
  scanf("%d %c", &a, &c);
  if (c != 'R') {
    while (int(c) >= '0' && c <= '9') {
      b = b * 10 + int(c) - '0';
      scanf("%c", &c);
    }
    q = false;
  } else
    scanf("\n");
  getline(cin, s);
  long long k = 1;
  long long help = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    help += k * get_n(s[i]);
    k *= a;
    if (k > 1000000000000000ll) break;
  }
  if (q) {
    cout << get_rim(help) << endl;
    return 0;
  }
  string ans;
  if (help == 0) ans += '0';
  while (help != 0) {
    ans += get_c(help % b);
    help /= b;
  }
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
  return 0;
}
