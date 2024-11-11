#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ar1[n], ar2[n], ar3[n], ar4[n];
  for (int i = 0; i < n; i++) cin >> ar1[i];
  for (int i = 0; i < n; i++) cin >> ar2[i];
  for (int i = 0; i < n - 1; i++) {
    ar3[i] = ar1[i + 1] - ar1[i];
    ar4[i] = ar2[i + 1] - ar2[i];
  }
  ar3[n - 1] = m - ar1[n - 1] + ar1[0];
  ar4[n - 1] = m - ar2[n - 1] + ar2[0];
  bool flag;
  for (int i = 0; i < n; i++) {
    flag = false;
    for (int j = 0, f = i; j < n; f++, j++) {
      if (f == n) f = 0;
      if (ar3[j] != ar4[f]) {
        flag = true;
        break;
      }
    }
    if (flag == false) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
