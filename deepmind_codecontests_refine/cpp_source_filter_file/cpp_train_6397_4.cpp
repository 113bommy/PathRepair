#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int maxn = 1000005;
int wa[maxn], wb[maxn], wv[maxn], Ws[maxn];
int cmp(int *r, int a, int b, int l) {
  return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(const int *r, int *sa, int n, int m) {
  int i, j, p, *x = wa, *y = wb, *t;
  for (i = 0; i < m; i++) Ws[i] = 0;
  for (i = 0; i < n; i++) Ws[x[i] = r[i]]++;
  for (i = 1; i < m; i++) Ws[i] += Ws[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--Ws[x[i]]] = i;
  for (j = 1, p = 1; p < n; j *= 2, m = p) {
    for (p = 0, i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < n; i++) wv[i] = x[y[i]];
    for (i = 0; i < m; i++) Ws[i] = 0;
    for (i = 0; i < n; i++) Ws[wv[i]]++;
    for (i = 1; i < m; i++) Ws[i] += Ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--Ws[wv[i]]] = y[i];
    for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
  return;
}
int sa[maxn], Rank[maxn], height[maxn];
void calheight(const int *r, int *sa, int n) {
  int i, j, k = 0;
  for (i = 1; i <= n; i++) Rank[sa[i]] = i;
  for (i = 0; i < n; height[Rank[i++]] = k)
    for (k ? k-- : 0, j = sa[Rank[i] - 1]; r[i + k] == r[j + k]; k++)
      ;
  return;
}
int a[maxn], n, f[maxn], c[maxn][4], m = maxn;
char str[maxn];
vector<int> v[maxn];
set<pair<int, int> > myset;
long long get(int l, int r) {
  int A = c[r][1] - c[l - 1][1];
  int B = c[r][2] - c[l - 1][2];
  int C = c[r][3] - c[l - 1][3];
  if (!A || !B || !C) return -1;
  return 1LL * A * B * C;
}
int main() {
  long long now = 1LL;
  scanf("%s", str);
  m = min(m, (int)strlen(str));
  now *= strlen(str);
  for (int i = 0; str[i]; i++) {
    f[n] = 1;
    a[n++] = str[i] - 'a' + 1;
  }
  a[n++] = 27;
  scanf("%s", str);
  m = min(m, (int)strlen(str));
  now *= strlen(str);
  for (int i = 0; str[i]; i++) {
    f[n] = 2;
    a[n++] = str[i] - 'a' + 1;
  }
  a[n++] = 28;
  scanf("%s", str);
  m = min(m, (int)strlen(str));
  now *= strlen(str);
  for (int i = 0; str[i]; i++) {
    f[n] = 3;
    a[n++] = str[i] - 'a' + 1;
  }
  a[n++] = 29;
  a[n] = 0;
  da(a, sa, n + 1, 50);
  calheight(a, sa, n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) c[i][j] = c[i - 1][j];
    c[i][f[sa[i]]]++;
  }
  for (int i = 1; i <= n; i++) v[height[i]].push_back(i);
  myset.insert(make_pair(1, n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      int p = v[i][j];
      set<pair<int, int> >::iterator it = myset.upper_bound(make_pair(p, MOD));
      if (it == myset.begin()) break;
      it--;
      if (it->first < p && it->second >= p) {
        pair<int, int> pp = *it;
        long long ttt = get(pp.first, pp.second);
        if (ttt != -1) now -= ttt;
        myset.erase(it);
        long long ppp = get(pp.first, p - 1);
        if (ppp != -1) {
          now += ppp;
          myset.insert(make_pair(pp.first, p - 1));
        }
        long long qqq = get(p, pp.second);
        if (qqq != -1) {
          now += qqq;
          myset.insert(make_pair(p, pp.second));
        }
      }
    }
    printf("%I64d\n", now % MOD);
  }
  return 0;
}
