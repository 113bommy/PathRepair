#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, mod = 1e9 + 7;
int main() {
  int a, b, c, d, flag = 0;
  cin >> a >> b >> c >> d;
  if (a > b + 1 || d > c + 1) {
    cout << "NO" << endl;
  } else if (a == b + 1) {
    if (d != 0 || c != 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 1; i <= b; i++) {
        printf("0 1 ");
      }
      printf("0");
    }
  } else if (d == c + 1) {
    if (a != 0 || b != 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 1; i <= c; i++) {
        printf("3 2 ");
      }
      printf("3");
    }
  } else {
    if (abs(b - a - (c - d)) > 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      if (b - a == c - d) {
        for (int i = 1; i <= a; i++) {
          printf("0 1 ");
        }
        for (int i = 1; i <= b - a; i++) {
          printf("2 1 ");
        }
        for (int i = 1; i <= d; i++) {
          printf("2 3 ");
        }
      } else if (b - a == c - d + 1) {
        printf("1 ");
        for (int i = 1; i <= a; i++) {
          printf("0 1 ");
        }
        for (int i = 1; i <= c - d; i++) {
          printf("2 1 ");
        }
        for (int i = 1; i <= d; i++) {
          printf("2 3 ");
        }
      } else {
        for (int i = 1; i <= a; i++) {
          printf("0 1 ");
        }
        for (int i = 1; i <= b - a; i++) {
          printf("2 1 ");
        }
        for (int i = 1; i <= d; i++) {
          printf("2 3 ");
        }
        printf("2");
      }
    }
  }
  return 0;
}
