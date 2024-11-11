#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, i, j;
  int tempa, tempb;
  cin >> n >> m;
  int a[m];
  for (i = 0; i < m; i++) {
    a[i] = 0;
  }
  for (i = 0; i < n; i++) {
    cin >> tempa;
    for (j = 0; j < tempa; j++) {
      cin >> tempb;
      a[tempb - 1]++;
    }
  }
  bool result = true;
  for (i = 0; i < m; i++) {
    if (a[i] == 0) {
      result = false;
      break;
    }
  }
  if (result) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
