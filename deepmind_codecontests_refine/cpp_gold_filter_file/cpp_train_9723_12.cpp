#include <bits/stdc++.h>
using namespace std;
const int maxn = 200020;
int fa[maxn];
int fin(int n) {
  if (n == fa[n]) return n;
  return fa[n] = fin(fa[n]);
}
multiset<pair<int, int> > S[maxn << 2];
int lft[maxn << 2], rht[maxn << 2];
void build(int n, int l, int r) {
  lft[n] = l, rht[n] = r;
  if (l == r) return;
  int mid = (l + r) / 2;
  build(n << 1, l, mid);
  build((n << 1) + 1, mid + 1, r);
}
void ins(int n, int p, int r, int ind) {
  S[n].insert(make_pair(r, ind));
  if (lft[n] == rht[n]) return;
  int mid = (lft[n] + rht[n]) / 2;
  if (p <= mid)
    ins(n << 1, p, r, ind);
  else
    ins((n << 1) + 1, p, r, ind);
}
int ban;
void del(int n, int p, int r, int ind) {
  if (S[n].find(make_pair(r, ind)) != S[n].end())
    S[n].erase(S[n].lower_bound(make_pair(r, ind)));
  if (lft[n] == rht[n]) return;
  int mid = (lft[n] + rht[n]) / 2;
  if (p <= mid)
    del(n << 1, p, r, ind);
  else
    del((n << 1) + 1, p, r, ind);
}
vector<pair<int, int> > V;
vector<int> VV;
void dfs(int n, int p, int r) {
  if (S[n].lower_bound(make_pair(r, -1)) == S[n].end()) return;
  if (lft[n] == rht[n]) {
    multiset<pair<int, int> >::iterator it;
    it = S[n].lower_bound(make_pair(r, -1));
    while (it != S[n].end()) V.push_back(*it), VV.push_back(p), it++;
    return;
  }
  int mid = (lft[n] + rht[n]) / 2;
  if (p <= mid)
    dfs(n << 1, p, r);
  else
    dfs(n << 1, mid, r), dfs((n << 1) + 1, p, r);
}
int a[maxn], b[maxn], c[maxn], d[maxn];
int L[maxn], R[maxn], ll[maxn], rr[maxn];
int main() {
  int n, i, j, k;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    if (a[i] == 1) d[i] = b[i], d[i + n] = c[i];
  }
  sort(d + 1, d + 1 + n + n);
  int N = unique(d + 1, d + 1 + n + n) - d - 1;
  for (i = 1; i <= n; i++)
    if (a[i] == 1)
      b[i] = lower_bound(d + 1, d + 1 + N, b[i]) - d + 1,
      c[i] = lower_bound(d + 1, d + 1 + N, c[i]) - d + 1;
  build(1, 1, N + 3);
  int cnt = 0;
  for (i = 1; i <= n; i++)
    if (a[i] == 2) {
      int l = L[fin(c[i])], r = R[fin(c[i])];
      if (ll[b[i]] > l && ll[b[i]] < r)
        puts("YES");
      else if (rr[b[i]] > l && rr[b[i]] < r)
        puts("YES");
      else
        puts("NO");
    } else {
      ++cnt;
      fa[cnt] = cnt;
      ll[cnt] = b[i], rr[cnt] = c[i];
      V.clear();
      VV.clear();
      dfs(1, b[i] - 1, b[i] + 1);
      dfs(1, c[i] - 1, c[i] + 1);
      L[cnt] = ll[cnt], R[cnt] = rr[cnt];
      for (j = 0; j < V.size(); j++)
        L[cnt] = min(L[cnt], VV[j]), R[cnt] = max(R[cnt], V[j].first),
        fa[fin(V[j].second)] = cnt, del(1, VV[j], V[j].first, V[j].second);
      ins(1, L[cnt], R[cnt], cnt);
    }
}
