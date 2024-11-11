#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
long double f[maxn][maxn];
bitset<maxn> A, B;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    A[a] = 1;
    B[b] = 1;
  }
  int k = n - A.count(), l = n - B.count();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!i && !j) continue;
      f[i][j] = n * n;
      if (j) f[i][j] += j * (n - i) * f[i][j - 1];
      if (i) f[i][j] += i * (n - j) * f[i - 1][j];
      if (i && j) f[i][j] += i * j * f[i - 1][j - 1];
      f[i][j] /= (i + j) * n - i * j;
    }
  }
  cout << setprecision(20) << f[k][l];
}
