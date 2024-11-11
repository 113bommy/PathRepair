#include <bits/stdc++.h>
using namespace std;
string bin(string tt, int k) {
  string poch = "";
  string ff = tt;
  while (k > 0) {
    if (k % 2 == 1) poch = poch + ff;
    k = k / 2;
    ff = ff + ff;
  }
  return poch;
}
string f(int a1, int a2, int a3, int a4) {
  string poch = "";
  if (abs(a3 - a4) > 1) return "-1";
  if (a3 > a1 || a3 > a2 || a4 > a1 || a4 > a2) return "-1";
  if (a3 + a4 >= a1 + a2) return "-1";
  int pomoshna = a3;
  poch = poch + bin("47", pomoshna);
  a1 = a1 - a3;
  a2 = a2 - a3;
  a4 = a4 - a3 + 1;
  if (a4 == 0) {
    poch = bin("4", a1) + poch;
    poch = poch + bin("7", a2);
    return poch;
  }
  if (a4 == 1) {
    if (a1 == 0) {
      if (a2 == 0)
        return "-1";
      else {
        poch += "7";
        a2--;
        poch = poch + bin("7", a2);
        return poch;
      }
    }
    poch = poch + bin("7", a2);
    poch = poch + "4";
    a1--;
    poch = bin("4", a1) + poch;
    return poch;
  }
  if (a2 == 0 || a1 == 0) return "-1";
  a1--;
  a2--;
  poch = bin("4", a1) + poch;
  poch = poch + bin("7", a2);
  return "7" + poch + "4";
}
int main() {
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  cout << f(a1, a2, a3, a4);
}
