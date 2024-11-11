#include <bits/stdc++.h>
using namespace std;
int n;
int td[1000009];
int ht[1000009];
vector<int> adj[1000009];
long long dp[2][1000009];
int in[1000009];
int out[1000009];
void dfs(int idx, int p) {
  for (auto it : adj[idx]) {
    if (it == p) continue;
    if (ht[idx] < ht[it]) {
      out[idx]++;
      in[it]++;
    } else if (ht[idx] > ht[it]) {
      in[idx]++;
      out[it]++;
    }
    dfs(it, idx);
  }
  return;
}
void solve(int idx, int p, int add) {
  vector<long long> st;
  long long fix = 0;
  int i = in[idx], o = out[idx];
  if (add == 1) i++;
  if (add == 2) o++;
  for (auto it : adj[idx]) {
    if (it == p) continue;
    if (ht[idx] < ht[it]) {
      solve(it, idx, 0);
      fix += dp[0][it];
    } else if (ht[idx] > ht[it]) {
      solve(it, idx, 0);
      fix += dp[0][it];
    } else {
      if (dp[0][it] == 0) {
        solve(it, idx, 1);
        solve(it, idx, 2);
      }
      st.push_back(dp[0][it] - dp[1][it]);
      fix += dp[1][it];
    }
  }
  sort(st.begin(), st.end());
  i += st.size();
  fix += max(i, o) * td[idx];
  long long tdp = fix;
  for (int k = 0; k < st.size(); k++) {
    if (i > o + 1)
      fix -= td[idx];
    else if (i <= o)
      fix += td[idx];
    i--;
    o++;
    fix += st[k];
    tdp = min(tdp, fix);
  }
  if (add == 0 || add == 1) dp[0][idx] = tdp;
  if (add == 2) dp[1][idx] = tdp;
  return;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &td[i]);
  for (int i = 0; i < n; i++) scanf("%d", &ht[i]);
  for (int i = 0; i < n - 1; i++) {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    v1--;
    v2--;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }
  dfs(0, -1);
  solve(0, -1, 0);
  printf("%lld", dp[0][0]);
  return 0;
}
