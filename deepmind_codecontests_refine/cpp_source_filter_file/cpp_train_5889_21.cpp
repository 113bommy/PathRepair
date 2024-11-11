#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x;
  cin >> n >> m;
  vector<vector<bool> > v(n, vector<bool>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> x;
      v[i][j] = x;
    }
  vector<vector<int> > a(n, vector<int>(m, 0));
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!v[i][j] && flag) a[i][j]++;
      if (v[i][j]) flag = 1;
    }
    flag = 0;
  }
  flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (!v[i][j] && flag) a[i][j]++;
      if (v[i][j]) flag = 1;
    }
    flag = 0;
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (!v[i][j] && flag) a[i][j]++;
      if (v[i][j]) flag = 1;
    }
    flag = 0;
  }
  for (int j = 0; j < m; j++) {
    for (int i = n - 1; i >= 0; i--) {
      if (!v[i][j] && flag) a[i][j]++;
      if (v[i][j]) flag = 1;
    }
    flag = 0;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ans += a[i][j];
  cout << ans;
  return 0;
}
