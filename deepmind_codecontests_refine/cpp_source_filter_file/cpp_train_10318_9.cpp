#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  int n, i, j, a[102], buc[102] = {0};
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    buc[a[i]]++;
  }
  int ones = 0, mx = -1;
  for (i = 1; i <= 100; i++) {
    if (buc[i] == 1) {
      ones++;
    }
    mx = max(mx, buc[i]);
  }
  if (!(ones % 2)) {
    cout << "YES" << endl;
    int cnt = 0;
    for (i = 0; i < n; i++) {
      if (buc[a[i]] > 1) {
        cout << "A";
      } else {
        if (cnt == ones / 2) {
          cout << "A";
        } else {
          cout << "B";
          cnt++;
        }
      }
    }
  } else {
    if (mx <= 2) {
      cout << "NO";
    } else {
      cout << "YES" << endl;
      int cnt = 0, flag = 0;
      for (i = 0; i < n; i++) {
        if (buc[a[i]] > 2 && !flag) {
          cout << "B";
          flag = 1;
        } else if (buc[a[i]] > 1 && flag) {
          cout << "B";
        } else if (buc[a[i]] > 1 && !flag) {
          cout << "B";
        } else {
          if (cnt == ones / 2) {
            cout << "A";
          } else {
            cout << "B";
            cnt++;
          }
        }
      }
    }
  }
  cout << endl;
  return 0;
}
