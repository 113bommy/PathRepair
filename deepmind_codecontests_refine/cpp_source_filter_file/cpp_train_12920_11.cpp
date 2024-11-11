#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int a[26] = {}, A[26] = {}, c[10] = {};
    int digit = 0, lower = 0, upper = 0, x = 0, y = 0, z = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 'a' && s[i] <= 'z') lower++;
      if (s[i] >= 'A' && s[i] <= 'Z') upper++;
      if (s[i] >= '1' && s[i] <= '9') digit++;
    }
    for (int i = 0; i < s.size(); i++) {
      if (digit == 0) {
        if (lower > 1 and (s[i] >= 'a' and s[i] <= 'z')) {
          s[i] = '4';
          digit = 1;
        } else if (upper > 1 and (s[i] >= 'A' and s[i] <= 'Z')) {
          s[i] = '4';
          digit = 1;
        }
      }
      if (lower == 0) {
        if (digit > 1 and (s[i] >= '1' and s[i] <= '9')) {
          s[i] = 'a';
          lower = 1;
        } else if (upper > 1 and (s[i] >= 'A' and s[i] <= 'Z')) {
          s[i] = 'a';
          lower = 1;
        }
      }
      if (upper == 0) {
        if (digit > 1 and (s[i] >= '1' and s[i] <= '9')) {
          s[i] = 'A';
          upper = 1;
        } else if (lower > 1 and (s[i] >= 'a' and s[i] <= 'z')) {
          s[i] = 'A';
          upper = 1;
        }
      }
    }
    cout << s << endl;
  }
}
