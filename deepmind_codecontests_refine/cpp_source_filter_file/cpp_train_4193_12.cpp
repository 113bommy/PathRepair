#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long result = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      char o;
      cin >> o;
      if (i == n && o == 'D') result++;
      if (i == m && o == 'R') result++;
      if (o == 'C') continue;
    }
  }
  cout << result << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
