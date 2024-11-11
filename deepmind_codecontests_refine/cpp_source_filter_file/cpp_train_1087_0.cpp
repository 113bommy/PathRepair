#include <bits/stdc++.h>
using namespace std;
int n, m;
int am[101], duong[101];
int main() {
  cin >> n;
  int i = 0, j = 0;
  bool flag = 1;
  while (n > 0) {
    cin >> m;
    if (m <= 0) {
      if (m == 0 && flag) {
        flag = 0;
      }
      if (m < 0) {
        am[j] = m;
        j++;
      }
    } else {
      duong[i] = m;
      i++;
    }
    n--;
  }
  sort(am, am + j);
  if (i == 0) {
    if (j <= 1) {
      if (!flag)
        cout << 0 << endl;
      else
        cout << am[0] << endl;
    } else {
      for (int k = 0; k + 1 < j; k += 2) {
        if (k >= 2) cout << " ";
        cout << am[k] << " " << am[k + 1];
      }
      cout << endl;
    }
  } else {
    cout << duong[0];
    for (int k = 1; k < i; k++) cout << " " << duong[k];
    if (j >= 2) {
      for (int k = 0; k < j; k += 2) {
        cout << " " << am[k] << " " << am[k + 1];
      }
    }
    cout << endl;
  }
  return 0;
}
