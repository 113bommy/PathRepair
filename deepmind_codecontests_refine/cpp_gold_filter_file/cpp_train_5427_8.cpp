#include <bits/stdc++.h>
using namespace std;
vector<long long> adj[100005];
long long sn[100005], an[100005], level[100005];
long long got = 1;
void dfs(long long u, long long par, long long carry) {
  if (sn[u] != -1 && sn[u] < carry) got = 0;
  level[u] = level[par] + 1;
  if (sn[u] != -1) {
    an[u] = sn[u] - carry;
    carry = sn[u];
  } else
    an[u] = 0;
  for (auto it : adj[u]) {
    if (it != par) dfs(it, u, carry);
  }
}
void dfs2(long long u, long long par, long long carry) {
  if (level[u] & 1) {
    if (u != 1) {
      an[u] = sn[u] - carry;
      carry = sn[u];
    }
  } else {
    long long mn = 1e15 + 7;
    for (auto it : adj[u])
      if (it != par) mn = min(mn, sn[it]);
    if (mn != 1e15 + 7) {
      an[u] = mn - carry;
      carry = mn;
    } else
      an[u] = 0;
  }
  for (auto it : adj[u])
    if (it != par) dfs2(it, u, carry);
}
int main() {
  long long i, j, k;
  long long n, m;
  cin >> n;
  for (i = 2; i <= n; i++) {
    cin >> m;
    adj[m].push_back(i);
    adj[i].push_back(m);
  }
  for (i = 1; i <= n; i++) cin >> sn[i];
  dfs(1, 0, sn[1]);
  if (!got) {
    cout << -1 << endl;
    return 0;
  }
  dfs2(1, 0, sn[1]);
  an[1] = sn[1];
  long long ans = 0;
  for (i = 1; i <= n; i++) ans += an[i];
  cout << ans << endl;
  return 0;
}
