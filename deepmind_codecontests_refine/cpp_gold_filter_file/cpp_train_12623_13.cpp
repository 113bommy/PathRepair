#include <bits/stdc++.h>
const int N = 4096;
const int maxn = 3e6;
const int M = 256;
using namespace std;
struct Ans {
  int x, y;
} s[maxn + 5];
struct block {
  int mp[M + 2][M + 2], id[N + 1];
} b[16 + 1];
int n, q, a[N + 5], t[N + 5], L[N + 5], R[N + 5], blo[N + 5], bs, ans, sm, cnt,
    anss[maxn + 5], f[M * 2 + 5][M + 2][M + 2];
int merge(int x, int y) {
  if (!x || !y) return x + y;
  s[++ans] = (Ans){x, y};
  return ++sm;
}
void solve(int k, int l, int r, vector<int> c) {
  if (l == r) {
    f[k][1][1] = t[c[1]];
    return;
  }
  int mid = l + r >> 1;
  vector<int> cl(1), cr(1);
  for (int i = 1; i < c.size(); i++)
    if (c[i] <= mid)
      cl.push_back(c[i]);
    else
      cr.push_back(c[i]);
  solve(k << 1, l, mid, cl);
  solve(k << 1 | 1, mid + 1, r, cr);
  int L = 1, R = 1;
  for (int i = 1; i < c.size(); c[i] <= mid ? L++ : R++, i++) {
    int ll = L - 1, rr = R - 1;
    c[i] <= mid ? ll++ : rr++;
    for (int j = i; j < c.size(); j++, c[j] <= mid ? ll++ : rr++)
      f[k][i][j] = merge(f[k << 1][L][ll], f[k << 1 | 1][R][rr]);
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), t[a[i]] = i;
  sm = n;
  bs = M;
  for (int i = 1; i <= n; i++) {
    blo[i] = (i - 1) / bs + 1;
    if (!L[blo[i]]) L[blo[i]] = i;
    R[blo[i]] = i;
  }
  for (int x = 1; x <= blo[n]; x++) {
    vector<int> c(1);
    for (int i = 1; i <= n; i++)
      if (a[i] >= L[x] && a[i] <= R[x]) {
        c.push_back(a[i]);
        b[x].id[i] = b[x].id[i - 1] + 1;
      } else
        b[x].id[i] = b[x].id[i - 1];
    solve(1, L[x], R[x], c);
    for (int i = 1; i < c.size(); i++)
      for (int j = 1; j < c.size(); j++) b[x].mp[i][j] = f[1][i][j];
  }
  int l, r;
  while (q--) {
    scanf("%d%d", &l, &r);
    cnt++;
    for (int x = 1; x <= blo[n]; x++)
      anss[cnt] = merge(anss[cnt], b[x].mp[b[x].id[l - 1] + 1][b[x].id[r]]);
  }
  cout << sm << endl;
  for (int i = 1; i <= ans; i++) printf("%d %d\n", s[i].x, s[i].y);
  for (int i = 1; i <= cnt; i++) printf("%d ", anss[i]);
  return 0;
}
