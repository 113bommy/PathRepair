#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(5, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++a[x];
  }
  int odp = 0;
  if (a[1] >= a[2]) {
    odp += a[2];
    a[3] += a[2];
    a[1] -= a[2];
    a[2] = 0;
    odp += a[1] / 3 * 2;
    a[3] += a[1] / 3;
    a[1] %= 3;
    if (a[1] == 1) {
      if (a[3] >= 1)
        ++odp;
      else {
        if (a[4] >= 2)
          odp += 2;
        else {
          cout << "-1";
          return 0;
        }
      }
    }
    if (a[1] == 2) {
      if (a[3] >= 2 || a[4] >= 1)
        odp += 2;
      else {
        cout << "-1";
        return 0;
      }
    }
  } else {
    odp += a[1];
    a[3] += a[1];
    a[2] -= a[1];
    a[1] = 0;
    odp += a[2] / 3 * 2;
    a[3] += a[2] / 3;
    a[2] %= 3;
    if (a[2] == 1) {
      if (a[4] >= 1)
        ++odp;
      else {
        if (a[3] >= 2)
          odp += 2;
        else {
          cout << "-1";
          return 0;
        }
      }
    }
    if (a[2] == 2) odp += 2;
  }
  cout << odp;
  return 0;
}
