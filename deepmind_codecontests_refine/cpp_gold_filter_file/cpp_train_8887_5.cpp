#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[510], y[510], d[510];
int a[510];
int ans[510];
bool used[510];
bool can(int p) {
  int i, j;
  for ((i) = 0; (i) < (int)(m); (i)++) used[i] = false;
  for ((i) = 0; (i) < (int)(n); (i)++) ans[i] = -1;
  for ((i) = 0; (i) < (int)(n / 2); (i)++) {
    int sum = d[i * 2 + p] + d[i * 2 + p + 1];
    for ((j) = 0; (j) < (int)(m); (j)++)
      if (a[j] == sum && !used[j]) {
        ans[(i * 2 + p + 1) % n] = j + 1;
        used[j] = true;
        break;
      }
    if (j == m) return false;
  }
  cout << "YES" << endl;
  for ((i) = 0; (i) < (int)(n); (i)++) {
    cout << ans[i];
    if (i == n - 1)
      cout << endl;
    else
      cout << ' ';
  }
  return true;
}
int main(void) {
  int i, j;
  cin >> n >> m;
  for ((i) = 0; (i) < (int)(n); (i)++) cin >> x[i] >> y[i];
  for ((i) = 0; (i) < (int)(m); (i)++) cin >> a[i];
  x[n] = x[0];
  y[n] = y[0];
  for ((i) = 0; (i) < (int)(n); (i)++)
    d[i] = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
  d[n] = d[0];
  if (!can(0) && !can(1)) cout << "NO" << endl;
  return 0;
}
