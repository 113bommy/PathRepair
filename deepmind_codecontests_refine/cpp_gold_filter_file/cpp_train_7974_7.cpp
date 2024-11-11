#include <bits/stdc++.h>
using namespace std;
int r[55], col[55];
long long s, arr[70];
int main() {
  int n, m, a;
  cin >> n >> m;
  arr[0] = 1;
  for (int i = 1; i < 70; i++) {
    arr[i] = arr[i - 1] * 2;
  }
  for (int i = 0; i < n * m; i++) {
    cin >> a;
    r[i / m] = r[i / m] + a;
    col[i % m] = col[i % m] + a;
  }
  for (int i = 0; i < m; i++) {
    s = s + arr[col[i]] + arr[n - col[i]];
  }
  for (int i = 0; i < n; i++) {
    s = s + arr[r[i]] + arr[m - r[i]];
  }
  cout << s - n * m - 2 * (n + m);
  return 0;
}
