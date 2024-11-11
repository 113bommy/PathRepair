#include <bits/stdc++.h>
using namespace std;
inline int fastMin(int x, int y) {
  return (((y - x) >> (32 - 1)) & (x ^ y)) ^ x;
}
int A[2][22][22];
int a[22][22];
int fx[22], fy[22];
int x[22], y[22];
int t[22], s[22];
int n, p, q;
const int INF = 1e9;
inline int calc(int S) {
  for (int i = 0; i < (int)(n); i++) {
    fx[i] = INF;
    fy[i] = 0;
    x[i] = -1;
    y[i] = -1;
  }
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) a[i][j] = A[(S >> i) & 1][i][j];
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(n); j++) fx[i] = max(fx[i], a[i][j]);
  }
  for (int i = 0; i < n;) {
    for (int j = 0; j < (int)(n); j++) {
      t[j] = -1;
      s[j] = i;
    }
    s[n] = i;
    for (p = q = 0; p <= q && x[i] < 0; p++) {
      for (int k = s[p], j = 0; j < n && x[i] < 0; j++) {
        if (fx[k] + fy[j] == a[k][j] && t[j] < 0) {
          s[++q] = y[j], t[j] = k;
          if (s[q] < 0) {
            for (p = j; p >= 0; j = p) {
              y[j] = k = t[j], p = x[k], x[k] = j;
            }
          }
        }
      }
    }
    if (x[i] < 0) {
      int d = INF;
      for (int k = 0; k <= q; k++) {
        for (int j = 0; j < n; j++) {
          if (t[j] < 0) d = fastMin(d, fx[s[k]] + fy[j] - a[s[k]][j]);
        }
      }
      for (int j = 0; j < (int)(n); j++) fy[j] += (t[j] < 0 ? 0 : d);
      for (int k = 0; k <= q; k++) fx[s[k]] -= d;
    } else {
      i++;
    }
  }
  int res = 0;
  for (int i = 0; i < (int)(n); i++) res += a[i][x[i]];
  return res;
}
int main() {
  cin >> n;
  for (int k = 0; k < (int)(2); k++)
    for (int i = 0; i < (int)(n); i++)
      for (int j = 0; j < (int)(n); j++) cin >> A[k][i][j];
  int U = (1 << n);
  vector<int> AAA;
  for (int S = 0; S < U; S++) {
    if (__builtin_popcount(S) * 2 != n) continue;
    AAA.push_back(S);
  }
  srand(364);
  random_shuffle((AAA).begin(), (AAA).end());
  int start = clock();
  int ans = 0;
  for (int i = 0; i < int((AAA).size()); i++) {
    if ((i & 7) == 0)
      if (clock() - start >= 1970) break;
    ans = max(ans, calc(AAA[i]));
  }
  cout << ans << endl;
}
