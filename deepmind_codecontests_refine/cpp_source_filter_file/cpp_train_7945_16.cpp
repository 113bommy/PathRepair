#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a[i][j];
    }
  }
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int l = 0, r = 0, u = 0, lo = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][0] > a[i][0] && a[i][1] == a[j][1]) {
        r++;
      } else if (a[j][0] < a[i][0] && a[i][1] == a[j][1]) {
        l++;
      } else if (a[j][1] > a[i][1] && a[i][0] == a[j][0]) {
        u++;
      } else if (a[j][1] < a[i][1] && a[i][0] == a[j][0]) {
        lo++;
      }
    }
    if (lo >= 1 && u >= 1 && r >= 1 && l >= 1) {
      k++;
    }
  }
  cout << k;
}
