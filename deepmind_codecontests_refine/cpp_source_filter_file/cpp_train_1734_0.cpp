#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 200007;
const int MAXL = 19;
const int L = 18;
int n;
int a[MAXN];
bool _cc[MAXL][MAXN * 2 + 7], *cc[MAXL];
int ans, md[MAXL], cur[MAXL];
void init();
void input();
void work();
void srch(int lev);
int main() {
  init();
  input();
  work();
}
void init() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < MAXL; ++i) cc[i] = _cc[i] + MAXN + 3;
}
void input() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
}
void work() {
  for (int i = 1; i <= n; ++i) cc[0][a[i]] = true;
  ans = INF;
  srch(0);
  printf("%d\n", ans);
  for (int i = 0; i < L; ++i)
    if (md[i]) printf("%d ", md[i] * (1 << i));
  putchar('\n');
}
void srch(int lev) {
  if (lev == L) {
    if (cc[L][1] || cc[L][-1]) return;
    int nc = 0;
    for (int i = 0; i < L; ++i)
      if (cur[i]) ++nc;
    if (nc < ans) {
      ans = nc;
      for (int i = 0; i < L; ++i) md[i] = cur[i];
    }
    return;
  }
  int ms = 1 << (L - lev);
  bool hv = false;
  for (int i = -ms + 1; i < ms; ++i) {
    if (cc[lev][i] && (i & 1)) {
      hv = true;
      break;
    }
  }
  int vs = 1 << (L - lev - 1);
  for (int i = -vs; i <= vs; ++i) cc[lev + 1][i] = 0;
  if (!hv) {
    cur[lev] = 0;
    for (int i = -ms + 1; i < ms; ++i)
      if (cc[lev][i]) cc[lev + 1][i >> 1] = true;
    srch(lev + 1);
  } else {
    cur[lev] = 1;
    for (int i = -ms + 1; i < ms; ++i)
      if (cc[lev][i]) cc[lev + 1][(i & 1) ? ((i - 1) >> 1) : (i >> 1)] = true;
    srch(lev + 1);
    for (int i = -vs; i <= vs; ++i) cc[lev + 1][i] = 0;
    cur[lev] = -1;
    for (int i = -ms + 1; i < ms; ++i)
      if (cc[lev][i]) cc[lev + 1][(i & 1) ? ((i + 1) >> 1) : (i >> 1)] = true;
    srch(lev + 1);
  }
}
