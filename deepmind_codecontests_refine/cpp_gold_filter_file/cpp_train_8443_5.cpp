#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[200], b[200], c[200], d[200];
  bool flag[200];
  int i, j, n;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    flag[i] = true;
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i] < a[j] && b[i] < b[j] && c[i] < c[j])
        flag[i] = false;
      else if (a[i] > a[j] && b[i] > b[j] && c[i] > c[j])
        flag[j] = false;
    }
  }
  int min = 20000000;
  for (i = 0; i < n; i++) {
    if (flag[i]) {
      if (d[i] < min) min = d[i];
    }
  }
  for (i = 0; i < n; i++) {
    if (flag[i]) {
      if (d[i] == min) {
        j = i + 1;
        break;
      }
    }
  }
  cout << j << endl;
  return 0;
}
