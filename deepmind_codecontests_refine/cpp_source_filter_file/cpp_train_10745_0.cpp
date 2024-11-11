#include <bits/stdc++.h>
using namespace std;
long long ksm(long long a, long long b) {
  if (!b) return 1;
  long long ns = ksm(a, b >> 1);
  ns = ns * ns % 1000000007;
  if (b & 1) ns = ns * a % 1000000007;
  return ns;
}
struct th {
  int r[5], fl;
  th() {
    memset(r, 0, sizeof(r));
    fl = 1;
  }
  bool operator<(const th &u) const {
    for (int j = 0; j < 5; j++)
      if (r[j] != u.r[j]) return r[j] < u.r[j];
    return 0;
  }
  void ins(int a) {
    for (int i = 4; i >= 0; i--) {
      if (a & (1 << i))
        if (r[i]) a ^= r[i];
    }
    if (!a) fl = 0;
    for (int i = 4; i >= 0; i--) {
      if (a & (1 << i)) {
        r[i] = a;
        for (int j = i + 1; j <= 4; j++)
          if (r[j] & (1 << i)) r[j] ^= a;
        return;
      }
    }
  }
  void ins(th &a) {
    for (int i = 4; i >= 0; i--)
      if (a.r[i]) ins(a.r[i]);
    if (!a.fl) fl = 0;
  }
  void otp() {
    for (int i = 0; i < 5; i++) cout << r[i] << ' ';
    cout << fl << endl;
  }
};
th cur[100005];
int us[100005];
int vis[100005];
vector<pair<int, int> > eg[100005];
int fl[100005];
int dep[100005], dd[100005], b[100005], fr[100005];
void dfs(int a, int fa, int bl) {
  fr[a] = fa, b[a] = bl;
  for (auto v : eg[a]) {
    if (fl[v.first] && fl[a]) continue;
    if (v.first == fa) continue;
    if (dd[v.first]) continue;
    dd[v.first] = dd[a] + 1;
    dep[v.first] = dep[a] ^ v.second;
    dfs(v.first, a, bl);
  }
}
int bg[17][9][5][3][2];
th tr[100005];
int cal(th r) {
  int s[5] = {0, 0, 0, 0, 0};
  for (int i = 4; i >= 0; i--)
    if (r.r[i])
      s[i] = r.r[i] - (1 << i) + 1;
    else
      s[i] = 0;
  return bg[s[4]][s[3]][s[2]][s[1]][s[0]];
}
map<th, int> id;
int idcnt = 0;
void init() {
  for (int i = 16; i >= 0; i--)
    for (int j = 8; j >= 0; j--)
      for (int k = 4; k >= 0; k--)
        for (int m = 2; m >= 0; m--)
          for (int l = 1; l >= 0; l--) {
            th cur;
            if (i) cur.ins(i + 16 - 1);
            if (j) cur.ins(j + 8 - 1);
            if (k) cur.ins(k + 4 - 1);
            if (m) cur.ins(m + 2 - 1);
            if (l) cur.ins(l + 1 - 1);
            if (!id[cur]) {
              id[cur] = ++idcnt;
              tr[idcnt] = cur;
            }
            bg[i][j][k][m][l] = id[cur];
          }
}
th uu[100005];
int nlp[100005];
int dp[100005][405];
int cnt = 0;
int u[100005], v[100005], w[100005];
int main() {
  init();
  int test = 0;
  int n, m;
  if (test)
    n = 100000, m = 99999;
  else
    scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    eg[u[i]].push_back(make_pair(v[i], w[i]));
    eg[v[i]].push_back(make_pair(u[i], w[i]));
  }
  for (auto v : eg[1]) fl[v.first] = 1;
  for (auto v : eg[1])
    dep[v.first] = v.second, dd[v.first] = 1, dfs(v.first, 1, v.first);
  for (int i = 0; i < m; i++)
    if (b[u[i]] == b[v[i]] && u[i] != fr[v[i]] && v[i] != fr[u[i]])
      cur[b[u[i]]].ins(dep[u[i]] ^ dep[v[i]] ^ w[i]);
  memset(vis, 0, sizeof(vis));
  for (auto v : eg[1]) {
    if (vis[v.first]) continue;
    vis[v.first] = 1;
    nlp[cnt] = -1;
    uu[cnt] = cur[v.first];
    for (auto g : eg[v.first])
      if (fl[g.first]) {
        vis[g.first] = 1;
        nlp[cnt] = dep[v.first] ^ dep[g.first] ^ g.second;
        uu[cnt].ins(uu[g.first]);
      }
    cnt++;
  }
  for (int a = cnt; a >= 0; a--)
    for (int r = 1; r <= idcnt; r++) {
      if (a == cnt) {
        dp[a][r] = 1;
        continue;
      }
      long long cans = dp[a + 1][r];
      if (nlp[a] == -1) {
        th ur = tr[r];
        ur.ins(uu[a]);
        if (ur.fl) cans += dp[a + 1][cal(ur)], cans %= 1000000007;
      } else {
        th ur = tr[r];
        ur.ins(uu[a]);
        if (ur.fl) cans += 2 * dp[a + 1][cal(ur)], cans %= 1000000007;
        ur.ins(nlp[a]);
        if (ur.fl) cans += dp[a + 1][cal(ur)], cans %= 1000000007;
      }
      dp[a][r] = cans % 1000000007;
    }
  if (test) cout << ksm(2, 99999) << endl;
  cout << dp[0][idcnt] << endl;
  return 0;
}
