#include <bits/stdc++.h>
using namespace std;
vector<int> e1[300005], e2[300005];
int n, m, aim, len[300005], st[300005], ed, vis[300005], tmp[300005], l[300005],
    r[300005], L[300005], R[300005], cd[300005], ans, tms[300005];
bool spe[300005];
void get(int k) {
  len[k] = 1;
  for (auto v : e1[k]) {
    if (!len[v]) get(v);
    len[k] = max(len[k], len[v] + 1);
  }
}
inline void mxs(int k) {
  for (; len[k] > 1;) {
    st[++ed] = k;
    for (auto v : e1[k])
      if (len[v] + 1 == len[k]) {
        k = v;
        break;
      }
  }
  st[++ed] = k;
  for (int i = 1; i <= ed; i++) spe[st[i]] = 1;
}
int dl(vector<int> e[], int k, int vis[]) {
  int rt = 1;
  vis[k] = aim;
  for (auto v : e[k])
    if (!vis[v]) rt += dl(e, v, vis);
  return rt;
}
int find(vector<int> e[], int k, bool tp) {
  int rt = 1;
  tmp[k] = 1;
  for (auto v : e[k])
    if ((tp ? (l[v] >= aim) : (r[v] <= aim)) && !tmp[v]) rt += find(e, v, tp);
  return rt;
}
void clear(int k, vector<int> e[]) {
  tmp[k] = 0;
  for (auto v : e[k])
    if (tmp[v]) clear(v, e);
}
inline void solve(int k) {
  int l = L[k - 1], r = R[k + 1], v = cd[k];
  aim = k;
  int tmp1 = find(e1, v, 0);
  clear(v, e1);
  int tmp2 = find(e2, v, 1);
  clear(v, e2);
  if (l + r + tmp1 + tmp2 == n) ans++;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v; i <= m; i++)
    scanf("%d%d", &u, &v), e1[u].push_back(v), e2[v].push_back(u);
  for (int i = 1; i <= n; i++)
    if (!len[i]) get(i);
  int mx = 0, pt = 0;
  for (int i = 1; i <= n; i++)
    if (len[i] > mx) mx = len[i], pt = i;
  mxs(pt);
  for (int i = 1; i <= ed; i++) aim = i, L[i] = L[i - 1] + dl(e2, st[i], l);
  for (int i = ed; i; i--) aim = i, R[i] = R[i + 1] + dl(e1, st[i], r);
  for (int i = 1; i <= ed; i++)
    if (L[i] + R[i] >= n) ans++;
  for (int i = 1; i <= n; i++)
    if (!l[i]) l[i] = ed + 1;
  for (int i = 1; i <= n; i++)
    if (!spe[i])
      if (l[i] == r[i] + 2) tms[r[i] + 1]++;
  for (int i = 1; i <= n; i++)
    if (!spe[i] && l[i] == r[i] + 2 && tms[r[i] + 1] == 1) cd[r[i] + 1] = i;
  for (int i = 1; i <= ed; i++)
    if (cd[i]) solve(i);
  printf("%d\n", ans);
}
