#include <bits/stdc++.h>
char ch;
bool fs;
void re(int& x) {
  while (ch = getchar(), ch < 33)
    ;
  if (ch == '-')
    fs = 1, x = 0;
  else
    fs = 0, x = ch - 48;
  while (ch = getchar(), ch > 33) x = x * 10 + ch - 48;
  if (fs) x = -x;
}
using namespace std;
int x[200005 + 200005], y[200005 + 200005];
int n, k, q, gg, ans, a[200005], f[200005], g[200005];
int tt, now, tag[1000], cnt[1000][1 << 14], en[1000];
vector<int> sy[501];
vector<int> s[200005];
int main() {
  re(n), re(k), re(q);
  for (int i = 1; i <= n; ++i) re(a[i]), f[i] = a[i];
  for (int i = 1; i <= n; ++i) re(g[i]), a[i] ^= g[i];
  ++n;
  for (int i = n; i; --i) a[i] = a[i] ^ a[i - 1];
  for (int i = 1; i <= k; ++i)
    for (int j = i, sum = 0; j <= n; j += k) {
      sum ^= a[j];
      s[i].push_back(sum);
      if (j + k <= n)
        ans += sum > 0;
      else
        gg += sum > 0;
    }
  printf("%d\n", gg ? -1 : ans);
  for (int i = 1; i <= q; ++i) {
    int opt, a, b;
    re(opt), re(a), re(b);
    opt += 48;
    int t = f[a] ^ g[a];
    if (opt == 'a')
      f[a] = b;
    else
      g[a] = b;
    b = f[a] ^ g[a] ^ t;
    x[i + i - 1] = a;
    x[i + i] = a + 1;
    y[i + i - 1] = y[i + i] = b;
  }
  q *= 2;
  if (k >= 500) {
    for (int i = 1; i <= q; ++i) {
      int id = (x[i] - 1) % k + 1, pos = (x[i] - 1) / k;
      for (int j = pos; j < s[id].size(); ++j) {
        if (j + 1 < s[id].size())
          ans -= s[id][j] > 0;
        else
          gg -= s[id][j] > 0;
        s[id][j] ^= y[i];
        if (j + 1 < s[id].size())
          ans += s[id][j] > 0;
        else
          gg += s[id][j] > 0;
      }
      if (i % 2 == 0) printf("%d\n", gg ? -1 : ans);
    }
  } else {
    for (int i = 1; i <= k; ++i) {
      for (int j = 0; j < s[i].size() - 1; ++j) {
        ++now;
        sy[i].push_back(tt);
        ++cnt[tt][s[i][j]];
        if (now == 500) now = 0, ++tt;
      }
      en[i] = tt;
      now = 0;
      ++tt;
    }
    for (int i = 1; i <= q; ++i) {
      int id = (x[i] - 1) % k + 1, pos = (x[i] - 1) / k;
      gg -= *s[id].rbegin() > 0;
      *s[id].rbegin() ^= y[i];
      gg += *s[id].rbegin() > 0;
      if (pos + 1 < s[id].size()) {
        int l = sy[id][pos] + 1;
        for (int j = pos; j < s[id].size() - 1 && sy[id][j] != l; ++j) {
          ans -= (tag[l - 1] ^ s[id][j]) > 0;
          --cnt[l - 1][s[id][j]];
          s[id][j] ^= y[i];
          ans += (tag[l - 1] ^ s[id][j]) > 0;
          ++cnt[l - 1][s[id][j]];
        }
        for (; l <= en[id]; ++l) {
          ans += cnt[l][tag[l]];
          tag[l] ^= y[i];
          ans -= cnt[l][tag[l]];
        }
      }
      if (i % 2 == 0) printf("%d\n", gg ? -1 : ans);
    }
  }
}
