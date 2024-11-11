#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  char c[n];
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(c, c + n);
  for (int u : c) cout << u;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  while (T--) {
    solve();
  }
}
