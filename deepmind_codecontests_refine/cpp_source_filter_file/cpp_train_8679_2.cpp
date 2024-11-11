#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  bool b[3001] = {0};
  int n, t;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t, b[t] = 1;
  for (int i = 1; i <= 3000; i++)
    if (!b[i]) {
      cout << i << '\n';
      return;
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test = 1;
  while (test--) solve();
  return 0;
}
