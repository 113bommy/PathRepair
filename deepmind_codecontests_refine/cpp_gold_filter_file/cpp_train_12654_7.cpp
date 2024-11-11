#include <bits/stdc++.h>
using namespace std;
const int inf = (int)(1e9) + 100;
const int mod = (int)(1e9) + 7;
const int N = (int)(1e5) + 100;
inline int read() {
  int x;
  cin >> x;
  return x;
}
inline void out(int x) { cout << x << ' '; }
long long n, a[555][555], r[555], c[555], d[5], r2[555], c2[555], d2[555];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int px, py;
  long long fd = 0, sd = 0;
  for (int i = 1; i <= n; i++) {
    long long s = 0;
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      s += a[i][j];
      if (a[i][j] == 0) px = i, py = j;
      if (i == j) fd += a[i][j];
      if (i + j == n + 1) sd += a[i][j];
    }
    r[i] = s;
  }
  d[1] = fd;
  d[2] = sd;
  if (n == 1) {
    if (a[n][n] == 0) cout << 1;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    long long s = 0;
    for (int j = 1; j <= n; j++) {
      s += a[j][i];
    }
    c[i] = s;
  }
  if (px > 1 && px < n) {
    long long cur = r[n];
    long long need = r[px];
    long long num = cur - need;
    if (num <= 0) return cout << -1, 0;
    a[px][py] = num;
  } else if (px == 1) {
    long long cur = r[n];
    long long need = r[px];
    long long num = cur - need;
    if (num <= 0) return cout << -1, 0;
    a[px][py] = num;
  } else if (px == n) {
    long long cur = r[1];
    long long need = r[px];
    long long num = cur - need;
    if (num <= 0) return cout << -1, 0;
    a[px][py] = num;
  }
  fd = sd = 0;
  for (int i = 1; i <= n; i++) {
    long long s = 0;
    for (int j = 1; j <= n; j++) {
      s += (a[i][j]);
      if (a[i][j] == 0) px = i, py = j;
      if (i == j) fd += a[i][j];
      if (i + j == n + 1) sd += a[i][j];
    }
    r2[i] = s;
  }
  d2[1] = fd;
  d2[2] = sd;
  for (int i = 1; i <= n; i++) {
    long long s = 0;
    for (int j = 1; j <= n; j++) {
      s += a[j][i];
    }
    c2[i] = s;
  }
  if (d2[1] != d2[2]) return cout << -1, 0;
  for (int i = 1; i < n; i++) {
    if (r2[i] != r2[i + 1] || c2[i] != c2[i + 1] || fd != r2[i] ||
        fd != c2[i] || sd != r2[i] || sd != c2[i] || fd != r2[i + 1] ||
        fd != c2[i + 1] || sd != r2[i + 1] || sd != c2[i + 1])
      return cout << -1, 0;
  }
  cout << a[px][py];
  return 0;
}
