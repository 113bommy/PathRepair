#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  int n, m, q, i, j, k, mat[505][505], sd[505], l[505], inv[] = {0, 1, 3, 2, 4};
  string s, str;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> s;
    for (j = 0; j < m; j++) mat[i][j] = s[j] - 'a';
  }
  int b = 0;
  for (i = 0; i < m; i++) {
    for (j = b; j < n; j++)
      if (mat[j][i]) {
        l[b] = i;
        for (k = i; k < m; k++) {
          swap(mat[b][k], mat[j][k]);
        }
        break;
      }
    if (j == n) continue;
    for (k = m - 1; k >= i; k--) mat[b][k] = (mat[b][k] * inv[mat[b][i]]) % mod;
    for (j = b + 1; j < n; j++) {
      for (k = m - 1; k >= i; k--) {
        mat[j][k] = (mat[j][k] - mat[b][k] * mat[j][i] + 50) % 5;
      }
    }
    b++;
  }
  long long ans = 1;
  for (i = 0; i < n - b; i++) {
    ans = (ans * 5ll) % mod;
  }
  cin >> q;
  while (q--) {
    cin >> str;
    for (i = 0; i < m; i++) sd[i] = str[i] - 'a';
    for (i = 0; i < b; i++) {
      for (j = m - 1; j >= l[i]; j--)
        sd[j] = (sd[j] - sd[l[i]] * mat[i][j] + 50) % 5;
    }
    bool ok = true;
    for (i = 0; i < m; i++) {
      ok = ok & !sd[i];
    }
    if (ok)
      cout << ans << endl;
    else
      cout << 0 << endl;
  }
}
