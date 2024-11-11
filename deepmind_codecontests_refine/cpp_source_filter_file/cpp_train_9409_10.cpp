#include <bits/stdc++.h>
using namespace std;
static const int maxn = 500 + 5;
static const long long int inf = 1e18;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<long long int> > mat(n + 1, vector<long long int>(n + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> mat[i][j];
  vector<int> del(n + 1);
  for (int i = 1; i <= n; i++) cin >> del[i];
  vector<long long int> ans(n);
  vector<int> alive;
  for (int k = n; k >= 1; k--) {
    alive.push_back(del[k]);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int ii = del[i];
        int jj = del[j];
        int kk = del[k];
        mat[ii][jj] = min(mat[ii][jj], mat[ii][kk] + mat[kk][jj]);
      }
    }
    long long int sum = 0;
    for (int i : alive)
      for (int j : alive) sum += mat[i][j];
    ans[k] = sum;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
