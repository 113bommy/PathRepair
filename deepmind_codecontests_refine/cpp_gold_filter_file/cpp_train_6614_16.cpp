#include <bits/stdc++.h>
using namespace std;
long long exp(long long n, long long r, long long md) {
  if (r == 0) {
    return 1;
  }
  long long ans = exp(n, r / 2, md);
  ans *= ans;
  ans %= md;
  if (r & 1) {
    ans *= n;
    ans %= md;
  }
  return ans % md;
}
long long choose(long long n, long long r, long long md) {
  long long ans = 1;
  for (int i = n - r + 1; i < n + 1; ++i) {
    ans *= i;
    ans %= md;
  }
  for (int i = 1; i < r + 1; ++i) {
    ans *= exp(i, md - 2, md);
    ans %= md;
  }
  return ans % md;
}
int mat[107][107] = {0};
int main() {
  int n, m, q, l = 0;
  cin >> n >> m >> q;
  vector<pair<int, int>> pr;
  for (int i = 0; i < q; ++i) {
    int p;
    cin >> p;
    int d, x, y, v;
    if (p > 2) {
      cin >> x >> y >> v;
      mat[x][y] = v;
    } else {
      cin >> d;
      pr.push_back(make_pair(p, d));
      if (p == 1) {
        int temp = mat[d][1];
        for (int i = 1; i < m; ++i) {
          mat[d][i] = mat[d][i + 1];
        }
        mat[d][m] = temp;
      } else {
        int temp = mat[1][d];
        for (int i = 1; i < n; ++i) {
          mat[i][d] = mat[i + 1][d];
        }
        mat[n][d] = temp;
      }
    }
  }
  for (int i = pr.size() - 1; i >= 0; --i) {
    if (pr[i].first == 1) {
      int temp = mat[pr[i].second][m];
      for (int j = m; j > 1; --j) {
        mat[pr[i].second][j] = mat[pr[i].second][j - 1];
      }
      mat[pr[i].second][1] = temp;
    } else {
      int temp = mat[n][pr[i].second];
      for (int j = n; j > 1; --j) {
        mat[j][pr[i].second] = mat[j - 1][pr[i].second];
      }
      mat[1][pr[i].second] = temp;
    }
  }
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
