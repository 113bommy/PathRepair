#include <bits/stdc++.h>
using namespace std;
long double prob[51][51][51], p[51][51][51];
int n, m, num[51];
template <typename T>
T combination(int n, int k) {
  if (n < k) return (0);
  static vector<vector<T> > cs(1, vector<T>(1, 1));
  for (int i = cs.size(); i <= n; i++) {
    cs.push_back(vector<T>(i + 1));
    cs[i][0] = cs[i][i] = 1;
    for (int j = 1; j < i; j++) cs[i][j] = cs[i - 1][j] + cs[i - 1][j - 1];
  }
  return (cs[n][k]);
}
int main() {
  cout << fixed;
  cout.precision(20);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> num[i];
  for (int i = 1; i <= 50; i++)
    for (int j = 0; j <= 50; j++)
      for (int k = 0; k <= j; k++) {
        p[i][j][k] = 1;
        for (int l = 1; l <= k; l++) p[i][j][k] /= i;
        for (int l = 1; l <= j - k; l++) p[i][j][k] *= (long double)(i - 1) / i;
        p[i][j][k] *= combination<int>(j, k);
      }
  prob[0][n][0] = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) {
        for (int l = 0; l <= j; l++)
          prob[i + 1][j - l][max(k, (l + num[i + 1] - 1) / num[i + 1])] +=
              prob[i][j][k] * p[m - i][j][l];
      }
  long double e = 0;
  for (int i = 0; i <= n; i++) e += prob[m][0][i] * i;
  cout << e << endl;
}
