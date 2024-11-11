#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, i, j;
long long a[105], k;
vector<vector<long long> > b, id;
vector<vector<long long> > mul(vector<vector<long long> > x,
                               vector<vector<long long> > y) {
  vector<vector<long long> > z;
  for (int ii = 0; ii < x.size(); ii++) {
    vector<long long> tmp;
    for (int jj = 0; jj < x.size(); jj++) tmp.push_back(0);
    z.push_back(tmp);
  }
  for (int ii = 0; ii < x.size(); ii++) {
    for (int jj = 0; jj < x.size(); jj++) {
      for (int kk = 0; kk < x.size(); kk++)
        z[ii][jj] = (z[ii][jj] + x[ii][kk] * y[kk][jj]) % MOD;
    }
  }
  return z;
}
vector<vector<long long> > pow(vector<vector<long long> > u, long long lv) {
  if (lv == 0) return id;
  vector<vector<long long> > now = pow(u, lv / 2);
  now = mul(now, now);
  if (lv & 1) now = mul(now, u);
  return now;
}
int main() {
  scanf("%d%lld", &n, &k);
  for (i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (i = 0; i < n; i++) {
    vector<long long> tmp1;
    for (j = 0; j < n; j++) tmp1.push_back(0);
    b.push_back(tmp1);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) b[j][i] = 1;
    }
  }
  for (i = 0; i < n; i++) {
    vector<long long> tmp1;
    for (j = 0; j < n; j++) {
      if (i == j)
        tmp1.push_back(1);
      else
        tmp1.push_back(0);
    }
    id.push_back(tmp1);
  }
  b = pow(b, k - 1);
  long long res = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) res = (res + b[i][j]) % MOD;
  }
  printf("%lld\n", res);
}
