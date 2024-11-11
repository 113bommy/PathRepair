#include <bits/stdc++.h>
using namespace std;
const char DEBUG = 0;
mt19937 gen(
    (unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
#pragma comment(linker, "/STACK:16777216")
long long hung(vector<vector<long long>> a) {
  int n = a.size();
  vector<long long> pl(n), pr(n);
  vector<int> mt(n, -1), p(n);
  long long res = 0;
  for (int row = 1; row < n; row++) {
    vector<long long> d(n, 1000000000000000000LL);
    vector<char> used(n);
    mt[0] = row;
    int col = 0;
    while (mt[col] != -1) {
      used[col] = 1;
      int v = mt[col];
      long long delta = 1000000000000000000LL;
      for (int i = 1; i < n; i++)
        if (!used[i]) {
          long long c = a[v][i] - pl[v] - pr[i];
          if (c < d[i]) d[i] = c, p[i] = col;
          delta = min(delta, d[i]);
        }
      for (int i = 0; i < n; i++)
        if (used[i]) {
          pr[i] -= delta;
          pl[mt[i]] += delta;
        }
      for (int i = 1; i < n; i++)
        if (!used[i]) {
          d[i] -= delta;
          if (!d[i]) col = i;
        }
    }
    while (col) {
      mt[col] = mt[p[col]];
      col = p[col];
    }
    res = max(res, pr[0]);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> k(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> k[i];
  vector<vector<long long>> mat(n + 1, vector<long long>(n + 1));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      mat[i + 1][j + 1] = -(a[j] - 1LL * min(i, k[j]) * b[j]);
  cout << hung(mat);
  return 0;
}
