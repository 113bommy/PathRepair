#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
const int MAXN = 30;
int a[MAXN], fa[MAXN], mark[MAX], vis[MAX];
vector<int> G[MAX];
string ans;
string strs[MAX];
void init() {
  ans.clear();
  memset(mark, -1, sizeof(mark));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < MAX; i++) {
    G[i].clear();
  }
}
bool build(string s, int c) {
  int len = s.length();
  if (len > 26) {
    return false;
  }
  memset(a, 0, sizeof(a));
  for (int i = 0; i < len; i++) {
    int k = s[i] - 'a';
    if (a[k] > 0) {
      return false;
    }
    a[k] = 1;
    if (mark[k] != -1) {
      G[c].push_back(mark[k]);
      G[mark[k]].push_back(c);
    } else {
      mark[k] = c;
    }
  }
  return true;
}
bool insert(string s) {
  if (ans.length() == 0) {
    ans = s;
    return true;
  }
  size_t len = ans.find(s[0]);
  if (len != ans.npos) {
    for (int i = len, j = 0; j < s.length(); j++) {
      if (i < ans.length() && ans[i] == s[j]) {
        i++;
      } else {
        ans.insert(i, s, j, s.length() - j);
        break;
      }
    }
  } else {
    len = s.find(ans[0]);
    if (len != s.npos) {
      for (int i = len, j = 0; j < ans.length(); j++) {
        if (s[i] == ans[j]) {
          i++;
        } else {
          s.insert(i, ans, j, ans.length() - j);
          break;
        }
      }
      ans = s;
    }
  }
  if (ans.length() > 26) {
    return false;
  }
  return true;
}
bool dfs(int u) {
  vis[u] = 1;
  if (!insert(strs[u])) {
    return false;
  }
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (vis[v]) {
      continue;
    }
    if (!dfs(v)) {
      return false;
    }
  }
  return true;
}
bool solve(int n) {
  memset(a, 0, sizeof(a));
  for (int i = 0; i < ans.length(); i++) {
    if (a[ans[i] - 'a'] > 0) {
      return false;
    }
    a[ans[i] - 'a'] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (ans.find(strs[i]) == ans.npos) {
      return false;
    }
  }
  return true;
}
int main(int argc, char const *argv[]) {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      cin >> strs[i];
    }
    init();
    bool ok = true;
    for (int i = 0; i < n; i++) {
      ok = ok && (build(strs[i], i));
      if (!ok) {
        break;
      }
    }
    if (!ok) {
      printf("NO\n");
      continue;
    }
    bool res = true;
    int cnt = 0;
    string rst[MAXN];
    for (int i = 0; i < n; i++)
      if (!vis[i]) {
        ans.clear();
        res = res && dfs(i);
        if (!res) {
          break;
        }
        rst[cnt++] = ans;
      }
    if (!res) {
      printf("NO\n");
      continue;
    }
    ans.clear();
    sort(rst, rst + cnt);
    for (int i = 0; i < cnt; i++) {
      ans = ans + rst[i];
    }
    if (solve(n)) {
      cout << ans << endl;
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
