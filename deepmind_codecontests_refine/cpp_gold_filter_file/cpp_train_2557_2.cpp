#include <bits/stdc++.h>
using namespace std;
bool visit[1000005];
vector<long long> adj[1000005];
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
int dfs(long long x) {
  int ans = 1;
  for (int i = 0; i < adj[x].size(); i++) {
    if (!visit[adj[x][i]]) {
      visit[adj[x][i]] = 1;
      ans += dfs(adj[x][i]);
    }
  }
  return ans;
}
int n, m, k;
int main() {
  read(n), read(m), read(k);
  for (int i = 0; i < m; i++) {
    int x, y;
    read(x), read(y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  long long l = 0, o = 0;
  for (int i = 1; i <= n; i++) {
    if (!visit[i]) {
      visit[i] = 1;
      l += min(dfs(i), k);
      o++;
    }
  }
  if (k == 1) {
    cout << max(0LL, o - 2);
    return 0;
  } else {
    long long ans = o - 1 - l / 2;
    if (ans < 0)
      cout << 0;
    else
      cout << o - 1 - l / 2;
  }
  return 0;
}
