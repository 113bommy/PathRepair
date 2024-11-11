#include <bits/stdc++.h>
using namespace std;
const int MAXN = 131072;
const int LG = 18;
const long long MOD = 3000000019;
const long long HSH = 1313131;
int Q, N[2], M = 0;
long long hpow[MAXN];
int opt[MAXN], opv[MAXN], nv[MAXN];
char opc[MAXN];
int par[2][LG][MAXN];
vector<int> child[2][MAXN];
long long hval[2][MAXN];
int dep[2][MAXN];
int turnon[MAXN];
int cnt[MAXN];
int go[MAXN][26];
int realv[MAXN];
int tpos[MAXN], rb[MAXN];
int BITcnt[MAXN], BITturnon[MAXN];
long long ans;
unordered_map<long long, int> hset;
void addBIT(int* BIT, int pos, int val) {
  pos++;
  while (pos < MAXN) {
    BIT[pos] += val;
    pos += pos & (-pos);
  }
}
int qryBIT(int* BIT, int pos) {
  int ret = 0;
  pos++;
  while (pos) {
    ret += BIT[pos];
    pos -= pos & (-pos);
  }
  return ret;
}
void make_hpow() {
  hpow[0] = 1;
  for (int i = 1; i < MAXN; i++) hpow[i] = (hpow[i - 1] * HSH) % MOD;
}
long long get_hash(int l, int r) {
  int len = dep[1][l] - dep[1][r];
  long long ret = (hval[1][l] - hval[1][r] * hpow[len]) % MOD;
  return (ret < 0 ? ret + MOD : ret) + len * MOD;
}
int find_deepest_match(int v) {
  int p = v;
  for (int i = LG - 1; i >= 0; i--) {
    int np = par[1][i][p];
    if (hset.count(get_hash(v, np))) p = np;
  }
  return hset[get_hash(v, p)];
}
void dfs(int v) {
  tpos[v] = M++;
  for (auto ch : child[0][v]) dfs(ch);
  rb[v] = M;
}
int main() {
  make_hpow();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> Q;
  N[0] = N[1] = 1;
  dep[0][0] = dep[1][0] = 0;
  hval[0][0] = hval[1][0] = 0;
  par[0][0][0] = par[1][0][0] = 0;
  realv[0] = 0;
  memset((go), -1, sizeof(go));
  for (int i = 0; i < Q; i++) {
    cin >> opt[i] >> opv[i] >> opc[i];
    opt[i]--;
    opv[i]--;
    int o = opt[i];
    int v = N[o]++;
    int p = opv[i];
    nv[i] = v;
    if (o == 0) {
      int cc = opc[i] - 'a';
      p = realv[p];
      if (go[p][cc] == -1) {
        go[p][cc] = v;
        realv[v] = v;
        child[o][p].push_back(v);
      } else {
        realv[v] = go[p][cc];
        v = realv[v];
      }
    }
    par[o][0][v] = p;
    dep[o][v] = dep[o][p] + 1;
    long long c = opc[i] - 'a' + 1;
    if (o == 0)
      hval[o][v] = (hval[o][p] + hpow[dep[o][p]] * c) % MOD;
    else
      hval[o][v] = (hval[o][p] * HSH + c) % MOD;
  }
  for (int i = 0; i < N[0]; i++)
    if (realv[i] == i) hset.insert({hval[0][i] + dep[0][i] * MOD, i});
  for (int i = 0; i < 2; i++)
    for (int j = 1; j < LG; j++)
      for (int k = 0; k < N[i]; k++)
        par[i][j][k] = par[i][j - 1][par[i][j - 1][k]];
  ans = 1;
  dfs(0);
  addBIT(BITturnon, tpos[0], 1);
  addBIT(BITturnon, rb[0], -1);
  for (int i = 0; i < Q; i++) {
    int o = opt[i], v = nv[i];
    if (o == 0) {
      v = realv[v];
      ans += qryBIT(BITcnt, rb[v] - 1) - qryBIT(BITcnt, tpos[v] - 1);
      addBIT(BITturnon, tpos[v], 1);
      addBIT(BITturnon, rb[v], -1);
    } else {
      int u = find_deepest_match(v);
      ans += qryBIT(BITturnon, tpos[u]);
      addBIT(BITcnt, tpos[u], 1);
    }
    cout << ans << "\n";
  }
  return 0;
}
