#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 3e5 + 5;
long long D[N][N];
long long cum[26][N][N];
long long R[N][N];
long long a[M], b[M], x[M], y[M];
char c[M];
string g[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> g[i];
    g[i] = "#" + g[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i] >> x[i] >> y[i] >> c[i];
    cum[c[i] - 'a'][a[i]][b[i]]++;
    cum[c[i] - 'a'][a[i]][y[i] + 1]--;
    cum[c[i] - 'a'][x[i] + 1][b[i]]--;
    cum[c[i] - 'a'][x[i] + 1][y[i] + 1]++;
    R[a[i]][b[i]]++;
    R[a[i]][y[i] + 1]--;
    R[x[i] + 1][b[i]]--;
    R[x[i] + 1][y[i] + 1]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      R[i][j] += R[i - 1][j] + R[i][j - 1] - R[i - 1][j - 1];
    }
  }
  for (int k = 0; k < 26; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cum[k][i][j] +=
            cum[k][i - 1][j] + cum[k][i][j - 1] - cum[k][i - 1][j - 1];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cum[g[i][j] - 'a'][i][j] += q - R[i][j];
  long long total = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 26; k++) {
        D[i][j] += abs((g[i][j] - 'a') - k) * (cum[k][i][j]);
      }
    }
  }
  for (int k = 0; k < 26; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cum[k][i][j] +=
            cum[k][i - 1][j] + cum[k][i][j - 1] - cum[k][i - 1][j - 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      D[i][j] += D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
    }
  }
  total = D[n][m];
  long long ans = 1e18;
  for (int i = 0; i < q; i++) {
    long long T = total;
    T -= D[x[i]][y[i]] - D[x[i]][b[i] - 1] - D[a[i] - 1][y[i]] +
         D[a[i] - 1][b[i] - 1];
    for (int k = 0; k < 26; k++)
      T += abs((c[i] - 'a') - k) *
           (cum[k][x[i]][y[i]] - cum[k][x[i]][b[i] - 1] -
            cum[k][a[i] - 1][y[i]] + cum[k][a[i] - 1][b[i] - 1]);
    ans = min(ans, T);
  }
  cout << ans << endl;
  return 0;
}
