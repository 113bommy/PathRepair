#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MOD = 1000000007;
int N, K;
int A[200005];
vector<int> adj[200005];
int siz[200005], sum[200005], len[200005];
int sub[200005], dp[200005];
void dfs(int n, int par, int mid) {
  siz[n] = 1;
  for (int nxt : adj[n]) {
    if (nxt != par) {
      dfs(nxt, n, mid);
      siz[n] += siz[nxt];
      if (siz[nxt] == sub[nxt])
        sum[n] += sub[nxt];
      else
        len[n] = max(len[n], sub[nxt]);
    }
  }
  sub[n] = sum[n] + len[n] + 1;
  if (A[n] < mid) sub[n] = 0;
}
void dfs2(int n, int par, int par_sub, int mid) {
  if (par_sub == N - siz[n])
    dp[n] = sum[n] + par_sub + len[n] + 1;
  else
    dp[n] = sum[n] + max(len[n], par_sub) + 1;
  if (A[n] < mid) dp[n] = 0;
  int cnt = adj[n].size();
  vector<int> l_sum(cnt + 2);
  vector<int> l_len(cnt + 2);
  for (int i = 1; i <= cnt; i++) {
    int nxt = adj[n][i - 1];
    l_sum[i] = l_sum[i - 1];
    l_len[i] = l_len[i - 1];
    if (nxt != par) {
      if (siz[nxt] == sub[nxt])
        l_sum[i] += sub[nxt];
      else
        l_len[i] = max(l_len[i], sub[nxt]);
    }
  }
  vector<int> r_sum(cnt + 2);
  vector<int> r_len(cnt + 2);
  for (int i = cnt; i >= 1; i--) {
    int nxt = adj[n][i - 1];
    r_sum[i] = r_sum[i + 1];
    r_len[i] = r_len[i + 1];
    if (nxt != par) {
      if (siz[nxt] == sub[nxt])
        r_sum[i] += sub[nxt];
      else
        r_len[i] = max(r_len[i], sub[nxt]);
    }
  }
  for (int i = 1; i <= cnt; i++) {
    int nxt = adj[n][i - 1];
    if (nxt != par) {
      int nxt_par_sub = 0;
      int p_sum = l_sum[i - 1] + r_sum[i + 1];
      int p_len = max(l_len[i - 1], r_len[i + 1]);
      if (par_sub == N - siz[n])
        nxt_par_sub = p_sum + par_sub + p_len + 1;
      else
        nxt_par_sub = p_sum + max(p_len, par_sub) + 1;
      if (A[n] < mid) nxt_par_sub = 0;
      dfs2(nxt, n, nxt_par_sub, mid);
    }
  }
}
bool foo(int mid) {
  memset(siz, 0, sizeof(siz));
  memset(sum, 0, sizeof(sum));
  memset(len, 0, sizeof(len));
  memset(sub, 0, sizeof(sub));
  memset(dp, 0, sizeof(dp));
  dfs(1, 0, mid);
  dfs2(1, 0, 0, mid);
  int best = 0;
  for (int i = 1; i <= N; i++) best = max(best, dp[i]);
  return best >= K;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int lo = 0, hi = 1000005;
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    if (foo(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << lo << '\n';
}
