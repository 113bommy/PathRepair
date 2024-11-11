#include <bits/stdc++.h>
using namespace std;
char mas[102][102];
char next(char ch) {
  if (ch >= '0' && ch < '9')
    return ch + 1;
  else if (ch == '9')
    return 'a';
  else if (ch >= 'a' && ch < 'z')
    return ch + 1;
  else if (ch == 'z')
    return 'A';
  else
    return ch + 1;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, chik, r = 0;
    cin >> a >> b >> chik;
    for (int j = 1; j <= a; j++)
      for (int k = 1; k <= b; k++) {
        cin >> mas[j][k];
        if (mas[j][k] == 'R') r++;
      }
    int t1 = 0, t2 = 0, c1 = 0, c2 = 0;
    if (r % chik == 0) {
      t1 = r / chik;
      c1 = chik;
    } else {
      t1 = (r / chik) + 1;
      t2 = r / chik;
      c2 = chik - (r % chik);
      c1 = r % chik;
    }
    char now = '0';
    int col = t1;
    for (int j = 1; j <= a; j++) {
      if (j % 2 == 1) {
        for (int k = 1; k <= b; k++) {
          if (mas[j][k] == '.') {
            mas[j][k] = now;
          } else {
            if (col > 0) {
              mas[j][k] = now;
              col--;
            } else if (c1 > 1) {
              col = t1 - 1;
              now = next(now);
              mas[j][k] = now;
              c1--;
            } else {
              col = t2 - 1;
              now = next(now);
              mas[j][k] = now;
            }
          }
        }
      } else {
        for (int k = b; k > 0; k--) {
          if (mas[j][k] == '.') {
            mas[j][k] = now;
          } else {
            if (col > 0) {
              mas[j][k] = now;
              col--;
            } else if (c1 > 1) {
              col = t1 - 1;
              now = next(now);
              mas[j][k] = now;
              c1--;
            } else {
              col = t2 - 1;
              now = next(now);
              mas[j][k] = now;
            }
          }
        }
      }
    }
    for (int j = 1; j <= a; j++) {
      for (int k = 1; k <= b; k++) cout << mas[j][k];
      cout << '\n';
    }
  }
}
