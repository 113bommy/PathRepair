#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x[n], y[n];
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  unordered_map<int, int> mp1, mp2;
  for (int i = 0; i < n; i++) {
    if (x[i] % 2 == 0)
      mp1[2]++;
    else if (x[i] % 2 != 0)
      mp1[1]++;
    if (y[i] % 2 == 0)
      mp2[2]++;
    else if (y[i] % 2 != 0)
      mp2[1]++;
  }
  if (mp1[1] % 2 == 0 && mp1[1] % 2 == 0)
    cout << "0";
  else if (mp1[1] % 2 != 0 && mp2[1] % 2 != 0) {
    int flag = 0;
    if (mp2[2] > 0 || mp1[2] > 0) {
      for (int i = 0; i < n; i++) {
        if ((x[i] % 2 == 0 && y[i] % 2 != 0) ||
            (x[i] % 2 != 0 && y[i] % 2 == 0)) {
          flag = 1;
          break;
        }
      }
    }
    if (flag)
      cout << "1";
    else
      cout << "-1";
  } else
    cout << "-1";
}
