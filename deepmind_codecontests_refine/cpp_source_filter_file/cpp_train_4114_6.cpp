#include <bits/stdc++.h>
using namespace std;
string str;
string a, b, t;
int check_w(char ch) {
  if (ch >= 'a' && ch <= 'z' || (ch >= 'A' && ch <= 'Z')) return 1;
  return 0;
}
int check_n(char ch) {
  if (ch >= '0' && ch <= '9') return 1;
  return 0;
}
int main() {
  int i = 0, j;
  cin >> str;
  int n = str.length();
  for (i = 0; i < n; i++) {
    if (str[i] == ';') {
      str[i] = ',';
    }
  }
  if (str[n - 1] == ',') {
    str[n++] = ' ';
  }
  i = 0;
  int f = 0;
  int n1 = 0, n2 = 0;
  while (i < n) {
    int c = 0;
    f = 0;
    t.clear();
    while (i < n) {
      if (str[i] == ',') break;
      if (check_w(str[i]) || str[i] == '.') {
        f = 1;
      }
      if (f != 1 && check_n(str[i])) {
        f = 2;
      }
      t = t + str[i];
      i++;
    }
    j = 0;
    if (f == 2) {
      if (t[0] == '0' && t.length()) {
        f = 1;
      } else {
        j = 0;
        b += t;
        b += ',';
      }
    }
    if (f != 2) {
      a += t;
      a += ',';
    }
    i++;
  }
  n2 = b.length();
  n1 = a.length();
  if (n2 > 0) b[n2 - 1] = ' ';
  if (n1 > 0) a[n1 - 1] = ' ';
  if (b.length() == 0) {
    puts("-");
  } else {
    printf("%c", '"');
    for (i = 0; i < n2; i++) {
      if (b[i] == ' ') continue;
      cout << b[i];
    }
    printf("%c", '"');
    puts("");
  }
  if (a.length() == 0) {
    puts("-");
  } else {
    printf("%c", '"');
    for (i = 0; i < a.length(); i++) {
      if (a[i] == ' ') continue;
      printf("%c", a[i]);
    }
    printf("%c\n", '"');
  }
}
