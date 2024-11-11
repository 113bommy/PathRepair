#include <bits/stdc++.h>
using namespace std;
const int OO = 1e9 + 9;
const int MAX = 1e5 + 9;
int n, m, freq[MAX], dp[2][77779];
vector<int> adj[MAX];
vector<pair<int, int> > a;
bool vis[MAX];
template <typename T>
void Minimize(T& a, T b) {
  a = min(a, b);
}
void Add(int cnt, int x) {
  int p = 1, sum = 0;
  while (sum < cnt) {
    if (sum + p <= cnt) {
      a.push_back({p * x, p});
    } else {
      int more = cnt - sum;
      a.push_back({more * x, more});
      break;
    }
    sum += p;
    p *= 2;
  }
}
bool Lucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) {
      return 0;
    }
    x /= 10;
  }
  return 1;
}
int Dfs(int cur) {
  vis[cur] = 1;
  int cnt = 1;
  for (int i = 0; i < adj[cur].size(); ++i) {
    int child = adj[cur][i];
    if (!vis[child]) {
      cnt += Dfs(child);
    }
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      ++freq[Dfs(i)];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (freq[i]) {
      Add(freq[i], i);
    }
  }
  const int sz = a.size();
  for (int j = 0; j <= n; ++j) {
    dp[0][j] = OO;
  }
  bool cur = 0;
  dp[0][0] = 0;
  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[cur ^ 1][j] = OO;
    }
    for (int j = 0; j <= n; ++j) {
      if (dp[cur][j] == OO) {
        continue;
      }
      int subsetSize = j + a[i].first, cost = dp[cur][j] + a[i].second;
      Minimize(dp[cur ^ 1][subsetSize], cost);
      Minimize(dp[cur ^ 1][j], dp[cur][j]);
    }
    cur ^= 1;
  }
  int mn = OO;
  for (int i = 1; i <= n; ++i) {
    if (dp[cur][i] == OO || !Lucky(i)) {
      continue;
    }
    mn = min(mn, dp[cur][i]);
  }
  cout << (mn == OO ? -1 : mn - 1);
  return 0;
}
