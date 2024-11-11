#include <bits/stdc++.h>
using namespace std;
inline void minimize(int &x, int y) { x = min(x, y); }
inline void maximize(int &x, int y) { x = max(x, y); }
const int N = 10000 + 1067, oo = 1e9 + 7;
int n, t, m, k;
int a[N], f[N][13];
int get(int x, int y) {
  int res = oo;
  for (int j = 12; j >= 0; j--) {
    if (x + (1 << j) - 1 <= y) res = min(res, f[x][j]), x = x + (1 << j);
  }
  return res;
}
int main() {
  cin >> t;
  for (int test = 1; test <= t; test++) {
    cin >> n >> m >> k;
    k = min(k, m - 1);
    m = n - m + 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= 12; j++) f[i][j] = oo;
    for (int i = 1; i <= n - m + 1; i++) {
      f[i][0] = max(a[i], a[i + m - 1]);
    }
    for (int j = 1; j <= 12; j++)
      for (int i = 1; i <= n - m + 1; i++)
        f[i][j] = min(f[i][j - 1], f[min(n, i + (1 << (j - 1)))][j - 1]);
    int res = 0;
    for (int i = 0; i <= k; i++) {
      res = max(res, get(i + 1, n - (k - i) - m + 1));
    }
    cout << res << endl;
  }
}
