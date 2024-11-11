#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
const int mod = 1e9 + 7;
vector<int> adj[2 * N];
pair<int, int> lis[N], idx[N], lis1[N];
bool used[N];
int pw2[2 * N], ver, edge;
void dfs(int x) {
  used[x] = true;
  ver++;
  edge += adj[x].size();
  for (int i : adj[x]) {
    if (!used[i]) {
      dfs(i);
    }
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, i, j, k, l, cnt = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> lis[i].first >> lis1[i].first;
    lis[i].second = lis1[i].second = i;
  }
  sort(lis + 1, lis + 1 + n);
  sort(lis1 + 1, lis1 + 1 + n);
  i = j = 1;
  while (i <= n) {
    while (j <= n && lis[j].first == lis[i].first) {
      j++;
    }
    cnt++;
    for (k = i; k < j; k++) {
      idx[lis[k].second].first = cnt;
    }
    i = j;
  }
  i = j = 1;
  while (i <= n) {
    while (j <= n && lis1[j].first == lis1[i].first) {
      j++;
    }
    cnt++;
    for (k = i; k < j; k++) {
      idx[lis1[k].second].second = cnt;
    }
    i = j;
  }
  pw2[0] = 1;
  for (i = 1; i <= cnt; i++) {
    pw2[i] = (pw2[i - 1] * 2) % mod;
  }
  for (i = 1; i <= n; i++) {
    adj[idx[i].first].push_back(idx[i].second);
    adj[idx[i].second].push_back(idx[i].first);
  }
  long long ans = 1;
  for (i = 1; i <= cnt; i++) {
    if (!used[i]) {
      ver = edge = 0;
      dfs(i);
      edge >>= 1;
      if (edge == ver - 1) {
        ans *= (pw2[ver] - 1);
      } else {
        ans *= pw2[ver];
      }
      ans %= mod;
    }
  }
  cout << ans;
}
