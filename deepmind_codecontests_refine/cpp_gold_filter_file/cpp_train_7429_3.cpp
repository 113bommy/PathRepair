#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int n;
double dp[100005][105];
double tmp[105];
int init[100005], has[100005];
double C[1000005][10];
int main() {
  for (int i = 0; i < 105; ++i)
    for (int j = 0; j < 105; ++j) dp[i][j] = 0;
  for (int i = 0; i < 1000005; ++i) {
    C[i][0] = 1;
    for (int j = 0; j < min(i, 9); ++j)
      C[i][j + 1] = C[i - 1][j] + C[i - 1][j + 1];
  }
  cin >> n;
  double cur = 0;
  for (int i = 0; i < n; ++i) {
    cin >> init[i];
    has[i] = init[i];
    dp[i][init[i]] = 1;
    if (init[i] == 0) ++cur;
  }
  int q;
  cin >> q;
  while (q--) {
    int u, v, k;
    cin >> u >> v >> k;
    --u;
    --v;
    cur -= dp[u][0];
    for (int j = 0; j < 105; ++j) tmp[j] = 0;
    for (int i = 0; i <= init[u]; ++i)
      if (dp[u][i] > 1e-30) {
        for (int j = 0; j <= k && j <= i; ++j) {
          tmp[i - j] +=
              dp[u][i] * C[i][j] * C[has[u] - i][k - j] / C[has[u]][k];
        }
      }
    for (int j = 0; j < 105; ++j) dp[u][j] = tmp[j];
    has[u] -= k;
    has[v] += k;
    cur += dp[u][0];
    printf("%.10f\n", cur);
  }
  return 0;
}
