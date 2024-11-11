#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, l;
  cin >> n >> d >> l;
  if (n % 2) {
    if (d < 0 || d > l) {
      int d0 = d;
      if (d > l) {
        d0 = l - d + 1;
      }
      if ((n - 1) / 2 * (l - 1) + d0 > 0) {
        if (d <= 0) {
          for (int i = 0; i < n - 1; i++) {
            if (i % 2) {
              if (d <= 0) {
                cout << min(1 - d + 1, l) << " ";
                d += min(1 - d, l - 1);
              } else {
                cout << 1 << " ";
              }
            } else {
              cout << 1 << " ";
            }
          }
          cout << d;
        } else {
          for (int i = 0; i < n - 1; i++) {
            if (!(i % 2)) {
              if (d > l) {
                cout << min(d - l + 1, l) << " ";
                d -= min(d - l, l - 1);
              } else {
                cout << 1 << " ";
              }
            } else {
              cout << 1 << " ";
            }
          }
          cout << d;
        }
      } else {
        cout << -1;
      }
    } else {
      for (int i = 0; i < n - 1; i++) {
        cout << 1 << " ";
      }
      cout << d;
    }
  } else {
    d = 1 - d;
    if (d < 0 || d > l) {
      int d0 = d;
      if (d > l) {
        d0 = l - d + 1;
      }
      if ((n - 1) / 2 * (l - 1) + d0 > 0) {
        if (d <= 0) {
          for (int i = 0; i < n - 1; i++) {
            if (!(i % 2)) {
              if (d <= 0) {
                cout << min(1 - d + 1, l) << " ";
                d += min(1 - d, l - 1);
              } else {
                cout << 1 << " ";
              }
            } else {
              cout << 1 << " ";
            }
          }
          cout << d;
        } else {
          for (int i = 0; i < n - 1; i++) {
            if (i % 2) {
              if (d > l) {
                cout << min(d - l + 1, l) << " ";
                d -= min(d - l, l - 1);
              } else {
                cout << 1 << " ";
              }
            } else {
              cout << 1 << " ";
            }
          }
          cout << d;
        }
      } else {
        cout << -1;
      }
    } else {
      for (int i = 0; i < n - 1; i++) {
        cout << 1 << " ";
      }
      cout << d;
    }
  }
}
