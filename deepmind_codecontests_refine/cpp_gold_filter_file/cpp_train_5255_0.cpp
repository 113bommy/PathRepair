#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
long long c[MAXN][MAXN], a[MAXN], b[MAXN], d[MAXN][MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> c[i][j];
  a[0] = 0;
  for (int i = 0; i < n; i++) {
    b[i] = c[i][0];
  }
  for (int k = 0; k < m; k++) {
    a[k] = c[0][k] - c[0][0];
  }
  long long mod = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      d[i][j] = b[i] + a[j];
      if (d[i][j] != c[i][j]) {
        long long tmp = abs(d[i][j] - c[i][j]);
        if (mod != -1 && tmp != mod) {
          cout << "NO" << endl;
          return 0;
        }
        mod = tmp;
      }
    }
  if (mod == -1) mod = 1e18;
  for (int i = 0; i < m; i++) a[i] = (a[i] + mod) % mod;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      d[i][j] = (b[i] + a[j]) % mod;
      if (d[i][j] != c[i][j]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  cout << "YES" << endl;
  cout << mod << endl;
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << endl;
  for (int j = 0; j < m; j++) cout << a[j] << " ";
  cout << endl;
  return 0;
}
