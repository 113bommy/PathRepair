#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& it : a) cin >> it;
    for (int& it : b) cin >> it;
    vector<bool> used(n + 1, false);
    long long ans = 0;
    for (int i = 0, l = 0; i < m; i++) {
      ++ans;
      if (used[b[i]]) continue;
      while (!used[b[i]]) {
        used[a[l]] = true;
        ++l;
      }
      ans += 2 * (l - i - 1);
    }
    cout << ans << "\n";
  }
  return 0;
}
