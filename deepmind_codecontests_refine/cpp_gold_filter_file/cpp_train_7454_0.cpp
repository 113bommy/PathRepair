#include <bits/stdc++.h>
using namespace std;
long long fast_min(long long a, long long b) {
  return (((a - b) >> 64) & (a ^ b)) ^ b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<vector<char>> mat(n, vector<char>(m));
  pair<long long, long long> r1{0, 0}, r2{n - 1, m - 1};
  pair<long long, long long> g1{0, 0}, g2{n - 1, m - 1};
  pair<long long, long long> b1{0, 0}, b2{n - 1, m - 1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
      if (mat[i][j] == 'R') {
        r1 = max(r1, {i, j});
        r2 = min(r2, {i, j});
      } else if (mat[i][j] == 'G') {
        g1 = max(g1, {i, j});
        g2 = min(g2, {i, j});
      } else {
        b1 = max(b1, {i, j});
        b2 = min(b2, {i, j});
      }
    }
  }
  if ((r1.first == g1.first && r1.first == b1.first) ||
      (r1.second == g1.second && r1.second == b1.second)) {
    long long r = 0;
    long long g = 0;
    long long b = 0;
    for (int i = r2.first; i <= r1.first; ++i) {
      for (int j = r2.second; j <= r1.second; ++j) {
        r++;
        if (mat[i][j] != 'R') {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
    for (int i = g2.first; i <= g1.first; ++i) {
      for (int j = g2.second; j <= g1.second; ++j) {
        g++;
        if (mat[i][j] != 'G') {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
    for (int i = b2.first; i <= b1.first; ++i) {
      for (int j = b2.second; j <= b1.second; ++j) {
        b++;
        if (mat[i][j] != 'B') {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
    if (r == b && r == g) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
