#include <bits/stdc++.h>
using namespace std;
long long deszcz[3000];
long long numer_par[3000];
long long a, n, m, pocz, kon;
long long dp[3000][3000];
void wypis() {
  for (int i = 0; i < a + 2; i++) {
    for (int j = 0; j < m + 1; j++) cout << dp[i][j] << " ";
    cout << endl;
  }
}
std::vector<pair<long long, long long> > parasolki;
int main() {
  parasolki.resize(3000);
  scanf("%lld %lld %lld", &a, &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &pocz, &kon);
    for (long long i = pocz; i < kon; i++) deszcz[i] = 1;
  }
  for (int i = 0; i < a + 5; i++) numer_par[i] = -1;
  parasolki[0] = make_pair(999999999999999999, 999999999999999999);
  bool nowe = 1;
  long long powt = 0, dlug = 1;
  for (int i = 0; i < m; i++) {
    scanf("%lld %lld", &pocz, &kon);
    nowe = 1;
    for (int j = 1; j < dlug; j++) {
      if (parasolki[j].first == pocz) {
        nowe = 0, parasolki[j].second = min(parasolki[j].second, kon), powt++;
        break;
      }
    }
    if (nowe) {
      dlug++;
      parasolki[i + 1] = make_pair(pocz, kon);
      numer_par[pocz] = i + 1 - powt;
    }
  }
  for (int i = 0; i < a + 2; i++) {
    for (int j = 0; j < m + 2; j++) dp[i][j] = 999999999999999999;
  }
  dp[0][0] = 0;
  for (int i = 0; i < a + 1; i++) {
    for (int j = 0; j < m + 2; j++) {
      if (dp[i][j] == 999999999999999999) continue;
      if (j > 0)
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + parasolki[j].second);
      if (!deszcz[i]) dp[i + 1][0] = min(dp[i + 1][0], dp[i][j]);
      if (numer_par[i] != -1)
        dp[i + 1][numer_par[i]] = min(
            dp[i + 1][numer_par[i]], dp[i][j] + parasolki[numer_par[i]].second);
    }
  }
  long long ans = 999999999999999999;
  for (int j = 0; j < m + 1; j++) {
    ans = min(dp[a][j], ans);
  }
  if (ans == 999999999999999999)
    printf("-1\n");
  else
    printf("%lld\n", ans);
}
