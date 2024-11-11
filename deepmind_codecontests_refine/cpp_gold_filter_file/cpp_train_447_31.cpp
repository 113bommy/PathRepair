#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, d[50][50], a[111], b[111];
  cin >> x;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) cin >> d[i][j];
  }
  for (int i = 0; i < x; i++) {
    a[i] = b[i] = 0;
    for (int j = 0; j < x; j++) {
      a[i] += d[i][j];
      b[i] += d[j][i];
    }
  }
  int ans = 0;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      if (a[i] < b[j]) ans++;
    }
  }
  cout << ans;
  return 0;
}
