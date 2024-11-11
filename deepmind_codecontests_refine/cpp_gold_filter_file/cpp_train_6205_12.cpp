#include <bits/stdc++.h>
const int MAXN = 100031, MAXM = 200031;
int u[MAXM], v[MAXM], l[MAXM], r[MAXM];
std::vector<int> z[MAXN * 4];
int n = 0, m = 0, q = 0;
namespace U {
int f[MAXN], k[MAXN], s[MAXM * 2], st = 0;
bool z[MAXN];
void init() {
  for (int i = 1; i <= n; i++) f[i] = i;
}
bool find(int &x) {
  bool d = 0;
  while (x != f[x]) d ^= z[x], x = f[x];
  return d;
}
bool uni(int x, int y) {
  bool d = find(x) ^ find(y);
  if (x == y) return d;
  if (k[x] < k[y]) std::swap(x, y);
  if (k[x] == k[y]) k[x]++, s[st++] = -x;
  s[st++] = y, f[y] = x, z[y] ^= d ^ 1;
  return 1;
}
void re(int x) {
  for (int t = 0; st != x;) (t = s[--st]) > 0 ? f[t] = t, z[t] = 0 : k[-t]--;
}
}  // namespace U
void ins(int p, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr)
    z[p].push_back(x);
  else {
    int mid = l + r >> 1;
    if (ql < mid) ins(p << 1, l, mid, ql, qr, x);
    if (mid < qr) ins(p << 1 | 1, mid, r, ql, qr, x);
  }
}
void slv(int p, int l, int r) {
  int st = U::st;
  for (int i = 0; i < z[p].size(); i++)
    if (!U::uni(u[z[p][i]], v[z[p][i]])) {
      for (int i = l; i < r; i++) puts("NO");
      U::re(st);
      return;
    }
  if (l + 1 == r)
    puts("YES");
  else {
    int mid = l + r >> 1;
    slv(p << 1, l, mid), slv(p << 1 | 1, mid, r);
  }
  U::re(st);
}
std::map<std::pair<int, int>, int> o;
int main() {
  scanf("%d%d", &n, &q), U::init();
  for (int i = 0, x = 0, y = 0; i < q; i++) {
    scanf("%d%d", &x, &y);
    if (x > y) std::swap(x, y);
    if (!o.count({x, y}))
      u[m] = x, v[m] = y, l[m] = i, o[{x, y}] = m++;
    else
      r[o[{x, y}]] = i, o.erase({x, y});
  }
  for (auto x : o) r[x.second] = q;
  for (int i = 0; i < m; i++) ins(1, 0, q, l[i], r[i], i);
  slv(1, 0, q);
  return 0;
}
