#include <bits/stdc++.h>
using namespace std;
int t, i, len, j, s, k, n, m, g, l;
string str;
int main() {
  cin >> t;
  for (i = 0; i < t; i++) {
    g = 0;
    n = 0;
    s = 0;
    cin >> str;
    len = str.size();
    for (j = 0; j < len; j++) {
      if (str[j] >= 97 && str[j] <= 122) {
        s++;
        if (s == 2) k = j;
      } else if (str[j] >= 65 && str[j] <= 90) {
        g++;
        if (g == 2) l = j;
      } else if (str[j] >= 48 && str[j] <= 57) {
        n++;
        if (n == 2) m = j;
      }
    }
    if (s > 0 && g > 0 && n > 0)
      cout << str << endl;
    else if (s < 1 && n > 1 && g > 0) {
      str[m] = 'a';
      cout << str << endl;
    } else if (s < 1 && n > 0 && g > 1) {
      str[l] = 'a';
      cout << str << endl;
    } else if (s > 1 && n < 1 && g > 0) {
      str[k] = '7';
      cout << str << endl;
    } else if (s > 0 && n < 1 && g > 1) {
      str[l] = '7';
      cout << str << endl;
    } else if (s > 1 && n > 0 && g < 1) {
      str[k] = 'A';
      cout << str << endl;
    } else if (s > 0 && n > 1 && g < 1) {
      str[m] = 'A';
      cout << str << endl;
    } else if (s < 1 && g == 2) {
      str[l] = 'a';
      cout << str << endl;
    } else if (n < 1 && g == 2) {
      str[l] = '4';
      cout << str << endl;
    } else if (s < 1 && n == 2) {
      str[m] = 'a';
      cout << str << endl;
    } else if (g < 1 && n == 2) {
      str[m] = 'A';
      cout << str << endl;
    } else if (s == 2 && n < 1) {
      str[k] = '9';
      cout << str << endl;
    } else if (s == 2 && g < 1) {
      str[k] = 'A';
      cout << str << endl;
    } else if (s > 2 && n < 1 && g < 1) {
      str[k] = '9';
      str[k + 1] = 'A';
      cout << str << endl;
    } else if (s < 1 && n > 2 && g < 1) {
      str[m] = 'a';
      str[m + 1] = 'A';
      cout << str << endl;
    } else if (s < 1 && n < 1 && g > 2) {
      str[l] = '9';
      str[l + 1] = 'a';
      cout << str << endl;
    }
  }
}
