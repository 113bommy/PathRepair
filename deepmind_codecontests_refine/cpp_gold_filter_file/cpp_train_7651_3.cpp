#include <bits/stdc++.h>
using namespace std;
const int maxn = 31, maxk = 51;
int ar[maxn][maxn][maxk];
int br(int n, int m, int k) {
  if (n * m == k || k == 0) return 0;
  if (ar[n][m][k] != -1) return ar[n][m][k];
  if (n * m < k) return 2e5;
  ar[n][m][k] = INT_MAX;
  for (int(i) = (1); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (k + 1); (j)++)
      ar[n][m][k] =
          min(ar[n][m][k], (m * m) + br(n - i, m, k - j) + br(i, m, j));
  for (int(i) = (1); (i) < (m); (i)++)
    for (int(j) = (0); (j) < (k + 1); (j)++)
      ar[n][m][k] =
          min(ar[n][m][k], (n * n) + br(n, m - i, k - j) + br(n, i, j));
  return ar[n][m][k];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  for (int(i) = (0); (i) < (maxn); (i)++)
    for (int(j) = (0); (j) < (maxn); (j)++)
      for (int(k) = (0); (k) < (maxk); (k)++) ar[i][j][k] = -1;
  int q;
  cin >> q;
  for (int(qq) = (0); (qq) < (q); (qq)++) {
    int n, m, k;
    cin >> n >> m >> k;
    cout << br(n, m, k) << '\n';
  }
}
