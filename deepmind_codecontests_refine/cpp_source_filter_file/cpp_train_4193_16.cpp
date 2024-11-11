#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
long long g[200005];
long long n, k;
void solve() {
  long long k, s, e, a, b, mini = INT_MAX;
  long long c = 0;
  long long n, m;
  cin >> n >> m;
  char ar[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> ar[i][j];
    }
  }
  for (long long i = 0; i < m - 1; i++) {
    if (ar[n - 1][i] == 'D') c++;
  }
  for (long long i = 0; i < m - 1; i++) {
    if (ar[i][m - 1] == 'R') c++;
  }
  cout << c;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test;
  cin >> test;
  long long i;
  while (test--) {
    solve();
    cout << "\n";
  }
}
