#include <bits/stdc++.h>
using namespace std;
vector<int> inv = {0, 1, 3, 2, 4};
vector<vector<int>> gauss(vector<vector<int>> a) {
  int n = a.size(), m = a[0].size();
  int row = 0;
  vector<vector<int>> basis;
  vector<bool> colm(m, 0);
  for (int k = 0; k < m; k++) {
    for (int i = row; i < n; i++) {
      if (a[i][k]) {
        swap(a[i], a[row]);
        break;
      }
    }
    if (row < n && (a[row][k] > 0)) {
      int mul = inv[a[row][k]];
      for (int j = k; j < m; j++) a[row][j] = a[row][j] * mul % 5;
      basis.push_back(a[row]);
      colm[k] = 1;
      for (int i = row + 1; i < n; i++) {
        int t = a[i][k];
        for (int j = k; j < m; j++)
          a[i][j] = (125 + a[i][j] - t * a[row][j]) % 5;
      }
      row++;
    }
  }
  return basis;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat;
  for (int i = 0; i < n; i++) {
    vector<int> a(m);
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[j] = s[j] - 'a';
    }
    mat.push_back(a);
  }
  vector<vector<int>> basis = gauss(mat);
  int free = n - basis.size();
  int ans = 1;
  int mod = 1e9 + 7;
  while (free--) {
    ans = 1ll * ans * 5 % mod;
  }
  int q;
  cin >> q;
  while (q--) {
    vector<int> b(m);
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) b[j] = s[j] - 'a';
    for (auto v : basis) {
      int idx = -1;
      for (int i = 0; i < m; i++) {
        if (v[i] > 0) {
          idx = i;
          break;
        }
      }
      int t = b[idx];
      for (int i = 0; i < m; i++) {
        b[i] = (125 + b[i] - t * v[i]) % 5;
      }
    }
    bool allZero = true;
    for (int x : b) {
      if (x) allZero = false;
    }
    if (allZero)
      cout << ans << endl;
    else
      cout << "0" << endl;
  }
  return 0;
}
