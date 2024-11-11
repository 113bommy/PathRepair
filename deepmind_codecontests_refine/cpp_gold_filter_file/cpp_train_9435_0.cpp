#include <bits/stdc++.h>
using namespace std;
int main() {
  cout.precision(20);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1)
    cout << "YES" << endl << 1;
  else if (n == 1 && m == 2)
    cout << "NO";
  else if (n == 1 && m == 3)
    cout << "NO";
  else if (n == 1 && m == 4)
    cout << "YES\n2 4 1 3";
  else if (n == 1 && m >= 5) {
    cout << "YES" << endl;
    for (int i = 1; i <= m; i += 2) cout << i << " ";
    for (int i = 2; i <= m; i += 2) cout << i << " ";
  } else if (n == 2 && m == 1)
    cout << "NO";
  else if (n == 3 && m == 1)
    cout << "NO";
  else if (n == 4 && m == 1)
    cout << "YES\n2\n4\n1\n3";
  else if (n >= 5 && m == 1) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i += 2) cout << i << endl;
    for (int i = 2; i <= n; i += 2) cout << i << endl;
  } else if (n == 2 && m == 2)
    cout << "NO";
  else if (n == 2 && m == 3)
    cout << "NO";
  else if (n == 3 && m == 2)
    cout << "NO";
  else if (n == 3 && m == 3) {
    cout << "YES\n1 6 8" << endl << "9 2 4" << endl << "5 7 3";
  } else {
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        v[i][j] = i * m + j + 1;
      }
    }
    vector<vector<int>> ans(v);
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j++) {
        v[i][j] = ans[i][(j + 1 + (n < m)) % m];
      }
    }
    ans = v;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j += 2) {
        v[i][j] = ans[(i + 1 + (n >= m)) % n][j];
      }
    }
    cout << "YES" << endl;
    for (auto i : v) {
      for (auto j : i) cout << j << " ";
      cout << endl;
    }
  }
}
