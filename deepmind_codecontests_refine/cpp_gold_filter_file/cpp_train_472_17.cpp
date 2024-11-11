#include <bits/stdc++.h>
using namespace std;
char s[100005], t[100005];
int q, ls, lt, c[100005], rk[100005];
long long pw[100005], hst[100005], hs[100005];
long long calc(int u, int l) {
  if (l <= u) return hs[l];
  if (l <= u + lt) return (hs[u] * pw[l - u] + hst[l - u]) % 998244353;
  return ((hs[u] * pw[l - u] + hst[lt] * pw[l - u - lt] + hs[l - lt] -
           hs[u] * pw[l - lt - u]) %
              998244353 +
          998244353) %
         998244353;
}
int getc(int u, int l) {
  if (l <= u) return s[l];
  if (l <= u + lt) return t[l - u];
  return s[l - lt];
}
bool cmp(const int &u, const int &v) {
  int L = 0, R = ls + lt, mid;
  for (; L < R;) {
    mid = L + R + 1 >> 1;
    if (calc(u, mid) == calc(v, mid))
      L = mid;
    else
      R = mid - 1;
  }
  return getc(u, L + 1) < getc(v, L + 1);
}
int L[100005], R[100005], K[100005], X[100005], Y[100005], lg[100005],
    ans[100005];
vector<int> G[100005];
vector<vector<int> > st;
bool cmp2(const int &u, const int &v) {
  if (rk[u] < rk[v] || (rk[u] == rk[v] && u < v)) return 1;
  return 0;
}
int qry(int u, int v) {
  if (u > v) return ls + 1;
  int t = lg[v - u + 1];
  return cmp2(st[t][u], st[t][v - (1 << t) + 1]) ? st[t][u]
                                                 : st[t][v - (1 << t) + 1];
}
int main() {
  scanf("%s%s%d", s + 1, t + 1, &q);
  ls = strlen(s + 1);
  lt = strlen(t + 1);
  for (int i = (1), LIM = (ls); i <= LIM; i++)
    hs[i] = (hs[i - 1] * 100 + s[i]) % 998244353;
  for (int i = (1), LIM = (lt); i <= LIM; i++)
    hst[i] = (hst[i - 1] * 100 + t[i]) % 998244353;
  pw[0] = 1;
  for (int i = (1), LIM = (ls + lt); i <= LIM; i++)
    pw[i] = pw[i - 1] * 100 % 998244353;
  for (int i = (0), LIM = (ls); i <= LIM; i++) c[i] = i;
  sort(c, c + ls + 1, cmp);
  int cnt = 0;
  for (int i = (0), LIM = (ls); i <= LIM; i++)
    if (i == 0 || cmp(c[i - 1], c[i]))
      rk[c[i]] = ++cnt;
    else
      rk[c[i]] = cnt;
  st = vector<vector<int> >(17, vector<int>(ls + 1));
  for (int i = (0), LIM = (ls); i <= LIM; i++) st[0][i] = i;
  for (int j = (1), LIM = (17 - 1); j <= LIM; j++)
    for (int i = (0), LIM = (ls - (1 << j) + 1); i <= LIM; i++)
      st[j][i] = cmp2(st[j - 1][i], st[j - 1][i + (1 << j - 1)])
                     ? st[j - 1][i]
                     : st[j - 1][i + (1 << j - 1)];
  for (int i = (2), LIM = (ls); i <= LIM; i++) lg[i] = lg[i >> 1] + 1;
  rk[ls + 1] = 0x3f3f3f3f;
  for (int i = (1), LIM = (q); i <= LIM; i++) {
    scanf("%d%d%d%d%d", &L[i], &R[i], &K[i], &X[i], &Y[i]);
    ans[i] = ls + 1;
    if (K[i] <= 100)
      G[K[i]].push_back(i);
    else {
      for (int j = 0; j * K[i] + X[i] <= ls; j++)
        if (j * K[i] + X[i] <= R[i] && j * K[i] + Y[i] >= L[i]) {
          int t = qry(max(j * K[i] + X[i], L[i]), min(j * K[i] + Y[i], R[i]));
          if (cmp2(t, ans[i])) ans[i] = t;
        }
    }
  }
  for (int i = (1), LIM = (100); i <= LIM; i++)
    for (int j = (0), LIM = (i - 1); j <= LIM; j++) {
      st = vector<vector<int> >(17, vector<int>(ls / i + 5));
      int len;
      for (len = 0; i * len + j <= ls; len++) st[0][len] = i * len + j;
      for (int k = (1), LIM = (17 - 1); k <= LIM; k++)
        for (int p = (0), LIM = (len - (1 << k) + 1); p <= LIM; p++)
          st[k][p] = cmp2(st[k - 1][p], st[k - 1][p + (1 << k - 1)])
                         ? st[k - 1][p]
                         : st[k - 1][p + (1 << k - 1)];
      for (int v : G[i])
        if (X[v] <= j && j <= Y[v]) {
          int t = qry((int)ceil((1.0 * L[v] - j) / i),
                      (int)floor((1.0 * R[v] - j) / i));
          if (cmp2(t, ans[v])) ans[v] = t;
        }
    }
  for (int i = (1), LIM = (q); i <= LIM; i++)
    if (ans[i] == ls + 1) ans[i] = -1;
  for (int i = (1), LIM = (q); i <= LIM; i++)
    printf("%d%c", ans[i], " \n"[i == q]);
}
