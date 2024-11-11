#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long a[n], b[m];
  long long v[n][m];
  long long k = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
      k = max(k, v[i][j]);
    }
  k++;
  bool ans = true;
  bool ch = false;
  for (int i = 0; i < m; i++) b[i] = v[0][i];
  a[0] = 0;
  for (int i = 1; i < n; i++) a[i] = v[i][0] - b[0];
  for (int i = 0; i < n && !ch; i++) {
    for (int j = 0; j < m && !ch; j++) {
      long long x = a[i] + b[j];
      if (a[i] < 0) x = x + k;
      if (x % k != v[i][j]) {
        k = k + x % k - v[i][j];
        ch = true;
      }
    }
  }
  if (!ch) {
    cout << "YES" << endl;
    cout << k << endl;
    for (int i = 0; i < n; i++)
      if (a[i] < 0) a[i] += k;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < m; i++) cout << b[i] << " ";
    cout << endl;
  } else {
    for (int i = 0; i < n && ans; i++) {
      for (int j = 0; j < m && ans; j++) {
        long long x = a[i] + b[j] + k;
        if (x % k != v[i][j]) {
          ans = false;
        }
      }
    }
    if (ans) {
      cout << "YES" << endl;
      cout << k << endl;
      for (int i = 0; i < n; i++)
        if (a[i] < 0) a[i] += k;
      for (int i = 0; i < n; i++) cout << a[i] << " ";
      cout << endl;
      for (int i = 0; i < m; i++) cout << b[i] << " ";
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
