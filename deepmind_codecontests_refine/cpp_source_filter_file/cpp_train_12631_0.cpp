#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long double PI = 3.141592653589793;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, a;
  cin >> n >> m;
  vector<int> v[n];
  for (int i = 0; i < n; i++) {
    v[i] = vector<int>(m);
    for (int j = 0; j < m; j++) cin >> v[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((j + 1 < m && v[i][j] != v[i][j + 1]) ||
          (i - 1 >= 0 && v[i - 1][j] == v[i][j]) ||
          (i + 1 < n && v[i + 1][j] == v[i][j])) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  cerr << "Time Lapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}
