#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  if (n == m) {
    cout << n + m - 1 << endl;
    for (int i = 1; i <= n; i++) cout << 1 << " " << i << endl;
    for (int i = 2; i <= n; i++) cout << i << " " << 1 << endl;
    return;
  } else if (n > m) {
    cout << n + m - 1 << endl;
    for (int i = 1; i <= n; i++) cout << i << " " << 1 << endl;
    for (int i = 2; i <= m; i++) cout << n << " " << i << endl;
    return;
  } else if (m > n) {
    cout << m + n - 1 << endl;
    for (int i = 1; i <= m; i++) cout << 1 << " " << i << endl;
    for (int i = 2; i <= n; i++) cout << i << " " << 1 << endl;
    return;
  }
  return;
}
int main() {
  solve();
  return 0;
}
