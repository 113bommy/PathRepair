#include <bits/stdc++.h>
using namespace std;
int n;
void input();
void solve() {
  for (int i = 0; i < n; i++) {
    if ((n - i) * 4 - 4 <= n) {
      cout << 8;
      continue;
    }
    cout << 9;
  }
  cout << "\n";
}
void Clear() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    input();
    solve();
    Clear();
  }
}
void input() { cin >> n; }
