#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
void solve() {
  long long n, m, x = 0, y = 0;
  cin >> n >> m;
  int a[n][m];
  vector<int> b(n, 0);
  vector<int> c(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      b[i] += a[i][j];
      c[j] += a[i][j];
    }
  }
  for (int i = 0; i < n; i++)
    if (b[i] == 0) x++;
  for (int i = 0; i < m; i++)
    if (c[i] == 0) y++;
  x = min(x, y);
  if (x % 2) {
    cout << "Ashish";
  } else {
    cout << "Vivek";
  }
  cout << endl;
}
int main() {
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
