#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 200010;
char s[maxn];
long long p[maxn];
long long h[maxn];
int len;
int lcp(int x, int y) {
  int l = 0;
  int r = len + 1;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    long long h1 = h[x + m - 1];
    if (x) h1 -= h[x - 1];
    long long h2 = h[y + m - 1];
    if (y) h2 -= h[y - 1];
    if (x < y)
      h1 *= p[y - x];
    else
      h2 *= p[x - y];
    if (h1 == h2)
      l = m;
    else
      r = m;
  }
  return l;
}
bool cmp(int x, int y) {
  int cur = lcp(x, y);
  return s[x + cur] < s[y + cur];
}
int sm[maxn];
const int maxt = (1 << 18) + 10;
long long t[maxt] = {};
long long curadd[maxt] = {};
bool needset[maxt] = {};
int needadd[maxt] = {};
void push(int v, int L, int R) {
  int ls = v * 2 + 1;
  int rs = v * 2 + 2;
  int m = (L + R) >> 1;
  if (needset[v]) {
    t[v] = 0;
    curadd[v] = R - L + 1;
    if (R != L) {
      needset[ls] = 1;
      needset[rs] = 1;
      needadd[ls] = 0;
      needadd[rs] = 0;
    }
    needset[v] = 0;
  }
  long long tadd = curadd[v];
  if (needadd[v]) {
    t[v] +=
        tadd * needadd[v] + (needadd[v] - 1LL) * (needadd[v]) / 2 * (R - L + 1);
    curadd[v] += (R - L + 1) * needadd[v];
    if (L != R) {
      needadd[ls] += needadd[v];
      needadd[rs] += needadd[v];
    }
    needadd[v] = 0;
  }
}
void recalc(int v, int L, int R) {
  if (L == R) return;
  int ls = v * 2 + 1;
  int rs = v * 2 + 2;
  int m = (L + R) >> 1;
  push(ls, L, m);
  push(rs, m + 1, R);
  t[v] = t[ls] + t[rs];
  curadd[v] = curadd[ls] + curadd[rs];
}
void build(int v, int L, int R) {
  int m = (L + R) >> 1;
  if (L == R) {
    curadd[v] = 1;
    t[v] = 0;
    needadd[v] = needset[v] = 0;
  } else {
    int m = (L + R) >> 1;
    build(v * 2 + 1, L, m);
    build(v * 2 + 2, m + 1, R);
    recalc(v, L, R);
  }
}
void modifyadd(int v, int l, int r, int L, int R) {
  push(v, L, R);
  if (l > r) return;
  if (l > R || L > r) return;
  if (L >= l && R <= r) {
    needadd[v] = 1;
    return;
  }
  int m = (L + R) >> 1;
  modifyadd(v * 2 + 1, l, r, L, m);
  modifyadd(v * 2 + 2, l, r, m + 1, R);
  recalc(v, L, R);
}
void modifyset(int v, int l, int r, int L, int R) {
  push(v, L, R);
  if (l > r) return;
  if (l > R || L > r) return;
  if (L >= l && R <= r) {
    needset[v] = 1;
    return;
  }
  int m = (L + R) >> 1;
  modifyset(v * 2 + 1, l, r, L, m);
  modifyset(v * 2 + 2, l, r, m + 1, R);
  recalc(v, L, R);
}
long long query(int v, int l, int r, int L, int R) {
  push(v, L, R);
  if (l > r) return 0;
  if (l > R || L > r) return 0;
  if (L >= l && R <= r) return t[v];
  int m = (L + R) >> 1;
  return query(v * 2 + 1, l, r, L, m) + query(v * 2 + 2, l, r, m + 1, R);
}
string deb() {
  stringstream ans;
  for (int i = 0; i < len; ++i) {
    ans << query(0, i, i, 0, len - 1) << " ";
  }
  string s;
  getline(ans, s);
  return s;
}
int main() {
  scanf("%s", &s);
  int n = strlen(s);
  for (int i = 0; i <= n; ++i) s[i + n + 1] = s[i];
  p[0] = 1;
  for (int i = 1; i <= 2 * n + 5; ++i) p[i] = p[i - 1] * 43;
  for (int i = 0; i <= 2 * n; ++i) {
    if (s[i]) h[i] = (s[i] - 'a' + 1) * p[i];
    if (i) h[i] += h[i - 1];
  }
  len = n + 1;
  for (int i = 0; i < len; ++i) sm[i] = i;
  sort(sm, sm + len, cmp);
  build(0, 0, len - 1);
  long long ans = 0;
  for (int i = 0; i < len - 1; ++i) {
    int cur = lcp(sm[i], sm[i + 1]);
    int tr = len - 2 - sm[i + 1];
    ans += query(0, cur, len - 1, 0, len - 1);
    modifyadd(0, 0, cur - 1, 0, len - 1);
    modifyset(0, cur, len - 1, 0, len - 1);
    modifyadd(0, cur, tr, 0, len - 1);
  }
  ans += query(0, 0, len - 1, 0, len - 1);
  cout << ans << endl;
  return 0;
}
