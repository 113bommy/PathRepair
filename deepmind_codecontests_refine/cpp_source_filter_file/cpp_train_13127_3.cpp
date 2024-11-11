#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
using namespace std;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, SGM = 3;
int n, m, k, u, v, x, y, t, l, r, shit;
int A[MAXN], mark[MAXN], pref[MAXN];
int dp[MAXN][SGM], pd[MAXN][SGM];
int prv[MAXN][SGM], nxt[MAXN][SGM];
pair<int, int> P[SGM];
string S;
int Get(int l, int r) {
  if (l > r) return 0;
  shit++;
  for (int c = 0; c < SGM; c++)
    if (l <= prv[r][c]) {
      int L = nxt[l][c], R = prv[r][c];
      int g = pd[l][c] ^ dp[r][c];
      g ^= pref[R] ^ pref[L];
      mark[g] = shit;
    }
  int res = 0;
  while (mark[res] == shit) res++;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> S;
  n = S.size();
  for (int i = 1; i <= n; i++) A[i] = S[i - 1] - 'a';
  A[0] = A[n + 1] = -1;
  for (int i = 1; i <= n; i++) {
    memcpy(prv[i], prv[i - 1], sizeof(prv[i]));
    prv[i][A[i]] = i;
  }
  fill(nxt[n + 1], nxt[n + 1] + SGM, n + 1);
  for (int i = n; i; i--) {
    memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
    nxt[i][A[i]] = i;
  }
  for (int r = 1; r <= n; r++) {
    int last = prv[r - 1][A[r]];
    pref[r] = pref[last] ^ dp[r - 1][A[r]];
    for (int i = 0; i < SGM; i++) P[i] = {prv[r][i], i};
    sort(P, P + SGM);
    for (int i = last + 1; i < r; i++) pd[i][A[r]] = Get(i, r - 1);
    for (int i = SGM - 2; ~i; i--) dp[r][P[i].second] = Get(P[i].first + 1, r);
  }
  cin >> m;
  while (m--) {
    cin >> l >> r;
    cout << (Get(l, r) ? "Alice" : "Bob") << "\n";
  }
  return 0;
}
