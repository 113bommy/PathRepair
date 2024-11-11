#include <bits/stdc++.h>
using namespace std;
const long long MXN = 3e5 + 10;
long long n, q;
long long A[MXN], ps[6][MXN][3];
vector<long long> perm[6];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  perm[0] = {0, 1, 2};
  for (int i = 1; i < 6; i++) {
    perm[i] = perm[i - 1];
    next_permutation(perm[i].begin(), perm[i].end());
  }
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    A[i] = (ch - 'a');
  }
  for (int j = 0; j < 6; j++) {
    for (int i = 1; i <= n; i++) {
      for (int k = 0; k < 3; k++) {
        ps[j][i][k] = ps[j][i - 1][(k + 2) & 3] + (perm[j][k] != A[i]);
      }
    }
  }
  while (q--) {
    long long ans = n, l, r;
    cin >> l >> r;
    for (int j = 0; j < 6; j++) {
      long long now = ps[j][r][(r - l) & 3] - ps[j][l - 1][2];
      ans = min(ans, now);
    }
    cout << ans << '\n';
  }
  return 0;
}
