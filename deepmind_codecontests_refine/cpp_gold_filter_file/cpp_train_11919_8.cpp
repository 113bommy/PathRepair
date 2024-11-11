#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  long long n, T, i, j, k, ct, cn = 1, nn, r = 0;
  cin >> n >> T;
  ct = T;
  vector<long long> t(n), q(n);
  for (i = 0; i < n; ++i) {
    cin >> t[i] >> q[i];
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n - 1; ++j) {
      if (t[j] < t[j + 1]) {
        swap(t[j], t[j + 1]);
        swap(q[j], q[j + 1]);
      }
    }
  }
  vector<vector<long long> > v(n + 1, vector<long long>(n + 1, -1));
  while (ct > t[0]) {
    cn *= 2;
    if (cn > n) {
      cn = n;
    }
    --ct;
  }
  v[0][cn] = 0;
  for (i = 0; i < n; ++i) {
    ct = t[i];
    nn = 1;
    if (i != n - 1) {
      for (j = ct; j > t[i + 1]; --j) {
        nn *= 2;
        if (nn > n) {
          nn = n;
        }
      }
    }
    for (j = 0; j <= n; ++j) {
      if (v[i][j] != -1) {
        v[i + 1][min(j * nn, n)] = max(v[i + 1][min(j * nn, n)], v[i][j]);
        if (j != 0) {
          v[i + 1][min((j - 1) * nn, n)] =
              max(v[i + 1][min((j - 1) * nn, n)], v[i][j] + q[i]);
        }
      }
    }
  }
  for (i = 0; i <= n; ++i) {
    r = max(r, v[n][i]);
  }
  cout << r << endl;
  return 0;
}
