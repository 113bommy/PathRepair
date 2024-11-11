#include <bits/stdc++.h>
using namespace std;
int disc[5001], value[5001];
long long dp[5001], dpp[5001];
int n;
const long long INF = 1ll << 30;
struct data {
  int v;
  int id;
} a[5001], st[5001];
inline bool cmp(const data &a, const data &b) { return a.v < b.v; }
int cnt;
void discretization() {
  int i;
  memset(disc, 0, sizeof(disc));
  sort(a + 1, a + 1 + n, cmp);
  cnt = 1;
  disc[1] = a[1].v;
  for (i = 2; i <= n; i++) {
    if (a[i].v != a[i - 1].v) cnt++;
    disc[a[i].id] = cnt;
    value[cnt] = a[i].v;
  }
}
int main() {
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i].v);
    a[i].id = i;
    st[i].v = a[i].v;
    st[i].id = i;
  }
  discretization();
  memset(dp, 0, sizeof(dp));
  for (i = 1; i <= n; i++) {
    memcpy(dpp, dp, sizeof(dp));
    memset(dp, 0, sizeof(dp));
    dp[0] = INF;
    for (j = 1; j <= n; j++) {
      int temp;
      if (st[i].v < a[j].v)
        temp = a[j].v - st[i].v;
      else
        temp = st[i].v - a[j].v;
      dp[j] = min(dp[j - 1], dpp[j] + temp);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
