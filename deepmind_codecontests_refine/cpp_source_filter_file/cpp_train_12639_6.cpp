#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
const int N = 100005;
char s[N];
int cnt[N][26], f[N][22];
long long tag[N], g[N][26];
unsigned long long h[N], mi[N];
unsigned long long geth(int l, int r) {
  return h[r] - h[l - 1] * mi[r - l + 1];
}
bool ext(int l, int r, int ch) { return cnt[r][ch] - cnt[l - 1][ch] > 0; }
void Cover(int l, int r, long long v) { tag[l] += v, tag[r + 1] -= v; }
int getpos(int l, int m, int r) {
  int L = 0, R = r - m, pos = 0;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (geth(l, l + mid - 1) == geth(m + 1, m + mid))
      pos = mid, R = mid - 1;
    else
      L = mid + 1;
  }
  pos++;
  if (m + pos == r || geth(l + pos, m - 1) == geth(m + pos + 1, r)) return pos;
  return -1;
}
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    s[i] -= 'a';
    for (int c = 0; c < 26; ++c) cnt[i][c] = cnt[i - 1][c];
    cnt[i][s[i]]++;
  }
  mi[0] = 1;
  long long sum = 0;
  for (int i = 1; i <= n; ++i) mi[i] = mi[i - 1] * 131;
  for (int i = 1; i <= n; ++i) h[i] = h[i - 1] * 131 + s[i];
  for (int i = 1; i <= n; ++i) f[i][0] = 1, sum++;
  for (int j = 1; j <= 17; ++j) {
    for (int i = 129; i <= n; ++i) {
      int d = (1 << j) - 1, l = i - d, r = i + d;
      if (l < 1 || r > n) continue;
      bool fl = f[i - (d + 1) / 2][j - 1], fr = f[i + (d + 1) / 2][j - 1],
           fm = geth(l, i - 1) == geth(i + 1, r);
      f[i][j] = fl && fr && fm && !ext(l, i - 1, s[i]);
      long long val = 1ll * (r - l + 1) * (r - l + 1);
      if (f[i][j]) {
        sum += val, Cover(l, i - 1, -val), Cover(i + 1, r, -val);
        for (int c = 0; c < 26; ++c)
          if (ext(l, i - 1, c)) g[i][c] -= val;
      } else {
        if (fl && fr && fm) {
          for (int c = 0; c < 26; ++c)
            if (!ext(l, i - 1, c)) g[i][c] += val;
        } else if (!fm) {
          int p = getpos(l, i, r);
          if (~p) {
            if (fl && !ext(l, i - 1, s[i])) g[i + p][s[l + p - 1]] += val;
            if (fr && !ext(i + 1, r, s[i])) g[l + p - 1][s[i + p]] += val;
          }
        }
      }
    }
  }
  long long ans = sum, now = 0;
  for (int i = 1; i <= n; ++i) {
    now += tag[i];
    for (int c = 0; c < 26; ++c)
      if (c != s[i]) ans = max(ans, sum + now + g[i][c]);
  }
  cout << ans;
  return 0;
}
