#include <bits/stdc++.h>
using namespace std;
typedef int Arr[600005];
int N, lim, L, R, dd;
long long Ans;
Arr A, p, pp, pos, ad;
pair<pair<int, int>, pair<int, int> > t[1048577];
inline int IN() {
  char c;
  register int first = 0;
  while ((c = getchar()) < 48 && c ^ '-' || c > 57)
    ;
  bool f = c == '-';
  if (f) (c = getchar());
  for (; c > 47 && c < 58; (c = getchar())) first = first * 10 + c - 48;
  if (f) first = -first;
  return first;
}
inline void Lu(pair<pair<int, int>, pair<int, int> >& u,
               const pair<int, int>& v) {
  if (v.first < u.first.first || !u.first.first)
    u.second = u.first, u.first = v;
  else if (v.first == u.first.first)
    u.first.second += v.second;
  else if (v.first < u.second.first || !u.second.first)
    u.second = v;
  else if (v.first == u.second.first)
    u.second.second += v.second;
}
inline void upd(int u) {
  pair<pair<int, int>, pair<int, int> > v = t[u << 1],
                                        &w = t[u] = t[u << 1 | 1];
  if (v.first.first) Lu(w, v.first);
  if (v.second.first) Lu(w, v.second);
}
inline void Mdy(int u, int w) {
  t[u].first.first += w;
  t[u].second.first += w;
  ad[u] += w;
}
inline void Dn(int u) {
  if (u < lim && ad[u]) {
    Mdy(u << 1, ad[u]);
    Mdy(u << 1 | 1, ad[u]);
    ad[u] = 0;
  }
}
inline void pret() {
  for (lim = 1; lim < N; lim <<= 1)
    ;
  for (int _r = N, i = 1; i <= _r; ++i)
    t[lim + i - 1] = {{1, 1}, {10000000, 1}};
  for (int i = lim - 1; i; --i) upd(i);
}
void Add(int u, int l, int r) {
  if (L <= l && r <= R) {
    Mdy(u, dd);
    return;
  }
  int m = l + r >> 1;
  Dn(u);
  if (R > m) Add(u << 1 | 1, m + 1, r);
  if (L <= m) Add(u << 1, l, m);
  upd(u);
}
inline void jia(int l, int r, int w) {
  if (l <= r) {
    L = l;
    R = r;
    dd = w;
    Add(1, 1, lim);
  }
}
inline int suan(const pair<pair<int, int>, pair<int, int> >& u) {
  int an = 0;
  if (u.first.first == 1 || u.first.first == 2) an += u.first.second;
  if (u.second.first == 1 || u.second.first == 2) an += u.second.second;
  return an;
}
int Qs(int u, int l, int r) {
  if (L <= l && r <= R) {
    return suan(t[u]);
  }
  int m = l + r >> 1, ret = 0;
  Dn(u);
  if (R > m) ret = Qs(u << 1 | 1, m + 1, r);
  if (L <= m) ret += Qs(u << 1, l, m);
  return ret;
}
int main() {
  N = IN();
  for (int _r = N, i = 1; i <= _r; ++i) A[pos[i] = IN()] = i;
  for (int _r = N, i = 1; i <= _r; ++i) {
    if (pos[A[i] - 1] < i) p[i] = pos[A[i] - 1];
    if (pos[A[i] + 1] < i) pp[i] = pos[A[i] + 1];
    if (p[i] < pp[i]) swap(p[i], pp[i]);
  }
  pret();
  for (int _r = N, i = 1; i <= _r; ++i) {
    jia(p[i] + 1, i - 1, 1);
    jia(1, pp[i], -1);
    L = 1, R = i;
    Ans += Qs(1, 1, lim);
  }
  printf("%I64d\n", Ans - N);
}
