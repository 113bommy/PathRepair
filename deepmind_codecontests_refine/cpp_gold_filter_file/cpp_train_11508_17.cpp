#include <bits/stdc++.h>
using namespace std;
int n, d, k, h;
pair<int, int> a[100004];
void xly() {
  if (h == 1 && n > 2) {
    cout << -1;
    exit(0);
  }
  for (int i = h + 2; i <= n; i++) a[++k] = pair<int, int>(h, i);
  if (k != n - 1) {
    cout << -1;
    exit(0);
  }
  for (int i = 1; i < n; i++) cout << a[i].first << ' ' << a[i].second << '\n';
  exit(0);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> d >> h;
  if (d > h * 2) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= h; i++) {
    a[++k] = pair<int, int>(i, i + 1);
  }
  if (h == d) xly();
  int i = h + 2;
  for (int j = 1; j <= d - h; j++) {
    if (i > n) {
      cout << -1;
      return 0;
    }
    if (i == h + 2)
      a[++k] = pair<int, int>(1, i);
    else
      a[++k] = pair<int, int>(i - 1, i);
    i++;
  }
  for (; i <= n; i++) a[++k] = pair<int, int>(1, i);
  if (k != n - 1) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i < n; i++) cout << a[i].first << ' ' << a[i].second << '\n';
}
