#include <bits/stdc++.h>
using namespace std;
int n, q;
const int N = 700000;
char st[N];
int nxt[N][30], len[N], par[N];
vector<int> pos[N], lst[N];
int li[N], ri[N], ki[N], res[N], cnt[N], sum[N], hd[N], vis[N];
int append(int p, int c) {
  static int tot = 1;
  if (nxt[p][c] && len[nxt[p][c]] == len[p] + 1) return nxt[p][c];
  int np = ++tot, fl = nxt[p][c];
  len[np] = len[p] + 1;
  for (; p && !nxt[p][c]; nxt[p][c] = np, p = par[p])
    ;
  if (!p)
    par[np] = 1;
  else {
    int q = nxt[p][c];
    if (len[q] == len[p] + 1)
      par[np] = q;
    else {
      int nq = (fl ? np : ++tot);
      len[nq] = len[p] + 1;
      par[nq] = par[q];
      par[q] = nq;
      if (!fl) par[np] = nq;
      for (int i = 0; i < 26; ++i) nxt[nq][i] = nxt[q][i];
      for (; p && nxt[p][c] == q; nxt[p][c] = nq, p = par[p])
        ;
    }
  }
  return np;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", st + 1);
    int l = strlen(st + 1);
    for (int p = 1, j = 1; j <= l; ++j) {
      p = append(p, st[j] - 'a');
      pos[i].push_back(p);
    }
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d%d", &li[i], &ri[i], &ki[i]);
    lst[li[i] - 1].push_back(i);
    lst[ri[i]].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < pos[i].size(); ++j) {
      int p = pos[i][j];
      for (; p && vis[p] != i; p = par[p]) vis[p] = i, cnt[p] = 0;
      hd[pos[i][j]] = p;
    }
    for (int j = pos[i].size() - 1; ~j; --j) {
      int p = pos[i][j], q = hd[p];
      cnt[p]++;
      for (; p != q; p = par[p]) {
        sum[p] += cnt[p];
        cnt[par[p]] += cnt[p];
      }
    }
    for (int p : lst[i])
      if (ri[p] == i)
        res[p] += sum[pos[ki[p]][pos[ki[p]].size() - 1]];
      else
        res[p] -= sum[pos[ki[p]][pos[ki[p]].size() - 1]];
  }
  for (int i = 1; i <= n; ++i) printf("%d\n", res[i]);
}
