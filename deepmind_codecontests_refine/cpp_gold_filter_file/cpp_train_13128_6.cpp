#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 10;
const int inf = 1e9 + 10;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<long long> len_a(n, INF);
  for (int i = 0; i < n; i++) {
    long long res = 0;
    for (int j = i; j < n; j++) {
      res += a[j];
      len_a[j - i] = min(len_a[j - i], res);
    }
  }
  vector<long long> len_b(m, INF);
  for (int i = 0; i < m; i++) {
    long long res = 0;
    for (int j = i; j < m; j++) {
      res += b[j];
      len_b[j - i] = min(len_b[j - i], res);
    }
  }
  long long x;
  cin >> x;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (len_a[i] * len_b[j] <= x) {
        ans = max(ans, 1LL * (i + 1) * (j + 1));
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
