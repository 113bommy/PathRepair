#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 100007;
const int MAXM = 1000007;
const int MOD = 1e9 + 7;
int n, m, ng;
int ns[MAXN];
set<int> s[MAXM];
map<pair<int, int>, int> now;
map<pair<int, int>, int>::iterator it;
map<pair<int, int>, int> nid;
long long frac[MAXM];
int id[MAXM];
void init();
void input();
void inputq();
void work();
int main() {
  init();
  input();
  work();
}
void init() {
  ios::sync_with_stdio(false);
  frac[0] = 1;
  for (int i = 1; i < MAXN; ++i) frac[i] = (frac[i - 1] * i) % MOD;
}
void input() { scanf("%d%d", &n, &m); }
void inputq() {
  scanf("%d", &ng);
  for (int i = 0; i < ng; ++i) scanf("%d", &ns[i]);
}
void work() {
  int kk = 0, maxi, nd;
  for (int i = 1; i <= m; ++i) s[kk].insert(i), id[i] = kk;
  for (int _q = 0; _q < n; ++_q) {
    inputq();
    now.clear();
    for (int i = 0; i < ng; ++i) {
      s[id[ns[i]]].erase(ns[i]);
      ++now[make_pair(ns[i], id[ns[i]])];
    }
    nid.clear();
    for (it = now.begin(); it != now.end(); ++it) {
      if (nid.find(make_pair(it->first.second, it->second)) == nid.end()) {
        nid.insert(make_pair(make_pair(it->first.second, it->second), ++kk));
      }
    }
    maxi = 0;
    for (it = now.begin(); it != now.end(); ++it) {
      nd = nid[make_pair(it->first.second, it->second)];
      s[nd].insert(it->first.first);
      id[it->first.first] = nd;
      maxi = (((maxi) > (it->second)) ? (maxi) : (it->second));
    }
    kk += maxi;
  }
  long long ans = 1;
  for (int i = 0; i <= kk; ++i) {
    ans = (ans * frac[s[i].size()]) % MOD;
  }
  printf("%I64d\n", ans);
}
