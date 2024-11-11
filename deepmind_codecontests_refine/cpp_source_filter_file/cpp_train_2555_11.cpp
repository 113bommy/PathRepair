#include <bits/stdc++.h>
using namespace std;
struct Node {
  int chi[28], fail;
  int ed;
  Node() {
    memset(chi, 0, sizeof chi);
    fail = -1;
    ed = 0;
  }
};
Node node[205];
int cnt;
long long cost[205];
void insert(string &s, int co) {
  int v = 0, la = 0;
  for (int i = 0; i < s.size(); i++) {
    la = v;
    if (!node[v].chi[s[i] - 'a']) {
      node[v].chi[s[i] - 'a'] = cnt;
      cnt++;
    }
    v = node[v].chi[s[i] - 'a'];
  }
  cost[v] = co;
}
vector<int> nei[205];
void bfs() {
  queue<int> q;
  for (int i = 0; i < 26; i++) {
    if (node[0].chi[i]) {
      q.push(node[0].chi[i]);
      nei[0].push_back(node[0].chi[i]);
      node[node[0].chi[i]].fail = 0;
    }
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    cost[v] += cost[node[v].fail];
    for (int i = 0; i < 26; i++) {
      if (node[v].chi[i]) {
        q.push(node[v].chi[i]);
        node[node[v].chi[i]].fail = node[node[v].fail].chi[i];
        nei[v].push_back(node[v].chi[i]);
      } else {
        node[v].chi[i] = node[node[v].fail].chi[i];
        nei[v].push_back(node[node[v].fail].chi[i]);
      }
    }
  }
}
int c[205];
struct mat {
  long long a[205][205];
  int sz;
  mat() {
    memset(a, 0, sizeof a);
    sz = 0;
  }
  void init() {
    for (int i = 0; i < sz; i++) a[i][i] = 1;
  }
  mat operator*(mat b) const {
    mat res;
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        res.a[i][j] = a[i][j];
      }
    }
    res.sz = sz;
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        for (int k = 0; k < sz; k++) {
          res.a[i][j] = max(a[i][k] + b.a[k][j], res.a[i][j]);
        }
      }
    }
    return res;
  }
};
mat M, F;
void quickpow(long long times) {
  mat res;
  res.sz = M.sz;
  for (int i = 0; i <= res.sz; i++) {
    for (int j = 0; j <= res.sz; j++) {
      res.a[i][j] = -1e18;
    }
  }
  res.a[0][0] = 0;
  while (times) {
    if (times & 1) res = res * M;
    times >>= 1;
    M = M * M;
  }
  F = res;
}
int main() {
  int n;
  long long l;
  cnt = 1;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    insert(s, c[i]);
  }
  bfs();
  M.sz = cnt + 1;
  for (int i = 0; i <= cnt; i++) {
    for (int j = 0; j <= cnt; j++) {
      M.a[i][j] = -1e18;
    }
  }
  for (int i = 0; i <= cnt; i++) {
    for (int j = 0; j < nei[i].size(); j++) {
      if (!nei[i][j]) continue;
      M.a[i][nei[i][j]] = cost[nei[i][j]];
    }
  }
  quickpow(l);
  long long res = 0;
  for (int i = 1; i <= cnt; i++) {
    res = max(F.a[0][i], res);
  }
  cout << res;
}
