#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<int> vec[300009];
long long ans, tag[300009][4], st[300009];
int n, m, rnk[300009], tong[300009], sa[300009], y[300009], h[300009],
    f[300009], be[300009], top;
char s[300009], s1[300009], s2[300009], s3[300009];
inline void MOD(long long &x) {
  while (x >= mod) x -= mod;
}
inline void qsort() {
  for (int i = 0; i <= m; ++i) tong[i] = 0;
  for (int i = 1; i <= n; ++i) tong[rnk[i]]++;
  for (int i = 1; i <= m; ++i) tong[i] += tong[i - 1];
  for (int i = n; i >= 1; --i) sa[tong[rnk[y[i]]]--] = y[i];
}
inline void SA() {
  m = 300;
  for (int i = 1; i <= n; ++i) rnk[i] = s[i], y[i] = i;
  qsort();
  for (int w = 1, p = 0; w < n; w <<= 1) {
    p = 0;
    for (int i = n - w + 1; i <= n; ++i) y[++p] = i;
    for (int i = 1; i <= n; ++i)
      if (sa[i] > w) y[++p] = sa[i] - w;
    qsort();
    swap(y, rnk);
    rnk[sa[1]] = p = 1;
    for (int i = 2; i <= n; ++i)
      rnk[sa[i]] =
          (y[sa[i]] == y[sa[i - 1]]) && (y[sa[i] + w] == y[sa[i - 1] + w])
              ? p
              : ++p;
  }
  for (int i = 1; i <= n; ++i) {
    if (rnk[i] == 1) continue;
    int j = max(0, h[rnk[i - 1]] - 1);
    while (s[i + j] == s[sa[rnk[i] - 1] + j]) j++;
    h[rnk[i]] = j;
    vec[j].push_back(rnk[i]);
  }
}
int find(int x) { return f[x] = f[x] == x ? x : find(f[x]); }
int main() {
  scanf("%s%s%s", s1, s2, s3);
  int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
  for (int i = 0; i < len1; ++i) s[++n] = s1[i], be[n] = 1;
  s[++n] = '#';
  for (int i = 0; i < len2; ++i) s[++n] = s2[i], be[n] = 2;
  s[++n] = '$';
  for (int i = 0; i < len3; ++i) s[++n] = s3[i], be[n] = 3;
  s[++n] = '(';
  SA();
  int x = min(len3, min(len1, len2));
  for (int i = 1; i <= n; ++i) {
    if (be[i]) tag[i][be[i]]++;
    f[i] = i;
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < vec[i].size(); ++j) {
      int x = vec[i][j], xx = find(sa[x - 1]), yy = find(sa[x]);
      if (xx != yy) {
        f[xx] = yy;
        ans = ((ans - tag[xx][1] * tag[xx][2] % mod * tag[xx][3] % mod) % mod +
               mod) %
              mod;
        ans = ((ans - tag[yy][1] * tag[yy][2] % mod * tag[yy][3] % mod) % mod +
               mod) %
              mod;
        MOD(tag[yy][1] += tag[xx][1]);
        MOD(tag[yy][2] += tag[xx][2]);
        MOD(tag[yy][3] += tag[xx][3]);
        ans = ((ans + tag[yy][1] * tag[yy][2] % mod * tag[yy][3] % mod) % mod +
               mod) %
              mod;
      }
    }
    if (i <= x) st[++top] = ans;
  }
  for (int i = top; i >= 1; --i) printf("%I64d ", st[i]);
  return 0;
}
