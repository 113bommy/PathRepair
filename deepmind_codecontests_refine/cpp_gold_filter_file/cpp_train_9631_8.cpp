#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const unsigned long long base = 3170119;
const long long mod = 1e9 + 7;
void upd(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
char s[2][maxn], t[maxn];
int n, lent;
unsigned long long pnum[maxn], suml[2][maxn], sumr[2][maxn], sumt[maxn];
void init_hash() {
  pnum[0] = 1;
  for (int i = 1; i < maxn; ++i) pnum[i] = pnum[i - 1] * base;
  suml[0][0] = s[0][0];
  suml[1][0] = s[1][0];
  for (int i = 1; i < n; ++i) {
    suml[0][i] = suml[0][i - 1] * base + s[0][i];
    suml[1][i] = suml[1][i - 1] * base + s[1][i];
  }
  sumr[0][n - 1] = s[0][n - 1];
  sumr[1][n - 1] = s[1][n - 1];
  for (int i = n - 2; i >= 0; --i) {
    sumr[0][i] = sumr[0][i + 1] * base + s[0][i];
    sumr[1][i] = sumr[1][i + 1] * base + s[1][i];
  }
  sumt[0] = t[0];
  for (int i = 1; i < lent; ++i) sumt[i] = sumt[i - 1] * base + t[i];
}
bool is_match(int tl, int tr, int tag, int sl, int sr, int d) {
  unsigned long long valt, vals;
  valt = sumt[tr];
  if (tl) valt -= sumt[tl - 1] * pnum[tr - tl + 1];
  if (d) {
    vals = sumr[tag][sl];
    if (sr < n - 1) vals -= sumr[tag][sr + 1] * pnum[sr - sl + 1];
  } else {
    vals = suml[tag][sr];
    if (sl) vals -= suml[tag][sl - 1] * pnum[sr - sl + 1];
  }
  return vals == valt;
}
int fl[2][maxn][maxn], fr[2][maxn][maxn];
bool visl[2][maxn][maxn], visr[2][maxn][maxn];
int solve_l(int tag, int pos, int len) {
  if (visl[tag][pos][len]) return fl[tag][pos][len];
  visl[tag][pos][len] = 1;
  int &ans = fl[tag][pos][len];
  ans = 0;
  if (s[tag][pos] ^ t[len]) return ans;
  if (len == lent - 1) return ans = 1;
  if (len == lent - 2) {
    if (t[len + 1] == s[tag ^ 1][pos]) ++ans;
    if (pos && s[tag][pos - 1] == t[lent - 1]) ++ans;
    return ans;
  }
  if (pos && s[tag ^ 1][pos] == t[len + 1])
    upd(ans, solve_l(tag ^ 1, pos - 1, len + 2));
  if (pos) upd(ans, solve_l(tag, pos - 1, len + 1));
  int tmp = lent - len;
  if (tmp % 2 == 0 && tmp / 2 <= pos + 1) {
    if (is_match(len, len + tmp / 2 - 1, tag, pos - tmp / 2 + 1, pos, 1) &&
        is_match(len + tmp / 2, lent - 1, tag ^ 1, pos - tmp / 2 + 1, pos, 0))
      ++ans;
  }
  return ans;
}
int solve_r(int tag, int pos, int len) {
  if (visr[tag][pos][len]) return fr[tag][pos][len];
  visr[tag][pos][len] = 1;
  int &ans = fr[tag][pos][len];
  ans = 0;
  if (s[tag][pos] ^ t[len]) return ans;
  if (len == lent - 1) return ans = 1;
  if (len == lent - 2) {
    if (t[len + 1] == s[tag ^ 1][pos]) ++ans;
    if (pos < n - 1 && s[tag][pos + 1] == t[lent - 1]) ++ans;
    return ans;
  }
  if (pos < n - 1 && s[tag ^ 1][pos] == t[len + 1])
    upd(ans, solve_r(tag ^ 1, pos + 1, len + 2));
  if (pos < n - 1) upd(ans, solve_r(tag, pos + 1, len + 1));
  int tmp = lent - len;
  if (tmp % 2 == 0 && tmp / 2 <= n - pos) {
    if (is_match(len, len + tmp / 2 - 1, tag, pos, pos + tmp / 2 - 1, 0) &&
        is_match(len + tmp / 2, lent - 1, tag ^ 1, pos, pos + tmp / 2 - 1, 1))
      ++ans;
  }
  return ans;
}
int main() {
  scanf("%s%s%s", s[0], s[1], t);
  n = strlen(s[0]);
  lent = strlen(t);
  if (lent == 1) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[0][i] == t[0]) ++ans;
      if (s[1][i] == t[0]) ++ans;
    }
    printf("%d\n", ans);
    return 0;
  }
  init_hash();
  int ans = 0;
  for (int pos = 0; pos < n; ++pos)
    for (int tag = 0; tag < 2; ++tag) {
      upd(ans, solve_l(tag, pos, 0));
      upd(ans, solve_r(tag, pos, 0));
      if (lent == 2 && s[tag][pos] == t[0] && s[tag ^ 1][pos] == t[1]) --ans;
      if (pos < n - 1) {
        for (int i = pos - 1; i >= 0; --i) {
          if ((pos - i + 1) * 2 >= lent) break;
          if (is_match(0, pos - i, tag, i, pos, 1) &&
              is_match(pos - i + 1, (pos - i + 1) * 2 - 1, tag ^ 1, i, pos, 0))
            upd(ans, solve_r(tag ^ 1, pos + 1, (pos - i + 1) * 2));
        }
      }
      if (pos) {
        for (int i = pos + 1; i < n; ++i) {
          if ((i - pos + 1) * 2 >= lent) break;
          if (is_match(0, i - pos, tag, pos, i, 0) &&
              is_match(i - pos + 1, (i - pos + 1) * 2 - 1, tag ^ 1, pos, i, 1))
            upd(ans, solve_l(tag ^ 1, pos - 1, (i - pos + 1) * 2));
        }
      }
    }
  ans = (ans % mod + mod) % mod;
  printf("%d\n", ans);
  return 0;
}
