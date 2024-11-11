#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
char s[maxn];
int nxt[maxn][26], par[maxn], len[maxn], num[maxn], rk[maxn], tp[maxn];
int n, cnt, last;
int add(int l) {
  ++cnt;
  memset(nxt[cnt], 0, sizeof nxt[cnt]);
  len[cnt] = l, num[cnt] = 0;
  return cnt;
}
void init() {
  cnt = 0;
  last = add(0);
}
void insert(char ch) {
  int t = ch - 'a', p = last, cur;
  cur = last = add(len[p] + 1);
  while (p && !nxt[p][t]) nxt[p][t] = cur, p = par[p];
  if (!p) {
    par[cur] = 1;
    return;
  }
  int q = nxt[p][t];
  if (len[q] == len[p] + 1) {
    par[cur] = q;
    return;
  }
  int nq = add(len[p] + 1);
  memcpy(nxt[nq], nxt[q], sizeof nxt[q]);
  par[nq] = par[q], par[q] = par[cur] = nq;
  while (p && nxt[p][t] == q) nxt[p][t] = nq, p = par[p];
}
void rsort() {
  for (int i = 0; i <= cnt; ++i) tp[i] = 0;
  for (int i = 1; i <= cnt; ++i) ++tp[len[i]];
  for (int i = 1; i <= cnt; ++i) tp[i] += tp[i - 1];
  for (int i = cnt; i >= 1; --i) rk[tp[len[i]]--] = i;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    init();
    cin >> s + 1;
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
      insert(s[i]);
      num[last] = 1;
    }
    rsort();
    long long ret = 0;
    for (int i = cnt; i >= 2; --i) {
      int u = rk[i];
      num[par[u]] += num[u];
      ret += num[u] * 1ll * num[u] * (len[u] - len[par[u]]);
    }
    cout << ret << "\n";
  }
  return 0;
}
