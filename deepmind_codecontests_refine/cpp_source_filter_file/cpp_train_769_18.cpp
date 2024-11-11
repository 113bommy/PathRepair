#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
void solve() {
  int n;
  cin >> n;
  int v[n];
  for (int i = 0; i < n; i++) cin >> v[i];
  if (n == 1) {
    cout << 0;
    return;
  }
  sort(v, v + n);
  int x = n / 2, y = n - 1;
  int minus = 0;
  while (x >= 0 && y > x) {
    if (2 * v[x] <= v[y]) {
      y--;
      minus++;
    }
    x--;
  }
  cout << n - minus;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
