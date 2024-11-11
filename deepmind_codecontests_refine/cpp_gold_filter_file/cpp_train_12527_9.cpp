#include <bits/stdc++.h>
using namespace std;
int a[1001000] = {0}, b[1001000] = {0};
int main() {
  string s;
  int i, j, k, l, m, n, co = 0, p = 0, t;
  cin >> s;
  l = s.length();
  if (s[0] == '.') {
    cout << "NO";
    return 0;
  }
  a[0] = 1;
  for (i = 1; i < l; i++) {
    if (co == 0 && s[i] != '.') {
      a[i] = a[i - 1] + 1;
      if (a[i] > 8) {
        cout << "NO";
        return 0;
      }
    } else if (s[i] != '.') {
      a[i] = a[i - 1] + 1;
      if (a[i] > 11) {
        cout << "NO";
        return 0;
      }
    } else {
      a[i] = 0;
      b[p++] = i;
      co++;
    }
  }
  if (co == 0) {
    cout << "NO";
    return 0;
  }
  for (i = 1; i < p; i++) {
    if ((b[i] - b[i - 1]) <= 2) {
      cout << "NO";
      return 0;
    }
  }
  if (a[l - 1] == 0 || a[l - 1] > 3) {
    cout << "NO";
    return 0;
  }
  if (co == 1) {
    for (i = 0; i < l; i++) {
      if (a[i] > 8) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES\n";
  k = 0;
  for (i = 0; i < l; i++) {
    if (s[i] == '.') {
      k++;
      cout << s[i];
      if (k == co) {
        for (j = i + 1; j < l; j++) {
          cout << s[j];
        }
        return 0;
      } else {
        if (a[i + 4] == 4) {
          cout << s[i + 1] << s[i + 2] << s[i + 3] << "\n";
          i = i + 3;
        } else {
          cout << s[i + 1] << "\n";
          i++;
        }
      }
    } else {
      cout << s[i];
    }
  }
  return 0;
}
