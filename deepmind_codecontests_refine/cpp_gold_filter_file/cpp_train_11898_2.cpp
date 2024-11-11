#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 6;
namespace AC {
int tot, tr[N][26];
int fail[N];
int cnt[N];
int sid[N];
int next[N];
bool vis[N];
int isend[N];
int in[N];
int val[N];
int victim[N];
queue<int> q;
void init() {
  memset(fail, 0, sizeof(fail));
  memset(tr, 0, sizeof(tr));
  memset(cnt, 0, sizeof(cnt));
  memset(vis, false, sizeof vis);
  memset(sid, 0, sizeof sid);
  memset(val, 0, sizeof val);
  memset(isend, 0, sizeof isend);
  memset(victim, 0, sizeof victim);
  memset(next, 0, sizeof next);
  tot = 0;
}
void insert(char *s, int id) {
  int u = 0;
  for (int i = 1; s[i]; i++) {
    if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;
    u = tr[u][s[i] - 'a'];
  }
  sid[id] = u;
  isend[u] = true;
}
void build() {
  next[0] = 0;
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) q.push(tr[0][i]);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (tr[u][i]) {
        fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
        in[fail[tr[u][i]]] += 1;
      } else
        tr[u][i] = tr[fail[u]][i];
      next[tr[u][i]] =
          isend[fail[tr[u][i]]] ? fail[tr[u][i]] : next[fail[tr[u][i]]];
    }
  }
}
int query(char *t) {
  int u = 0, res = -1;
  for (int i = 1; t[i]; i++) {
    u = tr[u][t[i] - 'a'];
    for (int x = u; x; x = next[x]) {
      if (isend[x]) {
        res = max(res, victim[x]);
      }
    }
  }
  return res;
}
void query(char *t, int) {
  int u = 0;
  for (int i = 1; t[i]; i++) {
    u = tr[u][t[i] - 'a'];
    val[u] += 1;
  }
}
void topoSort() {
  for (int i = 0; i < N; ++i)
    if (in[i] == 0) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int v = fail[u];
    in[v]--;
    val[v] += val[u];
    if (in[v] == 0) q.push(v);
  }
}
}  // namespace AC
char s[N];
int val[N];
map<int, int> mp[N];
int main() {
  int ans = 0;
  int n, m;
  cin >> n >> m;
  AC::init();
  for (int i = 0; i < n; i++) {
    scanf("%s", s + 1);
    AC::insert(s, i);
    mp[AC::sid[i]][0] += 1;
  }
  AC::build();
  while (m--) {
    int x, c, v;
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d %d", &c, &v);
      mp[AC::sid[c - 1]][val[c - 1]] -= 1;
      if (mp[AC::sid[c - 1]][val[c - 1]] == 0) {
        mp[AC::sid[c - 1]].erase(val[c - 1]);
      }
      val[c - 1] = v;
      mp[AC::sid[c - 1]][v] += 1;
      AC::victim[AC::sid[c - 1]] = (*--mp[AC::sid[c - 1]].end()).first;
      continue;
    }
    scanf("%s", s + 1);
    cout << AC::query(s) << endl;
  }
  return 0;
}
