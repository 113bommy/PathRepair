#include <bits/stdc++.h>
using namespace std;
string tmp = "";
int a1, a2, a3, a4;
int f0(char n) {
  int ret = 0;
  for (int i = 0; i < tmp.size(); i++) {
    ret += (n == tmp[i]);
  }
  return ret;
}
int f1(string sub) {
  int ret = 0;
  for (int i = 1; i < tmp.size(); i++) {
    ret += (sub[0] == tmp[i - 1] && sub[1] == tmp[i]);
  }
  return ret;
}
string solve0() {
  int ta1 = a1, ta2 = a2, ta3 = a3, ta4 = a4;
  string ans = "";
  tmp = "";
  if (ta3 == ta4) {
    while (ta3-- > 0) {
      ans += "47";
      ta1--;
      ta2--;
    }
    ans += '4';
    ta1--;
  } else if (ta3 > ta4) {
    while (ta3--) {
      ans += "47";
      ta1--;
      ta2--;
    }
  } else {
    while (ta4--) {
      ans += "74";
      ta1--;
      ta2--;
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    tmp += ans[i];
    if (ta1 > 0 && ans[i] == '4') {
      while (ta1--) {
        tmp += '4';
      }
    }
  }
  if (ta1 > 0) {
    while (ta1--) {
      tmp += '4';
    }
  }
  ans = tmp;
  tmp = "";
  for (int i = ans.size() - 1; i >= 0; i--) {
    tmp += ans[i];
    if (ta2 > 0 && ans[i] == '7') {
      while (ta2--) {
        tmp += '7';
      }
    }
  }
  if (ta2 > 0) {
    while (ta2--) {
      tmp += '7';
    }
  }
  reverse(tmp.begin(), tmp.end());
  if (f0('4') == a1 && f0('7') == a2 &&
      ((tmp.size() > 1 && f1("47") == a3 && f1("74") == a4) ||
       (tmp.size() < 2)))
    return tmp;
  return "0";
}
string solve1() {
  int ta1 = a1, ta2 = a2, ta3 = a3, ta4 = a4;
  string ans = "";
  tmp = "";
  if (ta3 == ta4) {
    while (ta3-- > 0) {
      ans += "47";
      ta1--;
      ta2--;
    }
    ans += '7';
    ta2--;
  } else if (ta3 > ta4) {
    while (ta3--) {
      ans += "47";
      ta1--;
      ta2--;
    }
  } else {
    while (ta4--) {
      ans += "74";
      ta1--;
      ta2--;
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    tmp += ans[i];
    if (ta1 > 0 && ans[i] == '4') {
      while (ta1--) {
        tmp += '4';
      }
    }
  }
  if (ta1 > 0) {
    while (ta1--) {
      tmp += '4';
    }
  }
  ans = tmp;
  tmp = "";
  for (int i = ans.size() - 1; i >= 0; i--) {
    tmp += ans[i];
    if (ta2 > 0 && ans[i] == '7') {
      while (ta2--) {
        tmp += '7';
      }
    }
  }
  if (ta2 > 0) {
    while (ta2--) {
      tmp += '7';
    }
  }
  reverse(tmp.begin(), tmp.end());
  if (f0('4') == a1 && f0('7') == a2 &&
      ((tmp.size() > 1 && f1("47") == a3 && f1("74") == a4) ||
       (tmp.size() < 2)))
    return tmp;
  return "0";
}
int main() {
  cin >> a1 >> a2 >> a3 >> a4;
  string a = solve0(), b = solve1();
  if (a == "0" && b != "0")
    cout << b << endl;
  else if (b == "0" && a != "0")
    cout << a << endl;
  else if (a != "0" && b != "0" && a.compare(b) <= 0)
    cout << a << endl;
  else if (a != "0" && b != "0" && b.compare(a) <= 0)
    cout << b << endl;
  else
    cout << -1 << endl;
}
