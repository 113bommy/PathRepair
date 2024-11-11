#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, i, j, x = 0;
  cin >> n;
  char a[n][5];
  for (i = 0; i < n; i++) {
    for (j = 0; j < 5; j++) cin >> a[i][j];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < 4; j++) {
      if (a[i][j] == 'O' && a[i][j + 1] == 'O') {
        a[i][j] = '+';
        a[i][j + 1] = '+';
        x = 1;
        break;
      }
    }
    if (x) break;
  }
  if (x) {
    cout << "YES\n";
    for (i = 0; i < n; i++) {
      for (j = 0; j < 5; j++) cout << a[i][j];
      cout << "\n";
    }
  } else
    cout << "NO\n";
  x = 0;
  return 0;
}
