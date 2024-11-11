#include <bits/stdc++.h>
using namespace std;
int b[100];
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  int f = 0, h = -1;
  for (int i = 1; i <= 100; i++) {
    if (b[i] == 1) {
      f++;
    } else if (b[i] > 2) {
      h = i;
    }
  }
  if (f % 2 == 0) {
    cout << "YES\n";
    int r = f / 2;
    for (int i = 0; i < n; i++) {
      if (b[a[i]] == 1) {
        if (r > 0) {
          cout << "A";
          r--;
        } else {
          cout << "B";
        }
      } else {
        cout << "A";
      }
    }
  } else {
    if (h == -1) {
      return cout << "NO", 0;
    }
    int y = 0;
    cout << "YES\n";
    int r = f / 2;
    for (int i = 0; i < n; i++) {
      if ((a[i] != h) || (a[i] == h && y != 0)) {
        if (b[a[i]] == 1) {
          if (r > 0) {
            cout << "A";
            r--;
          } else {
            cout << "B";
          }
        } else {
          cout << "B";
        }
      } else {
        cout << "A";
        y++;
      }
    }
  }
}
