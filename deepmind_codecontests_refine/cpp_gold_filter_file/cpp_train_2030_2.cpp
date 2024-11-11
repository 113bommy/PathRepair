#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<long long> X(n);
  for (int i = 0; i < n; ++i) cin >> X[i];
  if (n > m) {
    vector<int> count(m, 0);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += X[i];
      count[sum % m]++;
      if (count[sum % m] == 2) {
        cout << "YES\n";
        return 0;
      }
    }
    cout << "NO\n";
  } else {
    vector<vector<bool> > possible(n + 1, vector<bool>(m, false));
    possible[0][X[0] % m] = true;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        possible[i][X[i] % m] = true;
        if (possible[i - 1][j]) {
          possible[i][j] = true;
          possible[i][(j + X[i]) % m] = true;
        }
      }
    }
    if (possible[n - 1][0])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
