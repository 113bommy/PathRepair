#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[6], sum = 0, i = 0, j = 0, k = 0, t = 0, flag = 0, x = 0;
  for (i = 0; i < 6; i++) {
    cin >> a[i];
    sum = sum + a[i];
  }
  for (i = 0; i < 4; i++) {
    for (j = i + 1; j < 5; j++) {
      for (k = j + 1; k < 6; k++) {
        t = a[i] + a[j] + a[k];
        x = sum - t;
        if (t == x) {
          flag = 1;
          break;
        }
      }
    }
  }
  if (flag == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
