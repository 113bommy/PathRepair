#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int row, col;
  if (n <= 20) {
    int row = 1;
    int col = n;
    cout << row << " " << col << endl;
    cout << s;
  } else if (n >= 21 && n <= 40) {
    int row = 2;
    int stars = 0;
    int col;
    if (n % 2 == 0) {
      col = n / 2;
    } else {
      col = n / 2 + 1;
      stars = col * 2 - n;
    }
    int ctr = 0;
    cout << row << " " << col << endl;
    for (int i = 0; i < row - 1; i++) {
      if (stars > 0) {
        for (int j = 0; j < col - 1; j++) {
          cout << s[ctr];
          ctr++;
        }
        cout << "*";
        stars--;
        cout << endl;
      } else {
        for (int j = 0; j < col; j++) {
          cout << s[ctr];
          ctr++;
        }
        cout << endl;
      }
    }
    while (ctr <= (n - 1)) {
      cout << s[ctr];
      ctr++;
    }
    if (stars > 0) cout << "*";
  } else if (n >= 41 && n <= 60) {
    int row = 3;
    int stars = 0;
    int col;
    if (n % 3 == 0) {
      col = n / 3;
    } else {
      col = n / 3 + 1;
      stars = col * 3 - n;
    }
    int ctr = 0;
    cout << row << " " << col << endl;
    for (int i = 0; i < row - 1; i++) {
      if (stars > 0) {
        for (int j = 0; j < col - 1; j++) {
          cout << s[ctr];
          ctr++;
        }
        cout << "*";
        stars--;
        cout << endl;
      } else {
        for (int j = 0; j < col; j++) {
          cout << s[ctr];
          ctr++;
        }
        cout << endl;
      }
    }
    while (ctr <= (n - 1)) {
      cout << s[ctr];
      ctr++;
    }
    if (stars > 0) cout << "*";
  } else if (n >= 61 && n <= 80) {
    int row = 4;
    int stars = 0;
    int col;
    if (n % 4 == 0) {
      col = n / 4;
    } else {
      col = n / 4 + 1;
      stars = col * 4 - n;
    }
    int ctr = 0;
    cout << row << " " << col << endl;
    for (int i = 0; i < row - 1; i++) {
      if (stars > 0) {
        for (int j = 0; j < col - 1; j++) {
          cout << s[ctr];
          ctr++;
        }
        cout << "*";
        stars--;
        cout << endl;
      } else {
        for (int j = 0; j < col; j++) {
          cout << s[ctr];
          ctr++;
        }
        cout << endl;
      }
    }
    while (ctr <= (n - 1)) {
      cout << s[ctr];
      ctr++;
    }
    if (stars > 0) cout << "*";
  } else {
    int row = 5;
    int stars = 0;
    int col;
    if (n % 5 == 0) {
      col = n / 5;
    } else {
      col = n / 5 + 1;
      stars = col * 5 - n;
    }
    int ctr = 0;
    cout << row << " " << col << endl;
    for (int i = 0; i < row - 1; i++) {
      if (stars > 0) {
        for (int j = 0; j < col - 1; j++) {
          cout << s[ctr];
          ctr++;
        }
        cout << "*";
        stars--;
        cout << endl;
      } else {
        for (int j = 0; j < col; j++) {
          cout << s[ctr];
          ctr++;
        }
        cout << endl;
      }
    }
    while (ctr <= (n - 1)) {
      cout << s[ctr];
      ctr++;
    }
    if (stars > 0) cout << "*";
  }
}
