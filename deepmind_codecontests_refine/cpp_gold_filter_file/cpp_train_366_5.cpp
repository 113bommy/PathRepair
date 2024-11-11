#include <bits/stdc++.h>
using namespace std;
void test_case() {
  long long n, i, j, k;
  cin >> n >> k;
  vector<long long> p(n);
  vector<long long> w(n);
  const long long LOGN = log2(k) + 5;
  for (i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (i = 0; i < n; i++) {
    cin >> w[i];
  }
  vector<vector<long long>> sparse(n, vector<long long>(LOGN, -1));
  vector<vector<pair<long long, long long>>> sparse2(
      n, vector<pair<long long, long long>>(LOGN, {0, INT_MAX}));
  for (i = 0; i < n; i++) {
    sparse[i][0] = p[i];
    sparse2[i][0] = {w[i], w[i]};
  }
  for (j = 1; j < LOGN; j++) {
    for (i = 0; i < n; i++) {
      assert(sparse[i][j - 1] != -1);
      sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
      sparse2[i][j].first =
          sparse2[i][j - 1].first + sparse2[sparse[i][j - 1]][j - 1].first;
      sparse2[i][j].second = min(sparse2[i][j - 1].second,
                                 sparse2[sparse[i][j - 1]][j - 1].second);
    }
  }
  for (i = 0; i < n; i++) {
    long long cnt = k;
    long long su = 0;
    long long mn = INT_MAX;
    long long u = i;
    for (j = LOGN - 1; j >= 0; j--) {
      if (cnt - (1LL << j) >= 0) {
        cnt -= (1LL << j);
        su += sparse2[u][j].first;
        mn = min(mn, sparse2[u][j].second);
        u = sparse[u][j];
      }
    }
    assert(cnt == 0);
    cout << su << " " << mn << "\n";
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  t = 1;
  while (t--) {
    test_case();
  }
  return 0;
}
