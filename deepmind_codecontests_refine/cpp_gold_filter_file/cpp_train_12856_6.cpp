#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 10000020;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int bufpos;
char buf[MAXSIZE];
void init() {
  buf[fread(buf, 1, MAXSIZE, stdin)] = '\0';
  bufpos = 0;
}
int readint() {
  int val = 0;
  for (; !isdigit(buf[bufpos]); bufpos++)
    ;
  for (; isdigit(buf[bufpos]); bufpos++) val = val * 10 + buf[bufpos] - '0';
  return val;
}
char readchar() {
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  return buf[bufpos++];
}
int readstr(char* s) {
  int cur = 0;
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  for (; !isspace(buf[bufpos]); bufpos++) s[cur++] = buf[bufpos];
  s[cur] = '\0';
  return cur;
}
pair<int, int> a[30004], b[30004];
int p[30004], to[30004];
long long prod0[30004], prod1[30004], prod2[30004], prod3[30004], prod4[30004];
long long dp[30004];
int now[30004];
inline void tense(long long& x, long long y) {
  if (x < y) x = y;
}
int main() {
  init();
  int n = readint(), q = readint();
  for (int i = 1; i <= n; i++) a[i] = make_pair(readint(), i);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) b[i] = make_pair(readint(), i);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) p[a[i].second] = i;
  for (int i = 1; i <= n; i++) to[p[b[i].second]] = i;
  for (int i = 1; i <= n; i++) {
    prod0[i] = 1LL * a[i].first * b[i].first;
    if (i > 1) prod1[i] = 1LL * a[i].first * b[i - 1].first;
    if (i > 2) prod2[i] = 1LL * a[i].first * b[i - 2].first;
    if (i < n) prod3[i] = 1LL * a[i].first * b[i + 1].first;
    if (i < n - 1) prod4[i] = 1LL * a[i].first * b[i + 2].first;
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = -INF;
    if (to[i] != i) tense(dp[i], dp[i - 1] + prod0[i]);
    if (i > 1 && to[i] != i - 1) {
      if (to[i - 1] != i) tense(dp[i], dp[i - 2] + prod1[i] + prod3[i - 1]);
      if (to[i - 1] != i - 2 && to[i - 2] != i)
        tense(dp[i], dp[i - 3] + prod1[i] + prod1[i - 1] + prod4[i - 2]);
    }
    if (i > 2 && to[i] != i - 2) {
      if (to[i - 1] != i && to[i - 2] != i - 1)
        tense(dp[i], dp[i - 3] + prod2[i] + prod3[i - 1] + prod3[i - 2]);
      if (to[i - 1] != i - 1 && to[i - 2] != i)
        tense(dp[i], dp[i - 3] + prod2[i] + prod0[i - 1] + prod4[i - 2]);
    }
  }
  while (q--) {
    int x = p[readint()], y = p[readint()];
    swap(to[x], to[y]);
    for (int i = max(min(x, y) - 2, 1); i <= n; i++) {
      dp[i] = -INF;
      if (to[i] != i) tense(dp[i], dp[i - 1] + prod0[i]);
      if (i > 1 && to[i] != i - 1) {
        if (to[i - 1] != i) tense(dp[i], dp[i - 2] + prod1[i] + prod3[i - 1]);
        if (to[i - 1] != i - 2 && to[i - 2] != i)
          tense(dp[i], dp[i - 3] + prod1[i] + prod1[i - 1] + prod4[i - 2]);
      }
      if (i > 2 && to[i] != i - 2) {
        if (to[i - 1] != i && to[i - 2] != i - 1)
          tense(dp[i], dp[i - 3] + prod2[i] + prod3[i - 1] + prod3[i - 2]);
        if (to[i - 1] != i - 1 && to[i - 2] != i)
          tense(dp[i], dp[i - 3] + prod2[i] + prod0[i - 1] + prod4[i - 2]);
      }
    }
    printf("%lld\n", dp[n]);
  }
}
