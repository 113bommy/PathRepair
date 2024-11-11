#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 1e9 + 10;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1), b(m + 1);
    vector<bool> used(2 * n + 5, false);
    for (int i = 1; i <= m; i++) {
      cin >> a[i] >> b[i];
      used[a[i]] = 1;
      used[b[i]] = 1;
    }
    vector<int> r;
    for (int i = 1; i <= 2 * n; i++) {
      if (!used[i]) r.push_back(i), used[i] = 1;
    }
    int cnt = r.size();
    for (int i = 0; i < cnt / 2; i++) {
      a.push_back(r[i]);
      b.push_back(r[i + cnt / 2]);
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] > b[i]) swap(a[i], b[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i] < a[j] && b[i] < b[j] && b[i] > a[j]) ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
