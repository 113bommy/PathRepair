#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
template <class T>
inline void in(T &x) {
  x = 0;
  bool f = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ '0'), c = getchar();
  if (f) x = -x;
}
long long tre[32 * 200005][2], cnt = 1;
long long fa[32 * 200005];
long long n;
char tc[100];
const long long rt = 1;
bool del[32 * 200005], hv[32 * 200005], phv[32 * 200005];
long long d[200005], cntd, h[200005], cnth;
void inser(long long num, long long mx, long long typ) {
  long long x = rt;
  if (mx == 0) {
    if (typ)
      del[x] = 1, d[++cntd] = x;
    else
      hv[x] = 1, h[++cnth] = x, phv[x] = 1;
    return;
  }
  for (register long long i = 31; i >= 0; --i) {
    if (!tre[x][(num >> i) & 1]) tre[x][(num >> i) & 1] = ++cnt, fa[cnt] = x;
    x = tre[x][(num >> i) & 1];
    if (32 - i == mx) {
      if (typ)
        del[x] = 1, d[++cntd] = x;
      else
        hv[x] = 1, h[++cnth] = x, phv[x] = 1;
      break;
    }
  }
}
void ins() {
  long long len = strlen(tc + 1), wei = 0, p = 2, num = 0, mx = 32;
  for (; wei < 4;) {
    long long x = 0;
    while (p <= len && isdigit(tc[p])) x = x * 10 + tc[p] - '0', ++p;
    if (wei == 0)
      num += x << 24;
    else if (wei == 1)
      num += x << 16;
    else if (wei == 2)
      num += x << 8;
    else
      num += x;
    ++wei;
    ++p;
  }
  if (p <= len) {
    long long x = 0;
    while (p <= len && isdigit(tc[p])) x = x * 10 + tc[p] - '0', ++p;
    mx = x;
  }
  inser(num, mx, tc[1] == '-');
}
void gun() {
  puts("-1");
  exit(0);
}
vector<string> ans;
const long long bit = (1 << 8) - 1;
void toans(long long num, long long mx) {
  num <<= 32 - mx;
  stringstream str;
  for (register long long wei = 0; wei < 4; ++wei) {
    long long x = (num & (bit << ((4 - wei - 1) * 8))) >> ((4 - wei - 1) * 8);
    str << x;
    if (wei < 3)
      str << ".";
    else
      str << "/";
  }
  str << mx;
  string res;
  str >> res;
  ans.push_back(res);
}
void dfs(long long x, long long num, long long dep) {
  if (!x) return;
  if (del[x]) {
    toans(num, dep);
    return;
  }
  dfs(tre[x][0], num << 1, dep + 1);
  dfs(tre[x][1], num << 1 | 1, dep + 1);
}
signed main() {
  in(n);
  for (register long long i = 1; i <= n; ++i) {
    scanf("%s", tc + 1);
    ins();
  }
  sort(d + 1, d + 1 + cntd);
  cntd = unique(d + 1, d + 1 + cntd) - d - 1;
  sort(h + 1, h + 1 + cnth);
  cnth = unique(h + 1, h + 1 + cnth) - h - 1;
  for (register long long i = 1; i <= cnth; ++i) {
    long long x = h[i];
    while (x) {
      if (del[x]) gun();
      hv[x] = 1;
      x = fa[x];
    }
  }
  for (register long long i = 1; i <= cntd; ++i) {
    long long x = d[i];
    while (x) {
      if (phv[x]) gun();
      if (hv[x]) break;
      del[x] = 1;
      x = fa[x];
    }
  }
  dfs(1, 0, 0);
  printf("%lld\n", (long long)ans.size());
  for (register long long i = 0; i < (long long)ans.size(); ++i)
    cout << ans[i] << '\n';
  return 0;
}
