#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long r[2][N], l[2][N], a[N], n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  long long mx = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] < 2) continue;
    l[0][i] = l[0][i - 1] + a[i - 1] - (a[i - 1] & 1);
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] < 2) continue;
    r[0][i] = r[0][i + 1] + a[i] - (a[i] & 1);
  }
  for (int i = 1; i <= n; i++) {
    l[1][i] = l[1][i - 1] + max(0ll, a[i - 1] - (a[i - 1] % 2 == 0));
    l[1][i] = max(l[1][i], l[0][i]);
  }
  for (int i = n; i >= 1; i--) {
    r[1][i] = r[1][i + 1] + max(0ll, a[i] - (a[i] % 2 == 0));
    r[1][i] = max(r[1][i], r[0][i]);
  }
  for (int i = 1; i <= n; i++) {
    mx = max(mx, max(r[0][i] + l[1][i], r[1][i] + l[0][i]));
  }
  cout << mx << endl;
  return 0;
}
