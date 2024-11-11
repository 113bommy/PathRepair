#include <bits/stdc++.h>
using namespace std;
int main() {
  int BIG = 1000000;
  int n, k;
  cin >> n >> k;
  string s;
  int a[2][n + 2 * k];
  int x[2][n + 2 * k];
  for (int i = 0; i < 2; i++) {
    cin >> s;
    for (int j = k; j < n + k; j++) {
      if (s[j - k] == '-')
        a[i][j] = 0;
      else
        a[i][j] = 1;
    }
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < k; j++) {
      a[i][j] = 1;
    }
  for (int i = 0; i < 2; i++)
    for (int j = n + k; j < n + 2 * k; j++) {
      a[i][j] = 0;
    }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n + 2 * k; j++) {
      x[i][j] = BIG;
    }
  }
  x[0][k] = 0;
  vector<int> v[2][n + 1];
  v[0][0].push_back(k);
  for (int T = 1; T <= n; T++) {
    for (int i = 0; i < 2; i++) {
      for (int J = 0; J < v[(i) % 2][T - 1].size(); J++) {
        int j = v[(i) % 2][T - 1][J];
        if (x[i][j - 1] == BIG && (j - 1 - k) >= T) {
          x[i][j - 1] = (a[i][j - 1] == 1) ? BIG : T;
          if (!(a[i][j - 1] == 1)) v[(i) % 2][T].push_back(j - 1);
        }
        if (x[i][j + 1] == BIG) {
          x[i][j + 1] = (a[i][j + 1] == 1) ? BIG : T;
          if (!(a[i][j + 1] == 1)) v[(i) % 2][T].push_back(j + 1);
        }
        if (x[(i + 1) % 2][j + k] == BIG) {
          x[(i + 1) % 2][j + k] = (a[(i + 1) % 2][j + k] == 1) ? BIG : T;
          if (!(a[(i + 1) % 2][j + k] == 1)) v[(i + 1) % 2][T].push_back(j + k);
        }
      }
    }
  }
  for (int i = 0; i < 2; i++)
    for (int j = n + k; j < n + 2 * k; j++) {
      if (x[i][j] <= n) {
        cout << "YES";
        return 0;
      }
    }
  cout << "NO";
}
