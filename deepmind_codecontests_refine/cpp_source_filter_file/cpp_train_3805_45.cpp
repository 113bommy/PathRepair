#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = 1000000009;
int i, j, k, m, n, l;
int ans;
int a[601][601], b[601][601];
long long c[16][16], dp[16][1 << 16], path[16][1 << 16];
long long dist(int i, int j) {
  long long ret = 0;
  int div = 1;
  for (int k = 0; k < n / div; k++) {
    long long s1 = 0, s2 = 0;
    for (int u = k * div; u < (k + 1) * div; u++) {
      s1 += a[i][u];
      s2 += a[j][u];
    }
    ret += abs(s1 - s2);
  }
  return ret;
}
int main() {
  int tn;
  cin >> tn;
  while (tn--) {
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    for (int i = 0; i < k; i++)
      for (int j = 0; j < k; j++) {
        c[i][j] = dist((i + 1) * (m / k) - 1, j * (m / k));
      }
    if (0)
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) cout << c[i][j] << " ";
        cout << endl;
      }
    if (0) {
      for (int i = 0; i < m - 1; i++) {
        if ((i + 1) % (m / k) == 0)
          cout << "-----------------------------" << endl;
        cout << dist(i, i + 1) << endl;
      }
      cout << "Last: " << dist(m - 1, 0) << " " << c[2][0] << endl;
    }
    memset(dp, -1, sizeof(dp));
    ;
    for (int i = 0; i < k; i++) {
      dp[i][1 << i] = 0;
      path[i][1 << i] = -1;
    }
    for (int j = 0; j < (1 << k); j++)
      for (int i = 0; i < k; i++)
        if (dp[i][j] != -1)
          for (int p = 0; p < k; p++)
            if (((1 << p) & j) == 0) {
              if (dp[p][j ^ (1 << p)] == -1 ||
                  dp[p][j ^ (1 << p)] > dp[i][j] + c[i][p]) {
                dp[p][j ^ (1 << p)] = dp[i][j] + c[i][p];
                path[p][j ^ (1 << p)] = i;
              }
            }
    int i = 0;
    for (int j = 0; j < k; j++)
      if (dp[j][(1 << k) - 1] < dp[i][(1 << k) - 1]) i = j;
    vector<int> ret;
    int j = (1 << k) - 1;
    while (path[i][j] != -1) {
      ret.push_back(i);
      int newj = j ^ (1 << i);
      i = path[i][j];
      j = newj;
    }
    ret.push_back(i);
    reverse(ret.begin(), ret.end());
    vector<int> sol(k);
    for (int i = 0; i < ((int)ret.size()); i++) sol[ret[i]] = i;
    for (int i = 0; i < ((int)sol.size()); i++) cout << sol[i] + 1 << " ";
    cout << endl;
  }
  return 0;
}
