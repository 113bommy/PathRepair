#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, i;
  cin >> n >> m;
  int a[n + 1], hsh[n + 1];
  for (i = 0; i <= n; ++i) {
    a[i] = -1;
    hsh[i] = 0;
  }
  int ct = 0;
  int tmp;
  int b[m];
  for (i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (i = 0; i < m - 1; ++i) {
    tmp = (b[i + 1] - b[i] + n);
    if (tmp != n) tmp %= n;
    if (a[b[i]] != -1) {
      if (a[i] != tmp) {
        cout << "-1\n";
        return 0;
      } else
        continue;
    }
    if (tmp == n) {
      if (hsh[tmp] == 1) {
        cout << "-1\n";
        return 0;
      }
      a[b[i]] = tmp;
      hsh[tmp] = 1;
    } else {
      if (hsh[tmp % n] == 1) {
        cout << "-1\n";
        return 0;
      }
      a[b[i]] = tmp % n;
      hsh[tmp % n] = 1;
    }
  }
  int j;
  for (i = 1; i <= n; ++i) {
    if (a[i] == -1) {
      for (j = 1; j <= n; ++j) {
        if (hsh[j] == 0) {
          cout << j << " ";
          hsh[j] = 1;
          break;
        }
      }
      continue;
    }
    cout << a[i] << " ";
  }
  cout << '\n';
}
