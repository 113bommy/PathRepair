#include <bits/stdc++.h>
char str[200005], rev[200005];
int len[200005], st[200005][25], mn[200005], bit[200005], nxt[200005];
inline void kmp(int n) {
  nxt[0] = -1;
  for (int i = 1, j = -1; i < n; i++) {
    while (~j && rev[i] != rev[j + 1]) j = nxt[j];
    j += rev[i] == rev[j + 1];
    nxt[i] = j;
  }
  for (int i = 0, j = -1; i < n; i++) {
    while (~j && str[i] != rev[j + 1]) j = nxt[j];
    j += str[i] == rev[j + 1];
    mn[j + 1] = std::min(mn[j + 1], i + 1);
  }
}
inline void manacher(int n) {
  for (int i = n - 1; i >= 0; i--) {
    str[i * 2 + 2] = str[i];
    str[i * 2 + 3] = '*';
  }
  str[0] = '#';
  str[1] = '*';
  int mx = 0, idx;
  for (int i = 1; i < n * 2 + 2; i++) {
    if (mx > i)
      len[i] = std::min(mx - i, len[idx * 2 - i]);
    else
      len[i] = 1;
    while (str[i - len[i]] == str[i + len[i]]) len[i]++;
    if (i + len[i] > mx) {
      mx = i + len[i];
      idx = i;
    }
  }
}
inline void init_st(int n) {
  for (int i = 0; i < n; i++) {
    len[i] = len[i * 2 + 2] >> 1;
    st[i][0] = i;
  }
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j + (1 << i) <= n; j++)
      st[j][i] = (len[st[j][i - 1]] > len[st[j + (1 << i - 1)][i - 1]]
                      ? (st[j][i - 1])
                      : (st[j + (1 << i - 1)][i - 1]));
  }
}
inline int query(int l, int r) {
  if (l > r) return -1;
  int lg = bit[r - l + 1];
  return (len[st[l][lg]] > len[st[r - (1 << lg) + 1][lg]]
              ? (st[l][lg])
              : (st[r - (1 << lg) + 1][lg]));
}
int main() {
  scanf("%s", str);
  int n = strlen(str);
  for (int i = 2; i < 200005; i++) bit[i] = bit[i >> 1] + 1;
  for (int i = 1; i <= n; i++) mn[i] = n;
  memcpy(rev, str, sizeof(str));
  std::reverse(rev, rev + n);
  kmp(n);
  manacher(n);
  init_st(n);
  int ans = -1, pos;
  for (int i = 0; i <= n; i++) {
    int L = mn[i], R = n - i - 1;
    if (L > R) continue;
    int l = 0, r = R - L + 1, res = -1;
    while (l <= r) {
      int m = l + r >> 1, mxp = query(L + m - 1, R - m + 1);
      if (~mxp && len[mxp] >= m) {
        res = m;
        l = m + 1;
      } else
        r = m - 1;
    }
    if (res > 0 && (res + i << 1) > ans) {
      ans = res + i << 1;
      pos = i;
    }
  }
  int l = mn[pos], r = n - pos - 1, dia = (ans - pos * 2) / 2;
  printf("%d\n", pos ? 3 : 1);
  if (pos) printf("%d %d\n", mn[pos] - pos + 1, pos);
  printf("%d %d\n", query(l + dia - 1, r - dia + 1) - dia + 2, dia * 2 - 1);
  if (pos) printf("%d %d\n", n - pos + 1, pos);
  return 0;
}
