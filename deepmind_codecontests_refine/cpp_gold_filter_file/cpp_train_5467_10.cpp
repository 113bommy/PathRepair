#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1.01e9;
const double eps = 1e-9;
const int maxn = (int)1e6 + 10;
const long long INF = (long long)1e18;
const int mod = (int)1e9 + 7;
char s[maxn];
int dx[maxn];
int dy[maxn];
int mnx[maxn], mxx[maxn], mny[maxn], mxy[maxn];
long long a[maxn], b[maxn];
int len, n, m;
long long getx(int x) {
  long long res = 0;
  if (mnx[len] + x >= 0 && mxx[len] + x < n) {
    if (dx[len] == 0) return INF;
    int L = 0, R = n;
    while (L < R) {
      int M = (L + R) >> 1;
      if (mnx[len] + x + M * (long long)dx[len] >= 0 &&
          mxx[len] + x + M * (long long)dx[len] < n) {
        L = M + 1;
      } else
        R = M;
    }
    x += L * (long long)dx[len];
    res += len * (long long)L;
  }
  int L = 0, R = len;
  while (L < R) {
    int M = (L + R + 1) >> 1;
    if (mnx[M] + x >= 0 && mxx[M] + x < n) {
      L = M;
    } else
      R = M - 1;
  }
  return res + L;
}
long long gety(int y) {
  long long res = 0;
  if (mny[len] + y >= 0 && mxy[len] + y < m) {
    if (dy[len] == 0) return INF;
    int L = 0, R = m;
    while (L < R) {
      int M = (L + R) >> 1;
      if (mny[len] + y + M * (long long)dy[len] >= 0 &&
          mxy[len] + y + M * (long long)dy[len] < m) {
        L = M + 1;
      } else
        R = M;
    }
    y += L * (long long)dy[len];
    res += len * (long long)L;
  }
  int L = 0, R = len;
  while (L < R) {
    int M = (L + R + 1) >> 1;
    if (mny[M] + y >= 0 && mxy[M] + y < m) {
      L = M;
    } else
      R = M - 1;
  }
  return res + L;
}
long long sa[maxn];
int main() {
  scanf("%d%d%d", &len, &n, &m);
  scanf("%s", s);
  for (int i = 0; (i) < (len); ++i) {
    dx[i + 1] = dx[i];
    dy[i + 1] = dy[i];
    if (s[i] == 'U') dx[i + 1] -= 1;
    if (s[i] == 'D') dx[i + 1] += 1;
    if (s[i] == 'L') dy[i + 1] -= 1;
    if (s[i] == 'R') dy[i + 1] += 1;
  }
  for (int i = 1; i <= len; ++i) {
    mnx[i] = min(mnx[i - 1], dx[i]);
    mxx[i] = max(mxx[i - 1], dx[i]);
    mny[i] = min(mny[i - 1], dy[i]);
    mxy[i] = max(mxy[i - 1], dy[i]);
  }
  for (int i = 0; (i) < (n); ++i) {
    a[i] = getx(i) + 1;
    sa[i + 1] = (sa[i] + a[i]) % mod;
  }
  for (int i = 0; (i) < (m); ++i) {
    b[i] = gety(i) + 1;
  }
  long long res = 0;
  int pos = 0;
  for (int i = 0; (i) < (n); ++i)
    if (a[i] > a[pos]) pos = i;
  for (int j = 0; (j) < (m); ++j) {
    if (b[j] == INF + 1 && a[pos] == INF + 1) return 0 * printf("-1\n");
    if (b[j] >= a[pos])
      res = (res + sa[n]) % mod;
    else {
      int L1 = 0, R1 = pos;
      while (L1 < R1) {
        int M = (L1 + R1) >> 1;
        if (a[M] > b[j])
          R1 = M;
        else
          L1 = M + 1;
      }
      int L2 = pos, R2 = n - 1;
      while (L2 < R2) {
        int M = (L2 + R2 + 1) >> 1;
        if (a[M] > b[j])
          L2 = M;
        else
          R2 = M - 1;
      }
      res = (res + sa[L1] + (long long)sa[n] - sa[L2 + 1] + mod) % mod;
      res = (res + (L2 - L1 + 1) * (long long)(b[j] % mod)) % mod;
    }
  }
  printf("%I64d\n", res);
  return 0;
}
