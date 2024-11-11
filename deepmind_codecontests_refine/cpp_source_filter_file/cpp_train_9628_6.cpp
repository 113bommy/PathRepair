#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, i, j, t, max_pos, flag;
  cin >> n >> k;
  if (n % 2 == 0) {
    max_pos = (n * n) / 2;
    if (k > max_pos) {
      cout << "No"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
      t = 0;
      flag = 0;
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          if (t < k) {
            if (flag == 0) {
              if (j % 2 == 0) {
                cout << "L";
                t++;
              } else {
                cout << "S";
              }
            } else if (flag == 1) {
              if (j % 2 != 0) {
                cout << "L";
                t++;
              } else {
                cout << "S";
              }
            }
          } else {
            cout << "S";
          }
        }
        if (flag == 0) {
          flag = 1;
        } else {
          flag = 0;
        }
        cout << "\n";
      }
    }
  } else if (n % 2 != 0) {
    max_pos = (n * n) / 2 + 1;
    if (k > max_pos) {
      cout << "No"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
      t = 0;
      flag = 0;
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          if (t < k) {
            if (flag == 0) {
              if (j % 2 == 0) {
                cout << "L";
                t++;
              } else {
                cout << "S";
              }
            } else if (flag == 1) {
              if (j % 2 != 0) {
                cout << "L";
                t++;
              } else {
                cout << "S";
              }
            }
          } else {
            cout << "S";
          }
        }
        if (flag == 0) {
          flag = 1;
        } else {
          flag = 0;
        }
        cout << "\n";
      }
    }
  }
}
