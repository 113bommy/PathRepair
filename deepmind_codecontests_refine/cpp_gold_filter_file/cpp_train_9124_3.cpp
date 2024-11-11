#include <bits/stdc++.h>
using namespace std;
const int maxnode = 1e5 + 2;
int ch[maxnode][26];
int dep[maxnode];
bool ed[maxnode];
int node = 1;
int newnode(int lst) {
  int now = ++node;
  dep[now] = dep[lst] + 1;
  return now;
}
void insert(std::string s) {
  int p = 1;
  for (auto i : s) {
    int c = i - 'a';
    if (!ch[p][c]) {
      ch[p][c] = newnode(p);
    }
    p = ch[p][c];
  }
  ed[p] = true;
}
std::multiset<int> s[maxnode];
void merge(int u, int v) {
  if ((int)s[u].size() > (int)s[v].size()) {
    std::swap(s[u], s[v]);
  }
  for (auto i : s[v]) {
    s[u].insert(i);
  }
  s[v].clear();
}
int answer = 0;
void dfs(int u) {
  for (int i = 0; i < 26; i++) {
    if (ch[u][i]) {
      dfs(ch[u][i]);
      merge(u, ch[u][i]);
    }
  }
  if (u == 1) {
    return;
  }
  if (ed[u]) {
    answer += dep[u];
    s[u].insert(dep[u]);
    return;
  }
  answer -= *s[u].rbegin();
  s[u].erase(--s[u].end());
  answer += dep[u];
  s[u].insert(dep[u]);
}
int main() {
  int n;
  cin >> n;
  std::string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    insert(str);
  }
  dfs(1);
  cout << answer << '\n';
  return 0;
}
