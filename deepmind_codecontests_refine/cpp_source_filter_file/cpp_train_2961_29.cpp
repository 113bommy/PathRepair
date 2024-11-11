#include <bits/stdc++.h>
using namespace std;
long long gcd(long long u, long long v) {
  while (v != 0) {
    long long r = u % v;
    u = v;
    v = r;
  }
  return u;
}
int n, nq;
int a[100000];
int q[100000][3];
int v[200000], nv;
int getid(int x) {
  int l = 0, h = nv;
  while (l + 1 < h) {
    int m = l + (h - l) / 2;
    if (v[m] <= x)
      l = m;
    else
      h = m;
  }
  return l;
}
int cnt[101][200000];
int frq[101][100001];
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  scanf("%d", &nq);
  for (int i = (0); i < (nq); ++i)
    scanf("%d%d%d", &q[i][0], &q[i][1], &q[i][2]);
  nv = 0;
  for (int i = (0); i < (n); ++i) v[nv++] = a[i];
  for (int i = (0); i < (nq); ++i)
    if (q[i][0] == 1) v[nv++] = q[i][1];
  sort(v, v + nv);
  int nnv = 0;
  for (int i = (0); i < (nv); ++i)
    if (nnv == 0 || v[i] != v[nnv - 1]) v[nnv++] = v[i];
  nv = nnv;
  for (int i = (0); i < (n); ++i) a[i] = getid(a[i]);
  for (int i = (0); i < (nq); ++i)
    if (q[i][0] == 1) q[i][1] = getid(q[i][1]);
  int nb = 100, len = (n + 99) / nb;
  memset(cnt, 0, sizeof(cnt));
  memset(frq, 0, sizeof(frq));
  for (int b = (0); b < (nb); ++b) {
    for (int i = (0); i < (nv); ++i) cnt[b + 1][i] = cnt[b][i];
    for (int i = (0); i <= (n); ++i) frq[b + 1][i] = frq[b][i];
    for (int i = (b * len); i < (min(n, (b + 1) * len)); ++i) {
      ++cnt[b + 1][a[i]];
      ++frq[b + 1][cnt[b + 1][a[i]]];
    }
  }
  for (int qi = (0); qi < (nq); ++qi) {
    if (q[qi][0] == 1) {
      int x = q[qi][1], c = q[qi][2] - 1, b = c / len;
      for (int bb = (b + 1); bb <= (nb); ++bb) {
        --frq[bb][cnt[bb][a[c]]];
        --cnt[bb][a[c]];
      }
      a[c] = x;
      for (int bb = (b + 1); bb <= (nb); ++bb) {
        ++cnt[bb][a[c]];
        ++frq[bb][cnt[bb][a[c]]];
      }
    } else {
      int r = q[qi][1] - 1, c = q[qi][2] - 1, b = c / len;
      int v0 = v[a[c]];
      int v1 = cnt[b][v0];
      for (int i = (b * len); i <= (c); ++i)
        if (a[i] == v0) ++v1;
      int v2 = frq[b][v1];
      for (int i = (b * len); i <= (c); ++i)
        if (++cnt[b][a[i]] == v1) ++v2;
      for (int i = (b * len); i <= (c); ++i) --cnt[b][a[i]];
      printf("%d\n", r == 0 ? v0 : r % 2 == 1 ? v1 : v2);
    }
  }
}
int main() {
  run();
  return 0;
}
