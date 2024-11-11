#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x - 1] = i;
    }
    long long prev = -1, ans = 0;
    for (int i = 0; i < m; i++) {
      int b;
      cin >> b;
      int pos = a[b - 1];
      if (pos < prev)
        ans++;
      else {
        ans += 2 * (pos - i) + 1;
        prev = pos;
      }
    }
    cout << ans << "\n";
  }
}
