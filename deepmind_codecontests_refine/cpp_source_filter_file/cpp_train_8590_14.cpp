#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
long long INF = 1e18;
int n, d, h;
int solve() {
  cin >> n >> d >> h;
  int k = d - h;
  if (k > h || n > 2 && h == 1 && k == 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < h; i++) cout << i + 1 << ' ' << i + 1 + 1 << endl;
  if (k > 0) {
    cout << 0 + 1 << ' ' << h + 1 + 1 << endl;
    for (int i = h + 1; i < d; i++) cout << i + 1 << ' ' << i + 1 + 1 << endl;
  }
  for (int i = d + 1; i < n; i++) cout << 1 + 1 << ' ' << i + 1 << endl;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
