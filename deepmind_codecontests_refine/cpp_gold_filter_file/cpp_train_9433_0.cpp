#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 100;
vector<int> node[N];
char s[N];
int fail[N], trie[N][26], deep[N], dp[N][2], cnt;
bool vis[N];
int newnode() {
  cnt++;
  for (int i = 0; i < 26; i++) trie[cnt][i] = 0;
  return cnt;
}
void insert_word() {
  int len = strlen(s + 1);
  int pos = 0;
  for (int i = 1; i <= len; i++) {
    int to = s[i] - 'a';
    if (!trie[pos][to]) {
      trie[pos][to] = newnode();
      deep[trie[pos][to]] = i;
    }
    pos = trie[pos][to];
  }
}
void getfail() {
  queue<int> q;
  for (int i = 0; i < 26; i++) {
    if (trie[0][i]) {
      fail[trie[0][i]] = 0;
      q.push(trie[0][i]);
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (trie[cur][i]) {
        fail[trie[cur][i]] = trie[fail[cur]][i];
        q.push(trie[cur][i]);
      } else
        trie[cur][i] = trie[fail[cur]][i];
    }
  }
}
void build() {
  for (int i = 1; i <= cnt; i++) node[i].clear();
  for (int i = 1; i <= cnt; i++)
    if (fail[i] && deep[fail[i]] + 1 == deep[i]) {
      node[fail[i]].push_back(i);
      node[i].push_back(fail[i]);
    }
}
void dfs(int u, int fa) {
  vis[u] = true;
  dp[u][0] = 0, dp[u][1] = 1;
  for (auto v : node[u]) {
    if (v == fa) continue;
    dfs(v, u);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] += dp[v][0];
  }
}
void init() {
  cnt = -1;
  newnode();
}
int main() {
  int w;
  cin >> w;
  while (w--) {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s + 1);
      insert_word();
    }
    getfail();
    build();
    int ans = 0;
    memset(vis, false, cnt + 5);
    for (int i = 1; i <= cnt; i++)
      if (!vis[i]) {
        dfs(i, -1);
        ans += max(dp[i][0], dp[i][1]);
      }
    printf("%d\n", ans);
  }
  return 0;
}
