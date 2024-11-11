#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, x, i, j, k, temp = 0, m;
  cin >> n >> m;
  vector<string> s(n);
  for (i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (i = 0; i < m - 1; ++i) {
    if (s[n - 1][i] == 'D') temp++;
  }
  for (j = 0; j < n; ++j)
    if (s[j][m - 1] == 'R') temp++;
  cout << temp << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
