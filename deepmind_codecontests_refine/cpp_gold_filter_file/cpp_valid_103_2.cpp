#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 13;
int n, m, k;
bool e[MAXN][MAXN];
long long comb[MAXN][MAXN];
vector<vector<int> > R;
int p[13];
void dfs(int now, int mx) {
  if (now == n / 2 + 1) {
    vector<int> z;
    for (int i = 1; i <= n / 2; ++i) z.push_back(p[i] - 1);
    R.push_back(z);
    return;
  }
  for (int z = 1; z <= mx + 1; ++z) {
    p[now] = z;
    dfs(now + 1, max(z, mx));
  }
}
vector<vector<pair<int, int> > > R2;
bool used[MAXN];
void dfs2(int now) {
  if (now == n + 1) {
    vector<pair<int, int> > tmp;
    for (int i = 1; i <= n / 2; ++i) {
      tmp.push_back(make_pair(p[i] - 1, p[i + n / 2] - 1));
    }
    R2.push_back(tmp);
    return;
  }
  if (now <= n / 2) {
    for (int j = p[now - 1] + 1; j <= n; ++j) {
      p[now] = j;
      used[j] = 1;
      dfs2(now + 1);
      used[j] = 0;
    }
  } else {
    for (int j = p[now - n / 2] + 1; j <= n; ++j) {
      if (!used[j]) {
        p[now] = j;
        used[j] = 1;
        dfs2(now + 1);
        used[j] = 0;
      }
    }
  }
}
const int MOD = (1 << 22) - 1;
const unsigned int A = 10719;
struct Hashtable {
  vector<vector<int> > tmp;
  vector<int> nex;
  int fir[MOD + 1];
  Hashtable() { fill(fir, fir + MOD + 1, -1); }
  unsigned int ky(vector<int>& v) {
    unsigned int rest = 0;
    unsigned int AA = 1;
    for (auto it : v) {
      rest += AA * it;
      rest %= MOD;
      AA *= A;
    }
    return rest;
  }
  void insert(vector<int>& v) {
    int _ = ky(v);
    for (int now = fir[_]; now != -1; now = nex[now])
      if (tmp[now] == v) return;
    nex.push_back(fir[_]);
    fir[_] = tmp.size();
    tmp.push_back(v);
  }
} table;
int fa[MAXN], cnt[MAXN];
long long fact[MAXN];
int root(int x) { return fa[x] = (fa[x] == x ? x : root(fa[x])); }
void merge(int u, int v) {
  u = root(u);
  v = root(v);
  fa[min(u, v)] = max(u, v);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  fact[0] = 1;
  for (int i = 1; i <= 6; ++i) fact[i] = 1ll * i * fact[i - 1];
  dfs(1, 0);
  dfs2(1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    e[u][v] = e[v][u] = 1;
  }
  for (int i = 0; i <= k; ++i) comb[i][0] = 1;
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= k; ++j)
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
  bool dp[6][1 << 6];
  int pre[6];
  for (auto it : R2) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < it.size(); ++i)
      if (e[it[i].first][it[i].second]) dp[i][1 << i] = 1;
    for (int mask = 0; mask < 1 << it.size(); ++mask)
      for (int i = 0; i < it.size(); ++i)
        if (dp[i][mask]) {
          for (int j = 0; j < it.size(); ++j) {
            if ((mask >> j) & 1)
              ;
            else {
              int u1, v1, u2, v2;
              u1 = it[i].first, v1 = it[i].second;
              u2 = it[j].first, v2 = it[j].second;
              if ((e[u1][u2] && e[v1][v2]) || (e[u1][v2] && e[v1][u2]))
                dp[j][mask | (1 << j)] = 1;
            }
          }
        }
    bool ok = false;
    for (int i = 0; i < it.size(); ++i)
      if (dp[i][(1 << it.size()) - 1]) ok = 1;
    if (ok) {
      for (auto it2 : R) {
        fill(pre, pre + 6, -1);
        for (int i = 0; i < n; ++i) fa[i] = i;
        for (auto it3 : it) merge(it3.first, it3.second);
        for (int i = 0; i < it2.size(); ++i) {
          if (pre[it2[i]] == -1) {
            pre[it2[i]] = i;
            continue;
          }
          merge(it[pre[it2[i]]].first, it[i].first);
        }
        vector<int> Tmp;
        for (int i = 0; i < n; ++i) Tmp.push_back(root(i));
        table.insert(Tmp);
      }
    }
  }
  vector<vector<int> > H = table.tmp;
  long long answer = 0;
  for (auto ve : H) {
    memset(cnt, 0, sizeof(cnt));
    int nonz = 0;
    for (auto it : ve) {
      nonz += !cnt[it];
      cnt[it] = 1;
    }
    answer += fact[nonz] * comb[k][nonz];
  }
  cout << answer << endl;
  return 0;
}
