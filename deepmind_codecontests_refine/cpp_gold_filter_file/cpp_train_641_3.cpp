#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  int ini = a[0] + a[1] + a[2] + a[3];
  if (ini & 1) {
    cout << "NO";
    return 0;
  }
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = i + 1; j < 4; j++) {
      int put = a[i] + a[j];
      if (ini / 2 == put) {
        cout << "YES";
        return 0;
      }
    }
  }
  sort(a, a + 4);
  int y = a[0] + a[1] + a[2];
  if (a[3] == y) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
