#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, q;
  cin >> n >> m >> q;
  int mat[n][m];
  vector<long long> cnt(n, 0);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
    long long mx = 0;
    long long c = 0;
    long long j = 0;
    while (j < m) {
      while (j < m && mat[i][j] == 1) {
        j++;
        c++;
      }
      mx = max(mx, c);
      j++;
      c = 0;
    }
    cnt[i] = mx;
  }
  while (q--) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    mat[x][y] = 1 - mat[x][y];
    long long mx = 0;
    long long c = 0;
    long long j = 0;
    while (j < m) {
      while (j < m && mat[x][j] == 1) {
        j++;
        c++;
      }
      mx = max(mx, c);
      j++;
      c = 0;
    }
    cnt[x] = mx;
    cout << *max_element(cnt.begin(), cnt.end()) << "\n";
  }
  return 0;
}
