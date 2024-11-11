#include <bits/stdc++.h>
using namespace std;
long int a[100000], n, otr, otr1, pol, otr2, ok;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      otr++;
      if (ok == 1) {
        otr2 = a[i];
        ok = 2;
      };
      if (ok == 0) {
        otr1 = a[i];
        ok = 1;
      }
    }
    if (a[i] > 0) {
      pol++;
    }
  }
  if (otr % 2 == 1) {
    cout << 1 << " " << otr1 << "\n";
    if (otr != 1) {
      cout << otr - 1 << " ";
      for (int i = 1; i <= n; i++) {
        if (a[i] != otr1 && a[i] < 0) {
          cout << a[i] << " ";
        }
      }
      cout << "\n" << pol + 1 << " ";
      for (int i = 1; i <= n; i++) {
        if (a[i] >= 0) {
          cout << a[i] << " ";
        }
      }
      return 0;
    } else {
      cout << pol << " ";
      for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
          cout << a[i] << " ";
        }
      }
      cout << "\n";
      cout << "1 0.";
      return 0;
    }
  } else {
    if (otr == 2) {
      cout << 1 << " " << otr1;
      cout << "\n";
      cout << pol << " ";
      for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
          cout << a[i] << " ";
        }
      }
      cout << "\n" << 2 << " " << 0 << " " << otr2;
      return 0;
    } else {
      cout << 1 << " " << otr1 << "\n";
      cout << otr - 2 << " ";
      for (int i = 1; i <= n; i++) {
        if (a[i] != otr1 && a[i] != otr2 && a[i] < 0) {
          cout << a[i] << " ";
        }
      }
      cout << "\n";
      cout << pol + 2 << " ";
      for (int i = 1; i <= n; i++) {
        if (a[i] >= 0) {
          cout << a[i] << " ";
        }
      }
      cout << otr2;
      return 0;
    }
  }
}
