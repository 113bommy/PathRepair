#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
vector<string> type;
vector<vector<int> > edge;
vector<bool> ans;
void dfs(int u) {
  if (type[u] == "IN") {
    ans[u] = edge[u][0];
    return;
  }
  if (type[u] == "NOT") {
    dfs(edge[u][0]);
    ans[u] = !ans[edge[u][0]];
    return;
  }
  dfs(edge[u][0]);
  dfs(edge[u][1]);
  if (type[u] == "AND") {
    ans[u] = ans[edge[u][0]] & ans[edge[u][1]];
  }
  if (type[u] == "OR") {
    ans[u] = ans[edge[u][0]] | ans[edge[u][1]];
  }
  if (type[u] == "XOR") {
    ans[u] = ans[edge[u][0]] ^ ans[edge[u][1]];
  }
}
void dfs2(int u, vector<int>& a) {
  if (type[u] == "IN") {
    a.push_back(u);
    return;
  }
  if (type[u] == "NOT") {
    dfs2(edge[u][0], a);
    return;
  }
  bool l = ans[edge[u][0]];
  bool r = ans[edge[u][1]];
  int x = edge[u][0];
  int y = edge[u][1];
  if (type[u] == "AND") {
    if (!l && r) {
      dfs2(x, a);
    }
    if (l && !r) {
      dfs2(y, a);
    }
    if (l && r) {
      dfs2(x, a);
      dfs2(y, a);
    }
  }
  if (type[u] == "OR") {
    if (!r && !l) {
      dfs2(x, a);
      dfs2(y, a);
    }
    if (!l && r) {
      dfs2(y, a);
    }
    if (l && !r) {
      dfs2(x, a);
    }
  }
  if (type[u] == "XOR") {
    dfs2(x, a);
    dfs2(y, a);
  }
}
int main() {
  int n = nxt();
  type.resize(n);
  edge.resize(n);
  ans.resize(n);
  vector<int> q;
  for (int i = 0; i < n; i++) {
    cin >> type[i];
    if (type[i] == "IN") {
      edge[i].push_back(nxt());
      q.push_back(i);
    } else if (type[i] == "NOT") {
      edge[i].push_back(nxt() - 1);
    } else {
      edge[i].push_back(nxt() - 1);
      edge[i].push_back(nxt() - 1);
    }
  }
  dfs(0);
  vector<int> req;
  dfs2(0, req);
  set<int> s;
  for (int x : req) s.insert(x);
  for (int x : q) {
    if (s.count(x))
      printf("%d", ans[0] ^ 1 ? 1 : 0);
    else
      printf("%d", ans[0] ? 1 : 0);
  }
  return 0;
}
