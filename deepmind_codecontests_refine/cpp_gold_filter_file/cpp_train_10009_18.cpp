#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;
const ld EPS = 1e-9;
inline int cmp(ld first, ld second = 0, ld tol = EPS) {
  return (first <= second + tol) ? (first + tol < second) ? -1 : 0 : 1;
}
const int MOD = 1;
inline int mod(ll first, int m = MOD) { return (int)(((first % m) + m) % m); }
const int N = 1010;
int n, m;
int mat[N][N];
int maxR[N], maxC[N];
int rows[N][N], cols[N][N];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &mat[i][j]);
  for (int i = 1; i <= n; i++) {
    vector<int> vec;
    for (int j = 1; j <= m; j++) vec.push_back(mat[i][j]);
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    maxR[i] = ((int)(vec).size());
    for (int j = 1; j <= m; j++) {
      int v = mat[i][j];
      int p = lower_bound(vec.begin(), vec.end(), v) - vec.begin();
      rows[i][j] = p + 1;
    }
  }
  for (int j = 1; j <= m; j++) {
    vector<int> vec;
    for (int i = 1; i <= n; i++) vec.push_back(mat[i][j]);
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    maxC[j] = ((int)(vec).size());
    for (int i = 1; i <= n; i++) {
      int v = mat[i][j];
      int p = lower_bound(vec.begin(), vec.end(), v) - vec.begin();
      cols[i][j] = p + 1;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int maxi = max(rows[i][j], cols[i][j]);
      printf("%d",
             max((maxi - rows[i][j]) + maxR[i], (maxi - cols[i][j]) + maxC[j]));
      if (j == m)
        putchar('\n');
      else
        putchar(' ');
    }
  return 0;
}
