#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, flag;
  string s;
  cin >> n;
  cin >> s;
  j = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == '?') {
      j++;
    }
  }
  if (j == 0) {
    cout << "No"
         << "\n";
  } else {
    j = 0;
    i = 0;
    flag = 0;
    while (i < n) {
      if (s[i] == '?') {
        j = i;
        while (i < n && s[i] == '?') {
          i++;
        }
        if ((i - j) >= 2) {
          flag = 1;
        } else if (j == 0) {
          flag = 1;
        } else if (i < n && s[j - 1] == s[i]) {
          flag = 1;
        } else if (i == n) {
          flag = 1;
        }
      } else {
        if ((i + 1) < n && s[i] == s[i + 1]) {
          flag = 0;
          break;
        }
        i++;
      }
    }
    if (flag == 1) {
      cout << "Yes"
           << "\n";
    } else {
      cout << "No"
           << "\n";
    }
  }
}
