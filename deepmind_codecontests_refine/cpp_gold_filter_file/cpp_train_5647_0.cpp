#include <bits/stdc++.h>
using namespace std;
void fileio() {}
void solve() {
  int n, m;
  cin >> n >> m;
  char ar[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if ((i + j) & 1)
        ar[i][j] = 'W';
      else
        ar[i][j] = 'B';
    }
  }
  if (((n * m) & 1) == 0) ar[0][1] = 'B';
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cout << ar[i][j];
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fileio();
  long long tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
