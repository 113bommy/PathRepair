#include <bits/stdc++.h>
int read() {
  static int ch, x;
  while ((ch = getchar()) < 48) {
  }
  x = ch ^ 48;
  while ((ch = getchar()) >= 48) x = (((x << 2) + x) << 1) + (ch ^ 48);
  return x;
}
const int SIG = 27;
char s[100010];
int a[100010], sum[100010];
int pre[100010][SIG], suf[100010][SIG], pans[100010][SIG], sans[100010][SIG];
bool vis[SIG];
std::pair<int, int> st[SIG];
int main() {
  scanf("%s", s + 2);
  const int n = strlen(s + 2) + 2;
  s[1] = s[n] = 26 + 'a';
  for (int i = 1; i <= n; ++i) {
    a[i] = s[i] - 'a';
    for (int j = 0; j < SIG; ++j) pre[i][j] = pre[i - 1][j];
    pre[i][a[i]] = i;
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < SIG; ++j) suf[i][j] = suf[i + 1][j];
    suf[i][a[i]] = i;
  }
  for (int i = n; i >= 1; --i) {
    int top = 0;
    for (int j = 0; j < SIG; ++j) {
      if (const int t = suf[i][j]) st[++top] = std::make_pair(t, j);
    }
    std::sort(st + 1, st + top + 1);
    const int t = suf[i + 1][a[i]];
    if (t && t < n) {
      sum[i] = pans[i + 1][a[i]];
      sum[i] ^= sum[t];
    }
    for (int j = 1; j <= top; ++j) {
      const int pos = st[j].first, col = st[j].second;
      for (int k = 0; k < SIG; ++k) vis[k] = false;
      for (int k = 1; k < j; ++k) {
        const int p = st[k].second, u = pre[pos][p];
        int res = pans[i][p] ^ sum[suf[i][p]] ^ sum[u];
        if (u) res ^= pans[u + 1][col];
        if (res < SIG) vis[res] = true;
      }
      int &res = pans[i][col];
      while (res < SIG && vis[res]) ++res;
    }
    for (int j = 0; j < SIG; ++j)
      if (!suf[i][j]) pans[i][j] = pans[i][SIG - 1];
  }
  for (int i = 1; i <= n; ++i) {
    int top = 0;
    for (int j = 0; j < SIG; ++j) {
      if (const int t = pre[i][j]) st[++top] = std::make_pair(t, j);
    }
    std::sort(st + 1, st + top + 1, std::greater<std::pair<int, int>>());
    for (int j = 1; j <= top; ++j) {
      const int pos = st[j].first, col = st[j].second;
      for (int k = 0; k < SIG; ++k) vis[k] = false;
      for (int k = 1; k < j; ++k) {
        const int p = st[k].second, u = suf[pos][p];
        int res = sans[i][p] ^ sum[pre[i][p]] ^ sum[u];
        if (u <= n) res ^= sans[u - 1][col];
        if (res < SIG) vis[res] = true;
      }
      int &res = sans[i][col];
      while (res < SIG && vis[res]) ++res;
    }
    for (int j = 0; j < SIG; ++j)
      if (!pre[i][j]) sans[i][j] = sans[i][SIG - 1];
  }
  for (int m = read(); m--;) {
    const int l = read() + 1, r = read() + 1;
    bool flag = false;
    for (int i = 0; i < SIG; ++i) {
      const int t = suf[l][i];
      if (t && t <= r) {
        const int u = pre[r][i];
        int res = pans[l][i] ^ sum[t] ^ sum[u];
        if (u) res ^= sans[r][i];
        if (!res) {
          flag = true;
          break;
        }
      }
    }
    puts(flag ? "Alice" : "Bob");
  }
  return 0;
}
