#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0);
long long A[110][110];
long long Q[10010][4];
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  memset(A, 0, sizeof(A));
  ;
  for (int i = 0; i <= q - 1; ++i) {
    cin >> Q[i][0];
    if (Q[i][0] == 1 || Q[i][0] == 2) {
      cin >> Q[i][1];
    } else {
      cin >> Q[i][1] >> Q[i][2] >> Q[i][3];
    }
  }
  for (int b = q - 1; b >= 0; --b) {
    long long t;
    t = Q[b][0];
    if (t == 1) {
      long long r;
      r = Q[b][1];
      r--;
      long long temp = A[r][m - 1];
      for (int i = m - 1; i >= 1; --i) A[r][i] = A[r][i - 1];
      A[r][0] = temp;
    }
    if (t == 2) {
      long long c;
      c = Q[b][1];
      c--;
      long long temp = A[n - 1][c];
      for (int i = n - 1; i >= 1; --i) A[i][c] = A[i - 1][c];
      A[0][c] = temp;
    }
    if (t == 3) {
      long long r, c;
      long long x;
      r = Q[b][1];
      c = Q[b][2];
      x = Q[b][3];
      --r;
      --c;
      A[r][c] = x;
    }
  }
  for (int i = 0; i <= n - 1; ++i) {
    for (int j = 0; j <= m - 1; ++j) {
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }
}
int main() {
  clock_t tm = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int _t = 1; _t <= t; ++_t) {
    solve();
  }
  tm = clock() - tm;
  cerr << (float)(tm) / CLOCKS_PER_SEC << "\n";
  return 0;
}
