#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> items[N], compset;
long double C[N][N], sum[N][N], cnt[N][N];
int n, m, gtcnt[N], eqcnt[N];
inline long double getProb(int i, int j) {
  int n = items[i].size();
  return C[eqcnt[i]][j - gtcnt[i]] / C[n][j];
}
int main() {
  C[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int k, a;
    for (scanf("%d", &k); k--;) {
      scanf("%d", &a);
      items[i].push_back(a);
      compset.push_back(a);
    }
  }
  sort(compset.begin(), compset.end(), greater<int>());
  int clevel = compset[n - 1];
  for (int i = 1; i <= m; ++i)
    for (int p : items[i]) {
      gtcnt[i] += p > clevel;
      eqcnt[i] += p == clevel;
    }
  sum[0][0] = cnt[0][0] = 1;
  for (int i = 1; i <= m; ++i)
    for (int j = 0; j <= n; ++j)
      for (int s = gtcnt[i]; s <= gtcnt[i] + eqcnt[i]; ++s) {
        sum[i][j] += sum[i - 1][j - s] * getProb(i, s);
        cnt[i][j] += cnt[i - 1][j - s];
      }
  cout.setf(ios::fixed);
  cout << setprecision(10) << sum[m][n] / cnt[m][n] << endl;
}
