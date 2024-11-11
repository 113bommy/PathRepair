#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x;
  cin >> n >> x;
  bool used[105] = {0};
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    used[v] = 1;
  }
  for (int i = 1; i < 105; ++i) {
    if (x > 0 && !used[i]) {
      used[i] = 1;
      --x;
    }
  }
  for (int i = 2; i <= 105; ++i) {
    if (!used[i]) {
      cout << i - 1 << "\n";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
