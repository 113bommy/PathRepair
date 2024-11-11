#include <bits/stdc++.h>
using namespace std;
const int M = 1002, N = 200005, mod = 1000000007;
int n, m, q, S[N], T[N], eu[N], ev[N], tl[N], tr[N], sl[N], sr[N], ans[N];
struct query {
  int x, n;
};
bool operator<(query a, query b) { return a.x < b.x; }
bool cmp(query x, query y) { return y < x; }
vector<query> bl[N], br[N];
bitset<M> dp[M], p[N];
void solve(int l, int r) {
  if (l > r) return;
  int d = (l + r) >> 1;
  for (int i = d; i >= l; i--) {
    dp[eu[i]] = dp[ev[i]] = dp[eu[i]] | dp[ev[i]];
    while (tl[i] < sl[i] && bl[i][tl[i]].x >= d) {
      p[bl[i][tl[i]].n] = dp[S[bl[i][tl[i]].n]];
      tl[i]++;
    }
  }
  for (int x = l; x <= d; x++) {
    int i = eu[x];
    dp[i].reset(), dp[i][i] = 1;
    i = ev[x];
    dp[i].reset(), dp[i][i] = 1;
  }
  for (int i = d; i <= r; i++) {
    dp[eu[i]] = dp[ev[i]] = dp[eu[i]] | dp[ev[i]];
    while (tr[i] < sr[i] && br[i][tr[i]].x <= d) {
      ans[br[i][tr[i]].n] =
          !((p[br[i][tr[i]].n] & dp[T[br[i][tr[i]].n]]).none());
      tr[i]++;
    }
  }
  for (int x = d; x <= r; x++) {
    int i = eu[x];
    dp[i].reset(), dp[i][i] = 1;
    i = ev[x];
    dp[i].reset(), dp[i][i] = 1;
  }
  solve(l, d - 1);
  solve(d + 1, r);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &eu[i], &ev[i]);
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d%d%d", &l, &r, &S[i], &T[i]);
    bl[l].push_back((query){r, i});
    br[r].push_back((query){l, i});
  }
  for (int i = 1; i <= n; i++) {
    sl[i] = bl[i].size();
    sort(bl[i].begin(), bl[i].end(), cmp);
    sr[i] = br[i].size();
    sort(br[i].begin(), br[i].end());
  }
  for (int i = 1; i <= n; i++) {
    dp[i].reset();
    dp[i][i] = 1;
  }
  solve(1, m);
  for (int i = 1; i <= q; i++) {
    puts(ans[i] ? "Yes" : "No");
  }
  return 0;
}
