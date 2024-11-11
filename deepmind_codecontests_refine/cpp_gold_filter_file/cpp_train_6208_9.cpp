#include <bits/stdc++.h>
using namespace std;
int a[7];
int main() {
  int i, j, k, sum = 0, res;
  for (i = 1; i <= 6; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % 2 != 0) {
    cout << "NO" << endl;
    return 0;
  }
  for (i = 1; i <= 6; i++)
    for (j = i + 1; j <= 6; j++)
      for (k = j + 1; k <= 6; k++) {
        res = a[i] + a[j] + a[k];
        if (res == sum / 2) {
          cout << "YES" << endl;
          return 0;
        }
      }
  cout << "NO" << endl;
  return 0;
}
