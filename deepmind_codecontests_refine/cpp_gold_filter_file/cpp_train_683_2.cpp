#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 * 3 + 3;
struct node {
  map<char, int> next;
  int link, len, cl;
};
int n;
int sz, last;
node s[MAXN];
int cnt[MAXN];
void init() {
  for (int i = 0; i < sz; i++) {
    s[i].next.clear();
    s[i].link = -1;
    s[i].len = 0;
    s[i].cl = 0;
    cnt[i] = 0;
  }
  s[0].link = -1;
  s[0].len = 0;
  s[0].cl = 0;
  sz = 1;
  last = 0;
}
void append(char c) {
  int cur = sz++;
  s[cur].len = s[last].len + 1;
  int p = last;
  s[cur].cl = 0;
  while (p != -1 && !s[p].next.count(c)) {
    s[p].next[c] = cur;
    p = s[p].link;
  }
  if (p == -1) {
    s[cur].link = 0;
  } else {
    int q = s[p].next[c];
    if (s[p].len + 1 == s[q].len) {
      s[cur].link = q;
    } else {
      int clone = sz++;
      s[clone].next = s[q].next;
      s[clone].link = s[q].link;
      s[clone].len = s[p].len + 1;
      s[clone].cl = 1;
      while (p != -1 && s[p].next[c] == q) {
        s[p].next[c] = clone;
        p = s[p].link;
      }
      s[q].link = s[cur].link = clone;
    }
  }
  last = cur;
}
char str[MAXN];
void read_input() {
  scanf("%s", str);
  n = strlen(str);
}
struct state {
  int v, len;
  state(int _v, int _len) {
    v = _v;
    len = _len;
  }
  bool operator<(state other) const { return len > other.len; }
};
vector<state> ve;
bool vis[MAXN];
void dfs(int v, int p) {
  vis[v] = true;
  if (!s[v].cl && v != 0) {
    cnt[v] = 1;
  }
  ve.push_back(state(v, s[v].len));
  for (auto x : s[v].next) {
    if (!vis[x.second]) dfs(x.second, v);
  }
}
long long T[MAXN];
long long rec(int v) {
  if (T[v]) return T[v];
  long long ans = 0;
  for (auto x : s[v].next) {
    ans += rec(x.second);
  }
  if (v == 0) cnt[v] = 0;
  return T[v] = ans + (1LL * cnt[v] * cnt[v]);
}
void solve() {
  for (int i = 0; i < sz; i++) {
    T[i] = 0;
    vis[i] = false;
  }
  ve.clear();
  dfs(0, 0);
  sort(ve.begin(), ve.end());
  for (int i = 0; i < ve.size(); i++) {
    if (s[ve[i].v].link == -1) continue;
    cnt[s[ve[i].v].link] += cnt[ve[i].v];
  }
  printf("%lld\n", rec(0));
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    read_input();
    init();
    for (int i = 0; i < n; i++) {
      append(str[i]);
    }
    solve();
  }
  return 0;
}
