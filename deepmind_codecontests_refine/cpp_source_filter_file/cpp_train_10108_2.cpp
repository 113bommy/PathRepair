#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > g;
vector<long long> type;
vector<long long> val;
vector<long long> ans;
long long global_ans;
long long dfs1(long long v) {
  if (g[v].size() == 0) {
    return val[v];
  }
  if (type[v] == 2) {
    return val[v] = !dfs1(g[v][0]);
  } else if (type[v] == 3) {
    return val[v] = (dfs1(g[v][0]) & dfs1(g[v][1]));
  } else if (type[v] == 4) {
    return val[v] = (dfs1(g[v][0]) | dfs1(g[v][1]));
  } else {
    return val[v] = (dfs1(g[v][0]) ^ dfs1(g[v][1]));
  }
}
void dfs(long long v, bool flag) {
  if (g[v].size() == 0) {
    if (flag) {
      ans[v] = !global_ans;
    } else {
      ans[v] = global_ans;
    }
    return;
  }
  if (!flag) {
    for (long long i = 0; i < g[v].size(); i++) {
      dfs(g[v][i], flag);
    }
    return;
  }
  if (type[v] == 2) {
    dfs(g[v][0], flag);
  } else if (type[v] == 3) {
    if (val[g[v][0]] == 1 && val[g[v][1]] == 1) {
      dfs(g[v][0], flag);
      dfs(g[v][1], flag);
    }
    if (val[g[v][0]] == 0 && val[g[v][1]] == 1) {
      dfs(g[v][0], flag);
      dfs(g[v][1], false);
    }
    if (val[g[v][0]] == 1 && val[g[v][1]] == 0) {
      dfs(g[v][0], false);
      dfs(g[v][1], flag);
    }
    if (val[g[v][0]] == 0 && val[g[v][1]] == 0) {
      dfs(g[v][0], false);
      dfs(g[v][1], false);
    }
  } else if (type[v] == 4) {
    if (val[g[v][0]] == 0 && val[g[v][1]] == 0) {
      dfs(g[v][0], flag);
      dfs(g[v][1], flag);
    }
    if (val[g[v][0]] == 0 && val[g[v][1]] == 1) {
      dfs(g[v][0], false);
      dfs(g[v][1], flag);
    }
    if (val[g[v][0]] == 1 && val[g[v][0]] == 0) {
      dfs(g[v][0], flag);
      dfs(g[v][1], false);
    }
    if (val[g[v][0]] == 1 && val[g[v][1]] == 1) {
      dfs(g[v][0], false);
      dfs(g[v][1], false);
    }
  } else {
    dfs(g[v][0], flag);
    dfs(g[v][1], flag);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  val.resize(n);
  ans.resize(n);
  g.resize(n);
  type.resize(n);
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "IN") {
      cin >> val[i];
      type[i] = 1;
    } else if (s == "NOT") {
      type[i] = 2;
      long long pred;
      cin >> pred;
      pred--;
      g[i].push_back(pred);
    } else {
      long long l, r;
      cin >> l >> r;
      l--;
      r--;
      g[i].push_back(l);
      g[i].push_back(r);
      if (s == "AND") {
        type[i] = 3;
      } else if (s == "OR") {
        type[i] = 4;
      } else {
        type[i] = 5;
      }
    }
  }
  dfs1(0);
  global_ans = val[0];
  dfs(0, true);
  for (long long i = 0; i < n; i++) {
    if (type[i] == 1) {
      cout << ans[i];
    }
  }
  return 0;
}
