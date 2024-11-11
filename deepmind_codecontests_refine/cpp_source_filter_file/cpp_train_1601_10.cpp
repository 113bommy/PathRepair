#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int main(int argc, char **argv) {
  ifstream from;
  const int nmin = 2, nmax = 300, kmin = 1, kmax = 300;
  int n, rt, rt1, rt2, i, j, j0, j1, k;
  int err = 0;
  char ch;
  cin >> n;
  vector<vector<int>> d(n);
  for (i = 0; i < n; i++) d[i].resize(n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> d[i][j];
    }
  }
  cin >> k;
  vector<int> a(k);
  vector<int> b(k);
  vector<int> c(k);
  for (i = 0; i < k; i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
  }
  vector<int> q(k);
  for (i = 0; i < k; i++) {
    if (d[a[i]][b[i]] > c[i]) {
      d[a[i]][b[i]] = c[i];
      d[b[i]][a[i]] = c[i];
    }
    q[i] = 0;
    for (j0 = 0; j0 < n - 1; j0++) {
      for (j1 = j0 + 1; j1 < n; j1++) {
        rt1 = d[j0][a[i]] + d[a[i]][b[i]] + d[b[i]][j1];
        rt2 = d[j0][b[i]] + d[a[i]][b[i]] + d[a[i]][j1];
        rt = (rt1 < rt2) ? rt1 : rt2;
        if (rt < d[j0][j1]) {
          d[j0][j1] = rt;
          d[j1][j0] = rt;
        }
        q[i] += d[j0][j1];
      }
    }
  }
  for (i = 0; i < k - 1; i++) {
    cout << q[i] << " ";
  }
  cout << q[k - 1] << endl;
  return 0;
}
