#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, j, d, k = 0, x, y = 0, t, q, i, m;
  char c;
  set<long long int> s;
  cin >> n;
  long long int a[n][2], b[n][2], v2[m];
  for (i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    if (a[i][0] % 2 == 0) {
      b[i][0] = 0;
    } else {
      x++;
      b[i][0] = 1;
    }
    if (a[i][1] % 2 == 0) {
      b[i][1] = 0;
    } else {
      y++;
      b[i][1] = 1;
    }
  }
  if (x % 2 == 0 & y % 2 == 0) {
    cout << 0;
    return 0;
  } else if (x % 2 != 0 & y % 2 != 0) {
    for (i = 0; i < n; i++) {
      if (b[i][0] != b[i][1]) {
        cout << 1;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
