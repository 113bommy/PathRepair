#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, temp = 0, flag = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1]) {
      if (temp == 0)
        continue;
      else {
        cout << "NO" << endl;
        flag = -1;
        break;
      }
    } else if (a[i] > a[i + 1]) {
      if (temp == 0) {
        temp = -1;
        continue;
      }
    } else {
      cout << "NO" << endl;
      flag = 1;
      break;
    }
  }
  if (flag == 0) cout << "YES" << endl;
  return 0;
}
