#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, i, j, maxy = 1, k, sum = 0, h = 0;
  cin >> n >> m;
  vector<long long> b(m);
  char a[n][m];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> a[i][j];
  for (i = 0; i < m; i++) cin >> b[i];
  map<char, long long> mp;
  for (j = 0; j < m; j++) {
    for (i = 0; i < n; i++) {
      k = ++mp[a[i][j]];
      maxy = max(maxy, k);
    }
    sum += maxy * b[h++];
    maxy = 1;
    mp.clear();
  }
  cout << sum;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
