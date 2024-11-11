#include <bits/stdc++.h>
using namespace std;
long long a[2000][2000], b[2000][2000];
int main() {
  ios_base::sync_with_stdio(false);
  long long x = 0, n, i, j, flag = 0, ans;
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      b[i][j] = x;
      a[i][j] = x;
      x++;
    }
  }
  for (i = 0; i < n - 1; i = i + 2) {
    for (j = 0; j < n / 2; j++) a[j][i] = b[j + n / 2][i + 1];
    for (j = n / 2; j < n; j++) a[j][i + 1] = b[j - n / 2][i];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) cout << a[i][j] << " ";
    cout << endl;
  }
  return 0;
}
