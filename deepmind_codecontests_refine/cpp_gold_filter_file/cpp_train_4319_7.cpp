#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128777216")
using namespace std;
const long long LINF = 1000000000000000000LL;
const int INF = 1000000000;
const long double eps = 1e-9;
const long double PI = 3.1415926535897932384626433832795l;
void prepare(string s) {
  if (s.length() != 0) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}
const int MOD = INF + 9;
const int NMAX = 100100;
int n;
int xa[NMAX], xb[NMAX];
vector<int> g[NMAX], gr[NMAX];
map<pair<int, int>, int> mem;
int used[NMAX];
set<int> pq;
vector<int> ans;
void read() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) scanf("%d %d", &xa[i], &xb[i]);
}
int cntDown(int v) {
  int r = 0;
  for (int i = 0; i < (int)((int)((gr[v]).size())); i++) {
    int u = gr[v][i];
    if (!used[u]) r++;
  }
  return r;
}
bool canDel(int v) {
  for (int i = 0; i < (int)((int)((g[v]).size())); i++) {
    int u = g[v][i];
    if (used[u]) continue;
    if (cntDown(u) == 1) return false;
  }
  return true;
}
void upd(int v) {
  pq.erase(v);
  used[v] = 1;
  for (int i = 0; i < (int)((int)((gr[v]).size())); i++) {
    int u = gr[v][i];
    if (canDel(u) && !used[u])
      pq.insert(u);
    else
      pq.erase(u);
  }
  for (int i = 0; i < (int)((int)((g[v]).size())); i++) {
    int u = g[v][i];
    if (used[u]) continue;
    for (int j = 0; j < (int)((int)((gr[u]).size())); j++) {
      int k = gr[u][j];
      if (canDel(k) && !used[k])
        pq.insert(k);
      else
        pq.erase(k);
    }
  }
}
void solve() {
  for (int i = 0; i < (int)(n); i++) mem[make_pair(xa[i], xb[i])] = i;
  for (int i = 0; i < (int)(n); i++) {
    for (int j = -1; j <= 1; j++) {
      int x = xa[i] + j;
      int y = xb[i] + 1;
      if (mem.find(make_pair(x, y)) != mem.end()) {
        int id = mem[make_pair(x, y)];
        g[i].push_back(id);
        gr[id].push_back(i);
      }
    }
  }
  memset(used, 0, sizeof(used));
  for (int i = 0; i < (int)(n); i++)
    if (canDel(i)) pq.insert(i);
  int cur = 0;
  for (int _ = 0; _ < (int)(n); _++) {
    int v;
    if (cur & 1) {
      v = *pq.begin();
    } else {
      set<int>::iterator it = pq.end();
      --it;
      v = *it;
    }
    ans.push_back(v);
    used[v] = 1;
    upd(v);
    cur ^= 1;
  }
  int mul = 1;
  int res = 0;
  for (int i = (int)((int)((ans).size())) - 1; i >= 0; i--) {
    res = (res + ((long long)mul * (long long)ans[i]) % MOD) % MOD;
    mul = ((long long)mul * (long long)n) % MOD;
  }
  printf("%d\n", res);
}
int main() {
  prepare("");
  read();
  solve();
  return 0;
}
