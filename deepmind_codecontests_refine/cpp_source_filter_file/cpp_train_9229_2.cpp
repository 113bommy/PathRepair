#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, khalf;
  cin >> n >> k;
  if (k == 0) {
    cout << "YES" << endl;
    for (int i = 1; i <= 4; i++) {
      for (int j = 1; j <= n; j++) {
        cout << ".";
      }
      cout << endl;
    }
    goto kek;
  }
  if (k % 2 != 0 || k % 2 == 0) {
    cout << "YES" << endl;
    if (k % 2 != 0) {
      if (k >= n - 2) {
        for (int i = 1; i <= 4; i++) {
          for (int j = 1; j <= n; j++) {
            if (i != 1 & j != n & i != 4 & j != 1 & k != 0) {
              if (i != 3 || k != 1) {
                cout << "#";
                k--;
              } else {
                if (j != n - 1) {
                  cout << ".";
                }
                if (j == n - 1) {
                  cout << "#";
                }
              }
            } else {
              cout << ".";
            }
          }
          cout << endl;
        }
      } else {
        for (int i = 1; i <= 4; i++) {
          for (int j = 1; j <= n; j++) {
            if (i != 1 & j != n & i != 4 & j != 1 & k != 0) {
              if (i == 2) {
                if (j < (n - 2 - k) / 2 || j > (n - 2 - k) / 2 + k - 1) {
                  cout << ".";
                } else {
                  cout << "#";
                }
              } else {
                cout << ".";
              }
            } else {
              cout << ".";
            }
          }
          cout << endl;
        }
      }
    } else {
      for (int i = 1; i <= 4; i++) {
        khalf = k / 2;
        for (int j = 1; j <= n; j++) {
          if (i != 1 & j != n & i != 4 & j != 1 & khalf != 0) {
            cout << "#";
            khalf--;
          } else {
            cout << ".";
          }
        }
        cout << endl;
      }
    }
  } else {
    cout << "NO" << endl;
  }
kek:
  int j = 1;
}
