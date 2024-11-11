#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 1000;
int n, m;
vector<pair<int, char> > sons[N];
int trie[N][26], tot;
int ed[N];
int fail[N];
void insert(char *s, int &i) {
  int u = 0;
  for (char *t = s; *t; t++) {
    if (!trie[u][*t - 'a']) trie[u][*t - 'a'] = ++tot;
    u = trie[u][*t - 'a'];
  }
  ed[i] = u;
}
void build() {
  queue<int> q;
  for (int i = 0; i < 26; i++)
    if (trie[0][i]) q.push(trie[0][i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (trie[u][i])
        q.push(trie[u][i]), fail[trie[u][i]] = trie[fail[u]][i];
      else
        trie[u][i] = trie[fail[u]][i];
    }
  }
}
vector<int> nxt[N];
int size[N], id[N], dfsclock;
void dfs(int x) {
  id[x] = ++dfsclock;
  size[x] = 1;
  for (vector<int>::iterator it = nxt[x].begin(); it != nxt[x].end(); ++it)
    dfs(*it), size[x] += size[*it];
}
int tree[N];
void add(int pos, int x) {
  for (; pos <= n; pos += pos & -pos) tree[pos] += x;
}
int ask(int pos) {
  int res = 0;
  for (; pos; pos ^= pos & -pos) res += tree[pos];
  return res;
}
int ask(int l, int r) { return ask(r) - ask(l - 1); }
vector<int> query[N];
int ans[N];
void solve(int x, int f) {
  add(id[f], 1);
  for (vector<int>::iterator it = query[x].begin(); it != query[x].end();
       ++it) {
    int &node = ed[*it];
    ans[*it] = ask(id[node], id[node] + size[node] - 1);
  }
  for (vector<pair<int, char> >::iterator it = sons[x].begin();
       it != sons[x].end(); ++it)
    solve(it->first, trie[f][it->second - 'a']);
  add(id[f], -1);
}
char s[N];
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int op, father = 0;
    char c;
    scanf("%d", &op);
    if (op == 2) scanf("%d", &father);
    while ((c = getchar()) == ' ')
      ;
    sons[father].push_back(make_pair(i, c));
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int which;
    scanf("%d %s", &which, s);
    insert(s, i);
    query[which].push_back(i);
  }
  build();
  for (int i = 1; i <= tot; i++) nxt[fail[i]].push_back(i);
  dfs(0);
  solve(0, 0);
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
