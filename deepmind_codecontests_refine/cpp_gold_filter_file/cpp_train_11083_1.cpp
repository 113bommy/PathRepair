#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > A(n + 2, vector<int>(32));
  vector<int> q(m), l(m), r(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> q[i];
    for (int j = 0; j < 30; j++) {
      if ((q[i] >> j) & 1) {
        A[l[i]][j]++;
        A[r[i] + 1][j]--;
      }
    }
  }
  vector<int> a(n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 30; j++) {
      A[i][j] += A[i - 1][j];
      if (A[i][j]) a[i - 1] |= 1 << j;
    }
  }
  vector<vector<int> > rmq(19, vector<int>(n + 1));
  vector<int> lg(n + 1);
  rmq[0][1] = a[0];
  for (int i = 2; i <= n; i++) {
    lg[i] = lg[i >> 1] + 1;
    rmq[0][i] = a[i - 1];
  }
  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 1; j <= n - (1 << (i - 1)) + 1; j++) {
      rmq[i][j] = rmq[i - 1][j] & rmq[i - 1][j + (1 << (i - 1))];
    }
  }
  auto query = [&](int a, int b) -> int {
    int l = lg[b - a + 1];
    return rmq[l][a] & rmq[l][b - (1 << l) + 1];
  };
  for (int i = 0; i < m; i++) {
    if (query(l[i], r[i]) != q[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES\n";
  for (int& x : a) cout << x << " ";
  return 0;
}
