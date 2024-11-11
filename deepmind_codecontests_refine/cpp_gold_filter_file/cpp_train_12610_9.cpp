#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a = 0, b = 0, c = 0;
  cin >> n;
  string str;
  ;
  cin >> str;
  for (i = 0; i < n; i++) {
    if (str[i] == '0') {
      a++;
    }
    if (str[i] == '1') {
      b++;
    }
    if (str[i] == '2') {
      c++;
    }
  }
  i = 0;
  while (a < n / 3 && i < n) {
    if (c > n / 3) {
      if (str[i] == '2') {
        str[i] = '0';
        a++;
        c--;
      }
    }
    i++;
  }
  i = 0;
  while (a < n / 3 && i < n) {
    if (b > n / 3) {
      if (str[i] == '1') {
        str[i] = '0';
        a++;
        b--;
      }
    }
    i++;
  }
  i = n - 1;
  while (c < n / 3 && i > 0) {
    if (b > n / 3) {
      if (str[i] == '1') {
        str[i] = '2';
        c++;
        b--;
      }
    }
    i--;
  }
  i = n - 1;
  while (c < n / 3 && i > 0) {
    if (a > n / 3) {
      if (str[i] == '0') {
        str[i] = '2';
        c++;
        a--;
      }
    }
    i--;
  }
  i = 0;
  while (b < n / 3 && i < n) {
    if (c > n / 3) {
      if (str[i] == '2') {
        str[i] = '1';
        b++;
        c--;
      }
    }
    i++;
  }
  i = n - 1;
  while (b < n / 3 && i > 0) {
    if (a > n / 3) {
      if (str[i] == '0') {
        str[i] = '1';
        b++;
        a--;
      }
    }
    i--;
  }
  cout << str;
}
