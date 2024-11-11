#include <bits/stdc++.h>
using namespace std;
void r1() {
  printf("-1");
  return;
}
void r2(string rr) {
  printf("%s\n", rr.c_str());
  return;
}
int main() {
  string ret;
  int i;
  int a1, a2, a3, a4;
  scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
  if (abs(a3 - a4) > 1) {
    r1();
    return 0;
  }
  if (a3 == a4) {
    if (a1 > a3 && a2 >= a4) {
      for (i = 1; i <= a1 - a3 - 1; i++) ret += '4';
      for (i = 1; i <= a3; i++) ret += "47";
      for (i = 1; i <= a2 - a4; i++) ret += '7';
      ret += '4';
      r2(ret);
      return 0;
    } else if (a1 >= a3 && a2 > a4) {
      ret += '7';
      for (i = 1; i <= a1 - a3; i++) ret += '4';
      for (i = 1; i <= a3; i++) ret += "47";
      for (i = 1; i <= a2 - a4 - 1; i++) ret += '7';
      r2(ret);
      return 0;
    } else {
      r1();
      return 0;
    }
  }
  if (a3 < a4) {
    if (a1 >= a4 && a2 >= a4) {
      string tmp;
      for (i = 1; i <= a4; i++) tmp += "74";
      string s4;
      for (i = 1; i <= a1 - a4; i++) s4 += '4';
      string s7;
      for (i = 1; i <= a2 - a4; i++) s7 += '7';
      ret = tmp.substr(0, 2) + s4 + tmp.substr(2, tmp.size() - 3) + s7 + '4';
      r2(ret);
      return 0;
    } else {
      r1();
      return 0;
    }
  }
  if (a3 > a4) {
    if (a1 >= a3 && a2 >= a4) {
      for (i = 1; i <= a1 - a3; i++) ret += '4';
      for (i = 1; i <= a3; i++) ret += "47";
      for (i = 1; i <= a2 - a3; i++) ret += '7';
      r2(ret);
      return 0;
    } else {
      r1();
      return 0;
    }
  }
}
