#include <bits/stdc++.h>
using namespace std;
const int N = 105;
long long col[N], row[N], a[N], b[N];
int w[N][N];
int k;
bool solve(int n, int m, int mink) {
  k = 0;
  for (int j = 2; j <= m; j++) {
    col[j] = w[1][j] - w[1][1];
    if (k > 0 && col[j] < 0) col[j] += k;
    for (int i = 2; i <= n; i++) {
      long long tmp = w[i][j] - w[i][1];
      if (k > 0 && tmp < 0) tmp += k;
      if (tmp == col[j]) continue;
      if (k == 0) {
        if (tmp * col[j] >= 0) return false;
        k = abs(tmp - col[j]);
        if (k < mink) return false;
        if (col[j] < 0) col[j] += k;
      } else
        return false;
    }
  }
  for (int i = 2; i <= n; i++) {
    row[i] = w[i][1] - w[1][1];
    if (k > 0 && row[i] < 0) row[i] += k;
    for (int j = 2; j <= m; j++) {
      long long tmp = w[i][j] - w[1][j];
      if (k > 0 && tmp < 0) tmp += k;
      if (tmp == row[i]) continue;
      if (k == 0) {
        if (tmp * row[i] >= 0) return false;
        k = abs(tmp - row[i]);
        if (k < mink) return false;
        if (row[i] < 0) row[i] += k;
      } else
        return false;
    }
  }
  if (k == 0) k = mink;
  a[1] = 0;
  for (int i = 1; i <= m; i++) b[i] = w[1][i];
  for (int i = 2; i <= n; i++) a[i] = (row[i] + k) % k;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int mink = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> w[i][j];
      mink = max(mink, w[i][j] + 1);
    }
  if (!solve(n, m, mink)) {
    cout << "NO";
  } else {
    cout << "YES\n" << k << '\n';
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= m; i++) cout << b[i] << ' ';
  }
  return 0;
}
