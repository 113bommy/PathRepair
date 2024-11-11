#include <bits/stdc++.h>
using namespace std;
string str;
int k;
void ff() {
  int mn = -1;
  for (int i = 1; i <= str.size(); i++) {
    for (int j = 0; j + i <= str.size(); j++) {
      string s;
      int a = 0;
      for (int k = 0; k < i; k++) s += str[j + k];
      for (int k = 0; k < str.size() - s.size() + 1; k++) {
        int y = 1;
        for (int p = 0; p < s.size(); p++) {
          if (s[p] != str[p + k]) {
            y = 0;
          }
        }
        a += y;
      }
      if (a == 1) {
        if (mn == -1) {
          mn = s.size();
        }
      }
      if (a == 1 && mn == k && s.size() == mn) {
        cout << str << endl;
        cout << s << endl << endl;
      }
    }
  }
}
void f(int n) {
  if (n == 0) {
    ff();
    return;
  }
  str[n - 1] = '1';
  f(n - 1);
  str[n - 1] = '0';
  f(n - 1);
}
int main() {
  int n;
  cin >> n >> k;
  string s;
  for (int i = 0; i < n; i++) {
    s += '0';
    str += '0';
  }
  if (k == 1) {
    s[0] = '1';
    cout << s << endl;
    return 0;
  }
  if (k == 2) {
    s[0] = '1';
    s[1] = '1';
    cout << s << endl;
    return 0;
  }
  if (k < (n + 2) / 3) {
    s[k - 2] = '1';
    s[k * 2 - 3] = '1';
    cout << s << endl;
    return 0;
  } else {
    int t = (n - k) / 2;
    for (int i = 0; i < t; i++) {
      for (int j = i; j < n; j += t + 1) {
        s[j] = '1';
      }
    }
  }
  cout << s << endl;
}
