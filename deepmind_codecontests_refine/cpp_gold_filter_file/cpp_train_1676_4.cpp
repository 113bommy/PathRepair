#include <bits/stdc++.h>
using namespace std;
int p;
void printLayer(int i, const vector<long long>& layer) {
  cerr << "layer " << i << '\n';
  for (int j = 0; j < layer.size(); j++) cerr << layer[j] << ' ';
  cerr << '\n';
}
vector<int> x, y;
int f(int a, int b) { return (x[a] + y[b]) % p; }
const int MAX_N = 20010;
long long dp[2][MAX_N];
long long up[MAX_N];
long long down[MAX_N];
pair<long long, string> solve(int i1, int j1, int i2, int j2) {
  if (i1 == i2) {
    pair<long long, string> ret(f(i1, j2), "");
    for (int j = j1; j < j2; j++) {
      ret.first += f(i1, j);
      ret.second += 'S';
    }
    return ret;
  } else if (j1 == j2) {
    pair<long long, string> ret(f(i2, j1), "");
    for (int i = i1; i < i2; i++) {
      ret.first += f(i, j1);
      ret.second += 'C';
    }
    return ret;
  }
  int n = i2 - i1 + 1, m = j2 - j1 + 1, k = (n + m - 2) / 2;
  memset(down, -1, n * sizeof(down[0]));
  memset(up, -1, n * sizeof(up[0]));
  int cur = 0, done = 1;
  for (int j = m - 1; j >= 0; j--)
    dp[done][j] = f(i2, j1 + j) + (j + 1 < m ? dp[done][j + 1] : 0);
  int jDiag = k - n + 1;
  if (0 <= jDiag && jDiag < m) down[n - 1] = dp[done][jDiag];
  for (int i = n - 2; i >= 0; i--) {
    for (int j = m - 1; i + j >= k - 1 && j >= 0; j--)
      dp[cur][j] =
          f(i1 + i, j1 + j) + max(j + 1 < m ? dp[cur][j + 1] : 0, dp[done][j]);
    swap(cur, done);
    int jDiag = k - i;
    if (0 <= jDiag && jDiag < m) down[i] = dp[done][jDiag];
  }
  for (int j = 0; j < m; j++)
    dp[done][j] = f(i1, j1 + j) + (j > 0 ? dp[done][j - 1] : 0);
  jDiag = k;
  if (0 <= jDiag && jDiag < m) up[0] = dp[done][jDiag];
  for (int i = 1; i < n; i++) {
    for (int j = 0; i + j <= k + 1 && j < m; j++)
      dp[cur][j] =
          f(i1 + i, j1 + j) + max(j > 0 ? dp[cur][j - 1] : 0, dp[done][j]);
    swap(cur, done);
    int jDiag = k - i;
    if (0 <= jDiag && jDiag < m) up[i] = dp[done][jDiag];
  }
  long long best = -1, bestI;
  for (int i = 0; i < n; i++) {
    long long cur = up[i] + down[i] - f(i1 + i, j1 + k - i);
    if (cur > best) best = cur, bestI = i;
  }
  int i0 = i1 + bestI, j0 = j1 + k - bestI;
  pair<long long, string> retUp = solve(i1, j1, i0, j0);
  pair<long long, string> retDown = solve(i0, j0, i2, j2);
  return make_pair(retUp.first + retDown.first - f(i0, j0),
                   retUp.second + retDown.second);
}
int main() {
  int n, m;
  cin >> n >> m >> p;
  x.resize(n), y.resize(m);
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < m; i++) cin >> y[i];
  pair<long long, string> ans = solve(0, 0, n - 1, m - 1);
  cout << ans.first << '\n' << ans.second << '\n';
  return 0;
}
