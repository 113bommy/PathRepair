#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == s[i + 1] && s[i] == '1') {
      return false;
    }
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  string v;
  cin >> v;
  int flag = 0, f = 1;
  if (n == 1 && v[0] == '0') {
    cout << "No";
  } else {
    if (check(v) == false) {
      flag = 1;
    } else {
      for (int i = 0; i < n - 1; i++) {
        if (v[i] == '0') {
          v[i] = '1';
          if (check(v) == true) {
            cout << "No";
            f = 0;
            break;
          } else {
            v[i] = '0';
          }
        }
      }
    }
    if (flag == 1) {
      cout << "No";
    }
    if (f == 1 && flag == 0) {
      cout << "Yes";
    }
  }
}
