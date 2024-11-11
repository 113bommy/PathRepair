#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
struct to {
  short p1;
  short p2;
  short state;
  bool take;
  to(short _p1 = -1, short _p2 = -1, short _st = -1, bool t = false)
      : p1(_p1), p2(_p2), state(_st), take(t) {}
};
short dp[MAXN][MAXN][MAXN];
to path[MAXN][MAXN][MAXN];
char s1[MAXN], s2[MAXN], virus[MAXN];
int len1, len2, lenvir;
int p[MAXN];
void prefix(const char* s, int n) {
  for (int i = 1; i < n; ++i) {
    int j = p[i - 1];
    while (j > 0 && s[i] != s[j]) j = p[j - 1];
    if (s[i] == s[j]) j++;
    p[i] = j;
  }
}
int go(int j, char c) {
  while (j > 0 && virus[j] != c) j = p[j - 1];
  if (virus[j] == c) j++;
  return j;
}
int rec(int p1, int p2, int state) {
  if (dp[p1][p2][state] != -1) return dp[p1][p2][state];
  if (p1 == len1) return dp[p1][p2][state] = 0;
  if (p2 == len2) return dp[p1][p2][state] = 0;
  if (state == lenvir) return dp[p1][p2][state] = 0;
  int cur = -1;
  int tmpres = 0;
  to tmpto;
  tmpres = rec(p1 + 1, p2, state);
  if (tmpres > cur) {
    cur = tmpres;
    tmpto = to(p1 + 1, p2, state, false);
  }
  tmpres = rec(p1, p2 + 1, state);
  if (tmpres > cur) {
    cur = tmpres;
    tmpto = to(p1, p2 + 1, state, false);
  }
  tmpres = rec(p1 + 1, p2 + 1, state);
  if (tmpres > cur) {
    cur = tmpres;
    tmpto = to(p1 + 1, p2 + 1, state, false);
  }
  if (s1[p1] == s2[p2]) {
    int tostate = go(state, s1[p1]);
    if (tostate < lenvir) {
      tmpres = rec(p1 + 1, p2 + 1, tostate) + 1;
      if (tmpres > cur) {
        cur = tmpres;
        tmpto = to(p1 + 1, p2 + 1, tostate, true);
      }
    }
  }
  path[p1][p2][state] = tmpto;
  return dp[p1][p2][state] = cur;
}
int main() {
  memset(dp, -1, sizeof(dp));
  gets(s1);
  len1 = strlen(s1);
  gets(s2);
  len2 = strlen(s2);
  gets(virus);
  lenvir = strlen(virus);
  prefix(virus, lenvir);
  int reslen = rec(0, 0, 0);
  if (reslen == 0) {
    puts("0");
    return 0;
  }
  int printed = 0;
  int p1 = 0, p2 = 0, state = 0;
  while (printed < reslen) {
    to next = path[p1][p2][state];
    if (next.take) {
      putchar(s1[p1]);
      ++printed;
    }
    p1 = next.p1;
    p2 = next.p2;
    state = next.state;
  }
  return 0;
}
