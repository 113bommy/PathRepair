#include <bits/stdc++.h>
using namespace std;
int main() {
  int d = 0, flag = 1, c = 0;
  int a[100][2] = {0}, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) cin >> a[i][j];
  }
  for (int i = 0; i < 2; i++) {
    d = a[i][0] + a[i][1];
    for (int j = 0; j < n; j++) {
      if (d == a[j][0] && (a[j][0] + a[j][1] == a[i][0]) && i != j) {
        c++;
      }
    }
  }
  if (c > 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
