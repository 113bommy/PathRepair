#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, x;
  cin >> a >> b >> x;
  int n = a + b;
  int p, q;
  int t = 0;
  string s = "";
  int what = 0;
  if (b > a) {
    what = 1;
    swap(a, b);
  }
  s = "0";
  a--;
  p = 1;
  q = 0;
  for (int i = 2; i <= x; i = i + 2) {
    s = s + "10";
    t = t + 2;
    p++;
    q++;
    a--;
    b--;
  }
  if (t != x) {
    s = s + "1";
    q++;
    b--;
  }
  if (a > 0) {
    string ns = "";
    for (int i = 1; i <= a; i++) {
      ns += "0";
    }
    s = ns + s;
  }
  if (b > 0) {
    string ns = "";
    for (int i = 1; i <= b; i++) {
      ns += "1";
    }
    if (s[s.length() - 1] == '1') {
      s = s + ns;
    } else {
      s = s.substr(0, s.length() - 1);
      s = s + ns + "0";
    }
  }
  if (what) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') {
        s[i] = '1';
      } else {
        s[i] = '0';
      }
    }
  }
  cout << s;
}
