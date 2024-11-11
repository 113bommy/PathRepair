#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m + 1; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < n + 1; j++) {
    cin >> b[j];
  }
  if (m < n) {
    cout << "0/1" << endl;
    return 0;
  } else if (m > n) {
    if (a[0] * b[0] > 0)
      cout << "Infinity" << endl;
    else
      cout << "-Infinity" << endl;
  } else {
    if (a[0] * b[0] < 0) cout << "-";
    if (a[0] < 0) a[0] *= -1;
    if (b[0] < 0) b[0] *= -1;
    int max;
    if (a[0] > b[0])
      max = a[0];
    else
      max = b[0];
    for (int i = 2; i <= max; i++) {
      if (a[0] % i == 0 && b[0] % i == 0) {
        a[0] /= i;
        b[0] /= i;
        i = 1;
      }
    }
    cout << a[0] << "/" << b[0] << endl;
  }
}
