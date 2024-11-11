#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<int> sum_r(n, 0);
  vector<int> sum_c(m, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      sum_r[i] += a[i][j];
      sum_c[j] += a[i][j];
    }
  }
  vector<int> flip_r(n, false);
  vector<int> flip_c(m, false);
  while (true) {
    for (int i = 0; i < n; ++i) {
      if (sum_r[i] < 0) {
        sum_r[i] = -sum_r[i];
        for (int j = 0; j < m; ++j) {
          sum_c[j] -= 2 * a[i][j];
          a[i][j] *= -1;
        }
        flip_r[i] ^= 1;
        goto next;
      }
    }
    for (int j = 0; j < m; ++j) {
      if (sum_c[j] < 0) {
        sum_c[j] = -sum_c[j];
        for (int i = 0; i < n; ++i) {
          sum_r[i] -= 2 * a[i][j];
          a[i][j] *= -1;
        }
        flip_c[j] ^= 1;
        goto next;
      }
    }
    break;
  next : {}
  }
  int n_flip_r = 0, n_flip_c = 0;
  for (__typeof(flip_r.begin()) it = (flip_r.begin()); it != (flip_r).end();
       ++it) {
    n_flip_r += *it;
  }
  for (__typeof(flip_c.begin()) it = (flip_c.begin()); it != (flip_c).end();
       ++it) {
    n_flip_c += *it;
  }
  cout << n_flip_r;
  for (int i = 0; i < n; ++i) {
    if (flip_r[i]) {
      cout << " " << i + 1;
    }
  }
  cout << endl;
  cout << n_flip_c;
  for (int j = 0; j < m; ++j) {
    if (flip_c[j]) {
      cout << " " << j + 1;
    }
  }
  cout << endl;
}
