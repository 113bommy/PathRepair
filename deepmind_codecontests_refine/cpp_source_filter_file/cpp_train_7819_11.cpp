#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 10;
const int inf = 1e9 + 10;
const int N = 1e6 + 10;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int top = -1;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    int mx = -1, m;
    cin >> m;
    for (int q = 0; q < m; q++) {
      int x;
      cin >> x;
      mx = max(mx, x);
    }
    a[i] = make_pair(mx, m);
    top = max(top, mx);
  }
  long long ans = 0;
  for (auto i : a) ans = ans + (top - i.first) * i.second;
  cout << ans << "\n";
  return 0;
}
