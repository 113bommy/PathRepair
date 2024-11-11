#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 5;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m, c, cost = 0;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    long long temp = N;
    for (long long j = 0; j < m; j++) {
      cin >> c;
      temp = min(temp, c);
    }
    cost = max(temp, cost);
  }
  cout << cost << "\n";
  return 0;
}
