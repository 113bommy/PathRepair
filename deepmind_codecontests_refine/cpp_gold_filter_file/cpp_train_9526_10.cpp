#include <bits/stdc++.h>
using namespace std;
int const M = 1e5 + 1000, M2 = 5e5 + 10, mod = 1e9 + 7, mod2 = 1e9 + 9,
          inf = 1e9 + 30, sq = 180;
int cntt = 0, f[M], ind, idd[M], q[M], tim = 0, n, st[M], fin[M], sv2[M * 2];
long long cnt[M];
long long dp[sq + 503];
int ta[M * 2];
long long sum[sq + 503], ans[M * 2];
vector<int> need[M];
vector<long long> fir[M];
vector<int> hlp[M];
int sv[M * 2];
int nxt[27][M];
string y[M];
vector<int> adj[M], to[M], ch[M];
void add(int now, string &tmp, int id) {
  ch[now].push_back(ind);
  if (id == tmp.size()) {
    idd[ind] = now;
    to[now].push_back(ind);
    return;
  }
  int t = tmp[id] - 'a';
  if (!nxt[t][now]) nxt[t][now] = ++cntt;
  add(nxt[t][now], tmp, id + 1);
}
void ahu() {
  int head = 0, tail = 0;
  for (int j = 0; j < 26; j++) {
    if (nxt[j][0]) q[head++] = nxt[j][0];
  }
  while (head > tail) {
    int v = q[tail++];
    for (int j = 0; j < 26; j++) {
      if (nxt[j][v]) {
        f[nxt[j][v]] = nxt[j][f[v]];
        q[head++] = nxt[j][v];
      } else
        nxt[j][v] = nxt[j][f[v]];
    }
    adj[f[v]].push_back(v);
  }
}
void dfs(int v) {
  st[v] = ++tim;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    dfs(u);
  }
  fin[v] = tim;
}
void ne(int l, int ind, int qu) {
  int now = -1;
  while (true) {
    if ((now + 2) * sq - 1 <= l)
      now++;
    else
      break;
  }
  ta[qu] = now;
  if (now != -1) need[ind].push_back(now);
  int en = (now + 1) * sq;
  for (int j = en; j <= l; j++) {
    if (j != 0) hlp[idd[j]].push_back(qu);
  }
}
void upd(int bl, int inc) {
  sum[bl] += (long long)inc;
  for (int i = 0; i <= 600; i++) {
    dp[i] = sum[i];
    if (i != 0) dp[i] += dp[i - 1];
  }
}
void dfs_ans(int v) {
  for (int i = 0; i < to[v].size(); i++) {
    int tmp = to[v][i];
    int bl = tmp / sq;
    upd(bl, (long long)1);
  }
  for (int i = 0; i < ch[v].size(); i++) {
    int tmp = ch[v][i];
    for (int j = 0; j < need[tmp].size(); j++) {
      fir[tmp][j] += dp[need[tmp][j]];
    }
  }
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    dfs_ans(u);
  }
  for (int i = 0; i < to[v].size(); i++) {
    int tmp = to[v][i];
    int bl = tmp / sq;
    upd(bl, -(long long)1);
  }
}
void dfs_en(int v) {
  for (int i = 0; i < hlp[v].size(); i++) {
    int t = hlp[v][i];
    ans[hlp[v][i]] -= cnt[sv2[t]];
  }
  for (int i = 0; i < ch[v].size(); i++) cnt[ch[v][i]]++;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    dfs_en(u);
  }
  for (int i = 0; i < hlp[v].size(); i++) {
    int t = hlp[v][i];
    ans[hlp[v][i]] += cnt[sv2[t]];
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int qq;
  cin >> n >> qq;
  for (int i = 1; i <= n; i++) {
    ind = i;
    cin >> y[i];
    add(0, y[i], 0);
  }
  ahu();
  dfs(0);
  for (int i = 1; i <= qq; i++) {
    int l, r, ind;
    cin >> l >> r >> ind;
    sv2[i * 2] = ind;
    sv2[i * 2 - 1] = ind;
    sv[i * 2 - 1] = l - 1;
    sv[i * 2] = r;
    ne(l - 1, ind, i * 2 - 1);
    ne(r, ind, i * 2);
  }
  for (int i = 1; i <= n; i++) {
    vector<int> tmp;
    sort(need[i].begin(), need[i].end());
    for (int j = 0; j < need[i].size(); j++) {
      if (j == 0 || need[i][j] != need[i][j - 1]) tmp.push_back(need[i][j]);
    }
    need[i].clear();
    for (int j = 0; j < tmp.size(); j++)
      need[i].push_back(tmp[j]), fir[i].push_back(0);
  }
  dfs_ans(0);
  dfs_en(0);
  for (int i = 1; i <= 2 * qq; i++) {
    int h = ta[i];
    if (h == -1) continue;
    int ind = lower_bound(need[sv2[i]].begin(), need[sv2[i]].end(), h) -
              need[sv2[i]].begin();
    ans[i] += fir[sv2[i]][ind];
  }
  for (int i = 1; i <= qq; i++) cout << ans[i * 2] - ans[i * 2 - 1] << "\n";
}
