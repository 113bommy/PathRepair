#include <bits/stdc++.h>
using namespace std;
char s[2000100];
int Lb[2000100 << 2], Rb[2000100 << 2];
void build(int x, int L, int R) {
  if (L == R) {
    if (s[L] == '(')
      Rb[x] = 1;
    else
      Lb[x] = 1;
    return;
  }
  int mid = L + R >> 1;
  build((x << 1), L, mid);
  build((x << 1 | 1), mid + 1, R);
  if (Rb[(x << 1)] > Lb[(x << 1 | 1)]) {
    Lb[x] = Lb[(x << 1)];
    Rb[x] = Rb[(x << 1 | 1)] + Rb[(x << 1)] - Lb[(x << 1 | 1)];
  } else {
    Lb[x] = Lb[(x << 1)] + Lb[(x << 1 | 1)] - Rb[(x << 1)];
    Rb[x] = Rb[(x << 1 | 1)];
  }
}
int lb, rb;
int qury(int x, int L, int R, int l, int r) {
  if (l <= L && R <= r) {
    lb = lb + max(0, Lb[x] - rb);
    rb = Rb[x] + max(0, rb - Lb[x]);
    return lb;
  }
  int mid = L + R >> 1, res;
  if (l <= mid) res = qury((x << 1), L, mid, l, r);
  if (r > mid) res = qury((x << 1 | 1), mid + 1, R, l, r);
  return res;
}
int _wa[2000100], _wb[2000100], _wv[2000100], _ws[2000100];
int _cmp(int *r, int a, int b, int l) {
  return r[a] == r[b] && r[a + l] == r[b + l];
}
void Get_Sa(int *r, int *sa, int n, int m) {
  int i, j, p, *x = _wa, *y = _wb, *t;
  for (i = 0; i < m; i++) _ws[i] = 0;
  for (i = 0; i < n; i++) _ws[x[i] = r[i]]++;
  for (i = 1; i < m; i++) _ws[i] += _ws[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--_ws[x[i]]] = i;
  for (j = 1, p = 1; p < n; j <<= 1, m = p) {
    for (p = 0, i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < n; i++) _wv[i] = x[y[i]];
    for (i = 0; i < m; i++) _ws[i] = 0;
    for (i = 0; i < n; i++) _ws[_wv[i]]++;
    for (i = 1; i < m; i++) _ws[i] += _ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--_ws[_wv[i]]] = y[i];
    for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
      x[sa[i]] = _cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
}
int rnk[2000100], ht[2000100];
void Get_H(int *r, int *sa, int n) {
  int i, j, k = 0;
  for (i = 0; i <= n; i++) rnk[sa[i]] = i;
  for (i = 0; i < n; ht[rnk[i++]] = k)
    for (k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++)
      ;
}
int sa[2000100], pr[2000100];
struct Node {
  int l, m, id;
} ax[2000100];
int cmp(const Node &a, const Node &b) {
  if (a.l < b.l)
    return 1;
  else if (a.l == b.l) {
    if (a.m < b.m)
      return 1;
    else
      return 0;
  } else
    return 0;
}
int main() {
  scanf("%s", s);
  int zer = 0, one = 0, len = strlen(s), _len = len;
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < _len; i++)
    if (s[i] == '(')
      sum1++;
    else
      sum2++;
  for (int i = 0; i < _len - 1; i++) s[len++] = s[i];
  s[len] = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '(')
      pr[i] = 1;
    else
      pr[i] = 2;
  }
  pr[len] = 0;
  Get_Sa(pr, sa, len + 1, 3);
  Get_H(pr, sa, len);
  build(1, 0, len - 1);
  for (int i = 0; i < _len; i++) {
    lb = rb = 0;
    ax[i].l = qury(1, 0, len - 1, i, i + _len - 1);
    ax[i].m = rnk[i];
    ax[i].id = i;
  }
  sort(ax, ax + _len, cmp);
  int bj = ax[0].id;
  string ans = "";
  for (int i = 0; i < ax[0].l; i++) ans += '(';
  for (int i = bj; i < _len; i++) ans += s[i];
  for (int i = 0; i < bj; i++) ans += s[i];
  int lef = sum1 + ax[0].l - sum2;
  for (int i = 0; i < lef; i++) ans += ')';
  cout << ans << endl;
  return 0;
}
