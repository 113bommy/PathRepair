#include <bits/stdc++.h>
using namespace std;
void init() {}
char a[105][105];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int nn, mm;
  int kub, klb;
  if (n & 1) {
    klb = m / 2;
    if (k < klb) {
      cout << "NO" << endl;
      return;
    }
    if ((k - klb) % 2 == 1) {
      cout << "NO" << endl;
      return;
    }
    nn = n - 1;
    mm = m;
    for (int i = 0; i < m / 2; i++) {
      char c;
      if (i & 1) {
        c = 'y';
      } else {
        c = 'z';
      }
      a[n][2 * i + 1] = c;
      a[n][2 * i + 2] = c;
    }
    k -= klb;
  } else if (m & 1) {
    kub = n * m / 2 - n / 2;
    if (k > kub) {
      cout << "NO" << endl;
      return;
    }
    if (k % 2 == 1) {
      cout << "NO" << endl;
      return;
    }
    nn = n;
    mm = m - 1;
  } else {
    if (k % 2 == 1) {
      cout << "NO" << endl;
      return;
    }
    nn = n;
    mm = m;
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < nn / 2; ++j) {
      char c;
      if ((i + j) & 1) {
        c = 'v';
      } else {
        c = 'w';
      }
      a[2 * j + 1][i] = c;
      a[2 * j + 2][i] = c;
    }
  }
  int ii = 0, jj = 0;
  while (k) {
    k -= 2;
    char c1, c2;
    if ((ii + jj) & 1) {
      c1 = 'a';
      c2 = 'b';
    } else {
      c1 = 'c';
      c2 = 'd';
    }
    a[2 * ii + 1][2 * jj + 1] = c1;
    a[2 * ii + 1][2 * jj + 2] = c1;
    a[2 * ii + 2][2 * jj + 1] = c2;
    a[2 * ii + 2][2 * jj + 2] = c2;
    ii++;
    if (ii >= nn / 2) {
      ii = 0;
      jj++;
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= (n); ++i) {
    for (int j = 1; j <= (m); ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _t_t_;
  cin >> _t_t_;
  init();
  while (_t_t_--) {
    solve();
  }
  return 0;
}
