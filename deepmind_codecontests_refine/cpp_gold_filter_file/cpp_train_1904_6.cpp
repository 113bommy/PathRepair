#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool chmin(T1 &a, T2 b) {
  if (a <= b) return 0;
  a = b;
  return 1;
}
template <typename T1, typename T2>
bool chmax(T1 &a, T2 b) {
  if (a >= b) return 0;
  a = b;
  return 1;
}
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long double eps = 1e-9;
long double pi = acos(-1);
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20);
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum == m) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
