#include <bits/stdc++.h>
using namespace std;
const pair<long long, long long> M = make_pair(1e9 + 7, 1e9 + 9);
const long long base = 347;
const int N = 1e6 + 7;
ostream& operator<<(ostream& os, pair<long long, long long> hash) {
  return os << "(" << hash.first << ", " << hash.second << ")";
}
pair<long long, long long> operator+(pair<long long, long long> a,
                                     long long x) {
  return make_pair(a.first + x, a.second + x);
}
pair<long long, long long> operator-(pair<long long, long long> a,
                                     long long x) {
  return make_pair(a.first - x, a.second - x);
}
pair<long long, long long> operator*(pair<long long, long long> a,
                                     long long x) {
  return make_pair(a.first * x, a.second * x);
}
pair<long long, long long> operator+(pair<long long, long long> a,
                                     pair<long long, long long> x) {
  return make_pair(a.first + x.first, a.second + x.second);
}
pair<long long, long long> operator-(pair<long long, long long> a,
                                     pair<long long, long long> x) {
  return make_pair(a.first - x.first, a.second - x.second);
}
pair<long long, long long> operator*(pair<long long, long long> a,
                                     pair<long long, long long> x) {
  return make_pair(a.first * x.first, a.second * x.second);
}
pair<long long, long long> operator%(pair<long long, long long> a,
                                     pair<long long, long long> m) {
  return make_pair(a.first % m.first, a.second % m.second);
}
pair<long long, long long> power(pair<long long, long long> a, long long p) {
  if (p == 0) return make_pair(1, 1);
  pair<long long, long long> ans = power(a, p / 2);
  ans = (ans * ans) % M;
  if (p % 2) ans = (ans * a) % M;
  return ans;
}
pair<long long, long long> inverse(pair<long long, long long> a) {
  return power(a, (M.first - 1) * (M.second - 1) - 1);
}
pair<long long, long long> pb[N];
pair<long long, long long> invb;
void hashPre() {
  pb[0] = make_pair(1, 1);
  for (int i = 1; i < N; i++) pb[i] = (pb[i - 1] * base) % M;
  invb = inverse(pb[1]);
}
pair<long long, long long> Hash(string s) {
  pair<long long, long long> ans = make_pair(0, 0);
  for (int i = 0; i < s.size(); i++) ans = (ans * base + s[i]) % M;
  return ans;
}
pair<long long, long long> append(pair<long long, long long> cur, char c) {
  return (cur * base + c) % M;
}
const int MAX = 100007;
const int MAXLOG = 18;
vector<int> serial;
vector<int> edg[MAX];
vector<char> borno[MAX];
int lvl[MAX], sbtr[MAX];
char pch[MAX];
int par[MAXLOG + 1][MAX];
void dfs(int u, int p = 0) {
  serial.push_back(u);
  sbtr[u] = 1;
  lvl[u] = lvl[p] + 1;
  par[0][u] = p;
  for (int k = 1; k <= MAXLOG; k++) {
    par[k][u] = par[k - 1][par[k - 1][u]];
  }
  for (int i = 0; i < edg[u].size(); i++) {
    int v = edg[u][i];
    if (v == p) continue;
    pch[v] = borno[u][i];
    dfs(v, u);
    sbtr[u] += sbtr[v];
  }
}
int cnt;
int chainIdx[MAX], chainHead[MAX];
void HLD(int u, int p = 0) {
  if (chainHead[cnt] == 0) chainHead[cnt] = u;
  chainIdx[u] = cnt;
  int big = 0;
  int mx = 0;
  for (int i = 0; i < edg[u].size(); i++) {
    int v = edg[u][i];
    if (v == p) continue;
    if (sbtr[v] > big) {
      big = v;
      mx = sbtr[v];
    }
  }
  if (mx == 0) return;
  HLD(big, u);
  for (int i = 0; i < edg[u].size(); i++) {
    int v = edg[u][i];
    if (v == p || v == big) continue;
    cnt++;
    HLD(v, u);
  }
}
struct _q {
  int u, v;
  pair<long long, long long> shoja;
  pair<long long, long long> ulta;
  string s;
} qr[MAX];
set<pair<long long, long long> > queries;
map<pair<long long, long long>, vector<int> > chainHashes[MAX];
int LCA(int u, int v) {
  if (lvl[u] < lvl[v]) swap(u, v);
  for (int k = MAXLOG; k >= 0; k--) {
    if (lvl[u] - (1 << k) >= lvl[v]) {
      u = par[k][u];
    }
  }
  assert(lvl[u] == lvl[v]);
  if (u == v) return u;
  for (int k = MAXLOG; k >= 0; k--) {
    if (par[k][u] != par[k][v]) {
      u = par[k][u];
      v = par[k][v];
    }
  }
  assert(par[0][u] == par[0][v]);
  return par[0][u];
}
int queryUp(int l, int u, int len, pair<long long, long long> p) {
  int lo = lvl[l];
  int hi = lvl[u] - len;
  int lchain = l;
  int ans = 0;
  while (lo <= hi) {
    int uchain = chainIdx[u];
    int uHead = chainHead[uchain];
    auto it = chainHashes[uchain].find(p);
    if (it != chainHashes[uchain].end()) {
      ans += upper_bound((it->second).begin(), (it->second).end(), hi) -
             lower_bound((it->second).begin(), (it->second).end(), lo);
    }
    u = par[0][uHead];
    hi = lvl[u] - len;
  }
  return ans;
}
vector<int> prefixFunction(const string& s) {
  int n = s.size();
  int k = 0;
  vector<int> v(n + 1);
  v[1] = 0;
  for (int i = 2; i <= n; i++) {
    while (k > 0 && s[k] != s[i - 1]) k = v[k];
    if (s[k] == s[i - 1]) k++;
    v[i] = k;
  }
  return v;
}
int kmpMatcher(const string& text, const string& pattern) {
  vector<int> pi = prefixFunction(pattern);
  int matchCount = 0;
  int k = 0;
  for (int i = 0; i < text.size(); i++) {
    while (k > 0 && text[i] != pattern[k]) k = pi[k];
    if (text[i] == pattern[k]) k++;
    if (k == pattern.size()) {
      matchCount++;
      k = pi[k];
    }
  }
  return matchCount;
}
int jhamela(int u, int l, int v, string s) {
  int len = s.size() - 1;
  string t;
  for (int k = MAXLOG; k >= 0; k--) {
    if (lvl[u] - (1 << k) >= lvl[l] + len) {
      u = par[k][u];
    }
  }
  while (u != l) {
    t += pch[u];
    u = par[0][u];
  }
  string r;
  for (int k = MAXLOG; k >= 0; k--) {
    if (lvl[v] - (1 << k) >= lvl[l] + len) {
      v = par[k][v];
    }
  }
  while (v != l) {
    r += pch[v];
    v = par[0][v];
  }
  reverse(r.begin(), r.end());
  t += r;
  return kmpMatcher(t, s);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  hashPre();
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    edg[u].push_back(v);
    borno[u].push_back(c);
    edg[v].push_back(u);
    borno[v].push_back(c);
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> qr[i].u >> qr[i].v >> qr[i].s;
    qr[i].shoja = Hash(qr[i].s);
    queries.insert(qr[i].shoja);
    string r(qr[i].s);
    reverse(r.begin(), r.end());
    qr[i].ulta = Hash(r);
    queries.insert(qr[i].ulta);
  }
  dfs(1);
  HLD(1);
  for (int u : serial) {
    int uchain = chainIdx[u];
    pair<long long, long long> p(0, 0);
    for (int i = 0; i < 100 && u > 1; i++) {
      p = append(p, pch[u]);
      u = par[0][u];
      if (queries.count(p)) {
        chainHashes[uchain][p].push_back(lvl[u]);
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    int l = LCA(qr[i].u, qr[i].v);
    cout << queryUp(l, qr[i].u, qr[i].s.size(), qr[i].shoja) +
                queryUp(l, qr[i].v, qr[i].s.size(), qr[i].ulta) +
                jhamela(qr[i].u, l, qr[i].v, qr[i].s)
         << endl;
  }
  return 0;
}
