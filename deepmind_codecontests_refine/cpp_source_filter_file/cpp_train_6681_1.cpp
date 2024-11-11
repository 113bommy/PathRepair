#include <bits/stdc++.h>
using namespace std;
const int N = 200010, BL = 447;
int n, m, A[N], B[N];
char s[N], ss[N];
int num[N], len[N], nxt[N];
void kmp(int n, char* a, int m, char* b) {
  int i, j;
  for (nxt[0] = j = -1, i = 1; i < n; nxt[++i] = j) {
    while (~j && a[j + 1] != a[i]) j = nxt[j];
    if (a[j + 1] == a[i]) ++j;
  }
  for (j = -1, i = 0; i < m; ++i) {
    while (~j && a[j + 1] != b[i]) j = nxt[j];
    if (a[j + 1] == b[i]) ++j;
    if (j == n - 1) {
      if (i - n + 1 >= 0) ++A[i - n + 1 + 1], ++B[i + 1];
      j = nxt[j];
    }
  }
}
int ed[N], em[N], chf[N][26], tt;
void insfTire(int p) {
  for (int l = strlen(s), first = 0, i = l - 1, w; i >= 0; --i) {
    if (!chf[first][w = s[i] - 'a']) chf[first][w] = ++tt;
    first = chf[first][w];
    if (i == 0) ed[first] = p, em[first]++;
  }
}
int edz[N], emz[N], chz[N][26], ttz;
void inszTire(int p) {
  for (int l = strlen(s), first = 0, i = 0, w; i <= l - 1; ++i) {
    if (!chz[first][w = s[i] - 'a']) chz[first][w] = ++ttz;
    first = chz[first][w];
    if (i == l - 1) edz[first] = p, emz[first]++;
  }
}
int main() {
  scanf(" %s", ss + 1);
  int L = strlen(ss + 1);
  scanf("%d", &m);
  for (int i = (1); i <= (m); ++i) {
    scanf(" %s", s);
    len[i] = strlen(s);
    if (len[i] > BL) {
      kmp(len[i], s, L, ss + 1);
    }
    insfTire(i);
    inszTire(i);
  }
  long long ans = 0, BB, AA;
  for (int i = (1); i <= (L - 1); ++i) {
    BB = AA = 0;
    int now = 0;
    for (int j = (i); j >= (i - BL + 1); --j)
      if (j >= 1) {
        now = chf[now][ss[j] - 'a'];
        if (!now) break;
        if (ed[now]) BB += em[now];
      }
    now = 0;
    for (int j = (i + 1); j <= (i + BL); ++j)
      if (j <= L) {
        now = chz[now][ss[j] - 'a'];
        if (!now) break;
        if (edz[now]) AA += emz[now];
      }
    ans += (long long)(B[i - 1 + 1] + BB) * (AA + A[i + 1]);
  }
  printf("%lld\n", ans);
  return 0;
}
