#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int n, m;
void solve(int i, string var) {
  int it2 = 0;
  for (int j = 0; j < m; j++) {
    if (v[i][j] == '.') {
      if (j + 1 < m) {
        if (v[i][j + 1] == '.') {
          v[i][j] = v[i][j + 1] = var[it2];
          j++;
          it2 = (it2 + 1) % 3;
        } else if (i + 1 < n) {
          if (v[i + 1][j] == '.') {
            v[i][j] = v[i + 1][j] = var[it2];
            it2 = (it2 + 1) % 3;
          }
        }
      } else {
        if (i + 1 < n) {
          if (v[i + 1][j] == '.') {
            v[i][j] = v[i + 1][j] = var[it2];
            it2 = (it2 + 1) % 3;
          }
        }
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  v.resize(n);
  for (int i = (0), _i = (n); i < _i; ++i) cin >> v[i];
  bool ok = true;
  for (int i = (0), _i = (n); i < _i; ++i)
    for (int j = (0), _j = (m); j < _j; ++j) {
      if (v[i][j] != '.') continue;
      bool flag = true;
      if (i - 1 >= 0) {
        if (v[i - 1][j] == '.') flag = false;
      }
      if (i + 1 < n) {
        if (v[i + 1][j] == '.') flag = false;
      }
      if (j - 1 >= 0) {
        if (v[i][j - 1] == '.') flag = false;
      }
      if (i + 1 < m) {
        if (v[i][j + 1] == '.') flag = false;
      }
      if (flag) ok = false;
    }
  if (ok) {
    int it = 0;
    for (int i = (0), _i = (n); i < _i; ++i) {
      int it2 = 0;
      if (it == 0) {
        solve(i, "012");
      } else if (it == 1) {
        solve(i, "345");
      } else {
        solve(i, "678");
      }
      it = (it + 1) % 3;
    }
    for (int i = (0), _i = (n); i < _i; ++i)
      for (int j = (0), _j = (m); j < _j; ++j) {
        if (v[i][j] != '.') continue;
        if (i - 1 >= 0) {
          if (v[i - 1][j] != '.' && v[i - 1][j] != '#') {
            v[i][j] = v[i - 1][j];
            continue;
          }
        }
        if (i + 1 < n) {
          if (v[i + 1][j] != '.' && v[i + 1][j] != '#') {
            v[i][j] = v[i + 1][j];
            continue;
          }
        }
        if (j - 1 >= 0) {
          if (v[i][j - 1] != '.' && v[i][j - 1] != '#') {
            v[i][j] = v[i][j - 1];
            continue;
          }
        }
        if (i + 1 < m) {
          if (v[i][j + 1] != '.' && v[i][j + 1] != '#') {
            v[i][j] = v[i][j + 1];
            continue;
          }
        }
      }
    for (int i = (0), _i = (n); i < _i; ++i) cout << v[i] << endl;
  } else
    printf("-1\n");
}
