#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  cin >> x;
  int siz = x.size();
  string y = "AHIMNOTUVWXY";
  bool vis = 0;
  if (siz % 2 == 0) {
    for (int i = 0; i < siz / 2; i++) {
      if (x[i] == x[siz - 1 - i]) {
        for (int g = 0; g < y.size(); g++)
          if (x[i] == y[g]) {
            vis = 1;
            break;
          }
        if (!vis) {
          cout << "NO";
          return 0;
        }
      } else {
        cout << "NO";
        return 0;
      }
      vis = 0;
    }
    cout << "YES";
    return 0;
  } else {
    for (int i = 0; i < siz / 2; i++) {
      if (x[i] == x[siz - 1 - i]) {
        for (int g = 0; g < y.size(); g++) {
          if (x[i] == y[g]) {
            vis = 1;
            break;
          }
        }
        if (!vis) {
          cout << "NO";
          return 0;
        }
      } else {
        cout << "NO";
        return 0;
      }
      vis = 0;
    }
    vis = 0;
    for (int i = 0; i < y.size(); i++)
      if (x[siz / 2] == y[i]) {
        vis = 1;
        break;
      }
    if (vis)
      cout << "YES";
    else
      cout << "NO";
  }
}
