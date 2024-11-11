#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;
int st[100];
int mid[100];
int spa[17][100];
int dp[18][100];
int mm[1000000];
int ed[1000000];
int main() {
  int n, l, m, t;
  scanf("%d %d %d", &n, &l, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    t %= m;
    st[t]++;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    t %= m;
    mm[i] = t;
    mid[t]++;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &ed[i]);
    ed[i] %= m;
  }
  for (int i = 0; i < m; i++) {
    spa[0][i] = mid[i];
    dp[0][i] = st[i];
  }
  for (int i = 1; i <= 16; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < m; k++)
        spa[i][j] = (spa[i][j] +
                     (long long)spa[i - 1][k] * spa[i - 1][(j - k + m) % m]) %
                    MOD;
  v.push_back(-1);
  int le = l - 2;
  for (int i = 0; i < 17; i++)
    if ((1 << i) & le) v.push_back(i);
  for (int i = 1; i < (int)(v).size(); i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < m; k++)
        dp[i][j] =
            (dp[i][j] + (long long)dp[i - 1][k] * spa[v[i]][(j - k + m) % m]) %
            MOD;
  int nn = (int)(v).size() - 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int tt = ed[i] + mm[i];
    tt %= m;
    ans += dp[nn][(m - tt) % m];
  }
  printf("%lld", ans % MOD);
}
