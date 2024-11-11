#include <bits/stdc++.h>
using namespace std;
const int MAXN = 41;
const int MAXM = MAXN * MAXN / 2;
int X[MAXM], Y[MAXM];
vector<int> ed[MAXN];
int two[1 << 20];
long long ed1[MAXN], ed2[MAXN];
long long dp1[1 << 20], dp2[1 << 20];
bool chk[1 << 20];
int dfn[MAXN];
bool dfs(int x, int d) {
  dfn[x] = d;
  bool r = true;
  for (auto a : ed[x]) {
    if (!dfn[a]) dfs(a, d + 1);
    if (((dfn[a] ^ dfn[x]) & 1) == 0) r = false;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  for (int i = 0; i < 20; i++) two[1 << i] = i;
  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> X[i] >> Y[i];
  for (int i = 0; i < M; i++) {
    ed[X[i]].push_back(Y[i]);
    ed[Y[i]].push_back(X[i]);
  }
  for (int i = 1; i <= N; i++)
    for (auto a : ed[i]) {
      if (a <= N / 2)
        ed1[i] ^= 1 << (a - 1);
      else
        ed2[i] ^= 1 << (a - N / 2 - 1);
    }
  dp1[0] = 1;
  for (int i = 1; i < (1 << (N / 2)); i++) {
    int r = ((i) & (-(i)));
    dp1[i] =
        dp1[i ^ r] + dp1[(i ^ r) & (((1 << (N / 2)) - 1) ^ ed1[two[r] + 1])];
  }
  dp2[0] = (1 << (N / 2)) - 1;
  chk[0] = true;
  long long ans = dp1[(1 << (N / 2)) - 1];
  for (int i = 1; i < (1 << ((N + 1) / 2)); i++) {
    int r = ((i) & (-(i)));
    dp2[i] = dp2[i ^ r] & (((1 << (N / 2)) - 1) ^ ed1[two[r] + N / 2 + 1]);
    chk[i] = chk[i ^ r] && ((i & ed2[two[r] + N / 2 + 1]) == 0);
    if (chk[i]) ans += dp1[dp2[i]];
  }
  ans *= -2;
  ans += 1ll << N;
  for (int i = 1; i <= N; i++) chk[i] = false;
  int cnt = 0;
  bool bp = true;
  for (int i = 1; i <= N; i++)
    if (!dfn[i]) {
      cnt++;
      bp &= dfs(i, 1);
    }
  ans -= 1ll << cnt;
  if (bp) ans += 1ll << cnt;
  int alo = 0;
  for (int i = 1; i <= N; i++)
    if (ed[i].empty()) alo++;
  ans += 1ll << (alo + 1);
  if (M == 0) ans -= 1ll << N;
  cout << ans;
  return 0;
}
