#include <bits/stdc++.h>
using namespace std;
int n, m;
int getmax(int* a, int n) {
  int cnt = 0;
  int s = 0;
  int res = *max_element(a, a + n);
  for (int i = 0; i < n; ++i) {
    s += a[i];
    if (s < 0) {
      s = 0;
      cnt = 0;
    } else
      cnt++;
    if (cnt > 0) res = max(res, s);
  }
  return res;
}
int len[1 << 6];
int a[1 << 6][1 << 13];
int p[1 << 6][1 << 13];
int s[1 << 6][1 << 13];
int ms[1 << 6];
int mp[1 << 6];
int mm[1 << 6];
int b[1 << 18];
long long go(int L, int R) {
  if (R - L == 1) return mm[b[L]];
  int M = (L + R) / 2;
  long long res = max(go(L, M), go(M, R));
  long long maxR = -(1LL << 60);
  long long maxL = -(1LL << 60);
  long long now = 0;
  for (int i = M; i < R; ++i) {
    maxR = max(maxR, now + mp[b[i]]);
    now += p[b[i]][len[b[i]]];
    maxR = max(maxR, now);
  }
  now = 0;
  for (int i = M - 1; i >= L; --i) {
    maxL = max(maxL, now + ms[b[i]]);
    now += p[b[i]][len[b[i]]];
    maxL = max(maxL, now);
  }
  res = max(res, maxR);
  res = max(res, maxL);
  res = max(res, maxL + maxR);
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &len[i]);
    for (int j = 0; j < len[i]; ++j) scanf("%d", &a[i][j]);
    ms[i] = -(int)1e9;
    mp[i] = -(int)1e9;
    s[i][0] = p[i][0] = 0;
    for (int j = 0; j < len[i]; ++j) {
      s[i][j + 1] = s[i][j] + a[i][len[i] - j - 1];
      p[i][j + 1] = p[i][j] + a[i][j];
      ms[i] = max(ms[i], s[i][j + 1]);
      mp[i] = max(mp[i], p[i][j + 1]);
    }
    mm[i] = getmax(a[i], len[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
    b[i]--;
  }
  printf("%I64d\n", go(0, m));
  return 0;
}
