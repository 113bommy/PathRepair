#include <bits/stdc++.h>
using namespace std;
const int maxn = 75005;
const int maxm = (1 << 15) + 5;
int k, n[16], s[16], a[16][5005], co[maxn], col[maxn], idx, b[maxn];
int st[maxn], cnt[16], vis[maxm], lst[maxm], from[maxm], sel[maxn];
int head[maxn], ecnt, d[maxn];
struct edge {
  int to, next;
} e[maxn << 1];
map<long long, int> id, ans;
long long sum[maxn];
vector<int> to, nxt;
void adde(int u, int v) {
  e[++ecnt].to = v;
  d[v]++;
  e[ecnt].next = head[u];
  head[u] = ecnt;
}
int read() {
  int res = 0, f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (!isdigit(ch));
  do {
    res = res * 10 + ch - '0';
    ch = getchar();
  } while (isdigit(ch));
  return res * f;
}
void topsort() {
  queue<int> q;
  for (int i = (1); i <= (s[k]); ++i)
    if (!d[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].to;
      d[v]--;
      if (!d[v]) q.push(v);
    }
  }
}
void dfs(int u) {
  col[u] = idx;
  st[idx] |= (1 << (co[u] - 1));
  cnt[co[u]]++;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (d[u] && !col[v]) dfs(v);
  }
}
signed main() {
  k = read();
  for (int i = (1); i <= (k); ++i) {
    n[i] = read();
    s[i] = s[i - 1] + n[i];
    for (int j = (1); j <= (n[i]); ++j)
      a[i][j] = read(), id[a[i][j]] = s[i - 1] + j, co[id[a[i][j]]] = i,
      b[id[a[i][j]]] = a[i][j], sum[i] += a[i][j];
    sum[0] += sum[i];
  }
  if (sum[0] % k != 0) {
    puts("No");
    return 0;
  }
  sum[0] /= k;
  for (int i = (1); i <= (k); ++i)
    for (int j = (1); j <= (n[i]); ++j) {
      int x = (sum[0] - (sum[i] - a[i][j]));
      if (id[x] == 0 || (co[id[a[i][j]]] == co[id[x]] && id[a[i][j]] != id[x]))
        continue;
      adde(id[a[i][j]], id[x]);
    }
  topsort();
  for (int i = (1); i <= (s[k]); ++i) {
    if (d[i] && !col[i]) {
      ++idx;
      memset(cnt, 0, sizeof(cnt));
      dfs(i);
      for (int j = (1); j <= (k); ++j)
        if (cnt[j] > 1) st[idx] = 0;
    }
  }
  vis[0] = 1;
  to.push_back(0);
  int S = (1 << k) - 1;
  for (int i = (1); i <= (idx); ++i) {
    if (!st[i]) continue;
    nxt.clear();
    for (int x : to) {
      if (x & st[i]) continue;
      if (vis[x | st[i]]) continue;
      vis[x | st[i]] = 1;
      lst[x | st[i]] = x;
      from[x | st[i]] = i;
      nxt.push_back(x | st[i]);
    }
    for (int x : nxt) to.push_back(x);
  }
  if (!vis[S]) {
    puts("No");
    return 0;
  }
  puts("Yes");
  int tmp = S;
  while (tmp) sel[from[tmp]] = 1, tmp = lst[tmp];
  for (int u = (1); u <= (s[k]); ++u)
    if (sel[col[u]])
      for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (d[v]) ans[b[v]] = co[u];
      }
  for (int i = (1); i <= (k); ++i)
    for (int j = (1); j <= (n[i]); ++j)
      if (ans[a[i][j]]) printf("%d %d\n", a[i][j], ans[a[i][j]]);
}
