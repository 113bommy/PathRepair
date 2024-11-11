#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int mat[N][N], ind[N];
int mult(int a, int b, int m) { return int(1ll * a * b % m); }
int sub(int a, int b, int m) { return (a - b + m) % m; }
int rev(int x, int m) {
  int y = 1;
  while (y % x) y += m;
  return y / x;
}
void gauss(int n, int m, int MOD) {
  int k = 0, i;
  for (int j = 0; j < m; j++) {
    for (i = k; i < n; i++) {
      if (mat[i][j] != 0) break;
    }
    if (i == n) continue;
    swap(mat[k], mat[i]);
    int x = rev(mat[k][j], MOD);
    for (int h = j; h < m; h++) mat[k][h] = mult(mat[k][h], x, MOD);
    for (i = k + 1; i < n; i++) {
      for (int h = m - 1; h >= j; h--)
        if (mat[i][h])
          mat[i][h] = sub(mat[i][h], mult(mat[k][h], mat[i][j], MOD), MOD);
    }
    ind[j] = k++;
  }
}
long long pwr(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = (r * a) % 1000000007;
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return r;
}
int main() {
  int n, m, i;
  cin >> n >> m;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) mat[i][j] = int(s[j] - 'a');
  }
  for (int i = 0; i < m; i++) ind[i] = -1;
  gauss(n, m, 5);
  int r = -1;
  for (int i = 0; i < m; i++) r = max(r, ind[i]);
  if (r != -1) r = pwr(5, n - r - 1);
  int c[m];
  int q;
  cin >> q;
  while (q--) {
    cin >> s;
    for (int i = 0; i < m; i++) c[i] = int(s[i] - 'a');
    for (i = 0; i < m; i++) {
      if (c[i] == 0) continue;
      int x = -1;
      if (ind[i] == -1) {
        i = -1;
        break;
      }
      for (int j = m - 1; j >= i; j--)
        c[j] = sub(c[j], mult(mat[ind[i]][j], c[i], 5), 5);
    }
    if (i == -1)
      cout << "0\n";
    else
      cout << r << "\n";
  }
  return 0;
}
