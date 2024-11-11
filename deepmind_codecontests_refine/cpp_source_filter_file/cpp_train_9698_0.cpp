#include <bits/stdc++.h>
using namespace std;
bool comp(string a, string b) { return a.size() < b.size(); }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  long long b[n];
  long long g[m];
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> g[i];
  }
  sort(b, b + n);
  sort(g, g + m);
  if (b[n - 1] > g[m - 1]) {
    cout << "-1\n";
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < n - 2; ++i) {
    ans += (b[i] * m);
  }
  if (g[0] == b[n - 1]) {
    ans += (b[n - 2] * m);
    for (int i = 0; i < m; ++i) {
      ans += g[i];
    }
  } else {
    ans += (b[n - 2] * (m - 1));
    ans += g[m - 1];
    ans += b[n - 1];
    for (int i = 0; i < m - 1; ++i) {
      ans += g[i];
    }
  }
  cout << ans << endl;
  return 0;
}
