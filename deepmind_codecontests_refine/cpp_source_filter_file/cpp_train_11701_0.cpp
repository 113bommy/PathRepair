#include <bits/stdc++.h>
using namespace std;
char s[10001];
char t[20][10001];
int tl[20];
int l[10001];
int r[10001];
int n, len;
int z[10001];
char b[10001];
char good[4005][4005];
const unsigned long long mod = 123526111;
const unsigned long long mod2 = 1234567891;
const unsigned long long alpha = 31;
unsigned long long h[5005];
unsigned long long h2[5005];
unsigned long long apow[5005];
unsigned long long apow2[5005];
set<pair<unsigned long long, unsigned long long> > ht;
int res = 0;
void addh(int l, int r) {
  unsigned long long hl = h[l] * apow[r - l];
  hl %= mod;
  unsigned long long ch = (h[r] - hl + mod) % mod;
  unsigned long long hl2 = h2[l] * apow2[r - l];
  hl2 %= mod2;
  unsigned long long ch2 = (h2[r] - hl2 + mod2) % mod2;
  if (ht.find(make_pair(ch, ch2)) == ht.end()) {
    ht.insert(make_pair(ch, ch2));
    ++res;
  }
}
inline void calc(int n) {
  for (int i = 0; i <= n; ++i) z[i] = 0;
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && b[z[i]] == b[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}
int sum[100001];
void solve(const int lb) {
  int ret = 0;
  for (int i = lb + 1; i <= len; ++i) good[lb][i] = 1;
  int bl = 0;
  for (int i = lb; i < len; ++i) b[bl++] = s[i];
  b[bl++] = '#';
  int bs = bl;
  for (int ii = 0; ii < n; ++ii) {
    bl = bs;
    for (int i = 0; i < tl[ii]; ++i) b[bl++] = t[ii][i];
    calc(bl);
    for (int i = 0; i <= bs; ++i) sum[i] = 0;
    for (int i = bs; i < bl; ++i) {
      sum[z[i]]++;
    }
    int cs = 0;
    for (int i = bs; i >= 0; --i) {
      cs += sum[i];
      sum[i] = cs;
    }
    for (int i = 1; i < bs; ++i)
      if (!(l[ii] <= sum[i] && sum[i] <= r[ii])) {
        good[lb][lb + i] = 0;
      }
  }
}
int main() {
  gets(s);
  len = strlen(s);
  for (int i = 0; i < len; ++i) {
    h[i + 1] = h[i] * alpha + (s[i] - 'a' + 1);
    h[i + 1] %= mod;
    h2[i + 1] = h[i] * alpha + (s[i] - 'a' + 1);
    h2[i + 1] %= mod2;
  }
  apow[0] = apow2[0] = 1;
  for (int i = 0; i <= len; ++i) {
    apow[i + 1] = (apow[i] * alpha) % mod;
    apow2[i + 1] = (apow[i] * alpha) % mod2;
  }
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%d%d\n", t[i], l + i, r + i);
    tl[i] = strlen(t[i]);
  }
  for (int i = 0; i < len; ++i) solve(i);
  n = len;
  for (int len = 1; len <= n; ++len) {
    for (int i = 0; i + len <= n; ++i)
      if (good[i][i + len]) {
        addh(i, i + len);
      }
    ht.clear();
  }
  cout << res << '\n';
}
