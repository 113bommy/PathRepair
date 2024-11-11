#include <bits/stdc++.h>
using namespace std;
int const N = 100;
bool dp[N + 1][N * N];
vector<int> g[N + 1];
pair<int, int> bck[N + 1][N * N];
void no() { printf("NO\n"); }
vector<int> go(int n, int m) {
  if (m == n + 1) {
    vector<int> an(n);
    int t = 1, i = 0;
    while (t < n) an[i++] = t, t += 2;
    reverse(an.begin(), an.begin() + i);
    an[i++] = n;
    t = 2;
    while (t < n) an[i++] = t, t += 2;
    return an;
  }
  if (m == n * (n + 1) >> 1) {
    vector<int> an(n);
    for (int i = 0; i < (int)(n); ++i) an[i] = i + 1;
    return an;
  }
  int n1 = bck[n][m].first, m1 = bck[n][m].second;
  vector<int> a = go(n1, m1), b = go(n - n1 + 1, m - m1 + 1);
  for (int i = 0; i < (int)(a.size()); ++i) a[i] += b[0] - 1;
  int t = a.size();
  a.insert(a.end(), b.begin() + 1, b.end());
  for (int i = t; i < (int)(a.size()); ++i)
    if (a[i] > b[0]) a[i] += t - 1;
  if (a[t] > a[t - 1] && a[t - 1] > a[0] || a[t] < a[t - 1] && a[t - 1] < a[0])
    reverse(a.begin(), a.begin() + t);
  return a;
}
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 1) {
    printf("YES\n1\n");
    return;
  }
  if (!dp[n][m]) return no();
  vector<int> an = go(n, m);
  printf("YES\n%d", an[0]);
  for (int i = 1; i < (int)(n); ++i) printf("%d", an[i]);
  printf("\n");
}
int main(void) {
  for (int i = 2; i < (int)(N + 1); ++i) {
    if (i != 3) dp[i][i + 1] = true;
    int lm = i * (i + 1) >> 1;
    dp[i][lm] = true;
    for (int j = i + 1; j < (int)(lm + 1); ++j)
      if (dp[i][j]) g[i].push_back(j);
    for (int j = 2; j < (int)(i + 1); ++j)
      if (i + j - 1 <= N)
        for (int k = 0; k < (int)(g[i].size()); ++k)
          for (int w = 0; w < (int)(g[j].size()); ++w)
            if (!dp[i + j - 1][g[i][k] + g[j][w] - 1]) {
              dp[i + j - 1][g[i][k] + g[j][w] - 1] = true;
              bck[i + j - 1][g[i][k] + g[j][w] - 1] = make_pair(i, g[i][k]);
            }
  }
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
