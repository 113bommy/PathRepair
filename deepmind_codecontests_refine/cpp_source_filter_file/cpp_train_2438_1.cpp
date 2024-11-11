#include <bits/stdc++.h>
using namespace std;
int n, m[102], k, a[102][102], b[102][102];
bool p[102];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
    for (int j = 0; j < m[i]; ++j) {
      cin >> a[i][j];
      ++b[i][a[i][j]];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      for (int k = 0; k < m[i]; ++k) {
        if (b[j][a[i][k]]) {
          --b[j][a[i][k]];
        }
      }
      bool bo = 0;
      for (int k = 0; k < m[j]; ++k) {
        if (b[j][a[j][k]]) bo = 1;
      }
      for (int k = 0; k < m[j]; ++k) {
        b[j][a[j][k]] = 0;
      }
      for (int k = 0; k < m[j]; ++k) {
        ++b[j][a[j][k]];
      }
      p[i] = bo;
      if (!bo) break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (p[i]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
