#include <bits/stdc++.h>
using namespace std;
void chkmn(int &a, int b) {
  if (a > b) a = b;
}
void chkmx(int &a, int b) {
  if (a < b) a = b;
}
const int INF = 1e9 + 7;
const int N = 2e5 + 50;
int n, m, lg[N];
char S[N];
int sm[N][26], lp[N], rp[N];
vector<int> d[N];
int v[20][N];
int RMQ(int l, int r) {
  int x = lg[r - l + 1];
  return min(v[x][l], v[x][r - (1 << x) + 1]);
}
struct Suffix_Array {
  int SA[N], y[N], tmp[N], rk[N];
  int a[20][N], m;
  void radix_sort() {
    static int bin[N];
    for (int i = 1; i <= m; i++) bin[i] = 0;
    for (int i = 1; i <= n; i++) bin[rk[i]]++;
    for (int i = 1; i <= m; i++) bin[i] += bin[i - 1];
    for (int i = n; i >= 1; i--) SA[bin[rk[y[i]]]--] = y[i];
  }
  void work() {
    m = 128;
    for (int i = 1; i <= n; i++) y[i] = i, rk[i] = S[i];
    radix_sort();
    for (int k = 1, c; m != n; k <<= 1) {
      c = 0;
      for (int i = n - k + 1; i <= n; i++) y[++c] = i;
      for (int i = 1; i <= n; i++)
        if (SA[i] > k) y[++c] = SA[i] - k;
      radix_sort();
      swap(rk, tmp);
      rk[SA[c = 1]] = 1;
      for (int i = 2; i <= n; i++)
        if (tmp[SA[i]] == tmp[SA[i - 1]] &&
            tmp[SA[i] + k] == tmp[SA[i - 1] + k])
          rk[SA[i]] = c;
        else
          rk[SA[i]] = ++c;
      m = c;
    }
    for (int i = 1, h = 0; i <= n; i++) {
      if (rk[i] == 1) continue;
      int j = SA[rk[i] - 1];
      if (h) --h;
      while (j + h <= n && i + h <= n && S[i + h] == S[j + h]) ++h;
      a[0][rk[i]] = h;
    }
    for (int i = 1; (1 << i) <= n; i++)
      for (int j = 1; j + (1 << i) - 1 <= n; j++)
        a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
  }
  int LCP(int l, int r) {
    l = rk[l], r = rk[r];
    if (l > r) swap(l, r);
    ++l;
    int x = lg[r - l + 1];
    return min(a[x][l], a[x][r - (1 << x) + 1]);
  }
} t[2];
namespace zkw {
const int M = 1 << 19 | 5;
int mn[M << 1][2];
void init() { memset(mn, 0x3f, sizeof(mn)); }
void mdf(int l, int r, int v, int z) {
  if (l > r) return;
  for (l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (l & 1 ^ 1) chkmn(mn[l ^ 1][z], v);
    if (r & 1) chkmn(mn[r ^ 1][z], v);
  }
}
void ask(int x, int &a, int &b) {
  a = b = INF;
  for (x += M; x; x >>= 1) chkmn(a, mn[x][0]), chkmn(b, mn[x][1]);
}
}  // namespace zkw
void pre_work() {
  zkw::init();
  for (int len = 1; len <= n; len++)
    for (int i = len; i + len <= n; i += len) {
      int l = t[1].LCP(n - i + 1, n - i - len + 1);
      int r = t[0].LCP(i, i + len);
      int L = i - l + 1, R = i + len + r - 1;
      zkw::mdf(L + len + len - 1, R, len << 1, 1);
      zkw::mdf(L, R - len - len + 1, len << 1, 0);
    }
  for (int i = 1; i <= n; i++) zkw::ask(i, lp[i], rp[i]);
}
int border(int l, int r) {
  int S = sqrt(n);
  for (int i = 1; i <= S; i++)
    if (t[0].LCP(l, r - i + 1) >= i) return i;
  int z = t[0].rk[l], ans = INF;
  for (int i = max(1, z - S), o; i <= min(n, z + S); i++) {
    o = t[0].SA[i];
    if (o <= l || o > r) continue;
    if (t[0].LCP(l, o) >= r - o + 1) chkmn(ans, r - o + 1);
  }
  return ans;
}
int Main() {
  int l, r;
  scanf("%d%d", &l, &r);
  bool ok = false;
  for (int i = 0; i < 26 && !ok; i++) ok |= (sm[r][i] - sm[l - 1][i] > 1);
  if (!ok) return -1;
  for (int x : d[r - l + 1])
    if (t[0].LCP(l, l + x) >= r - l + 1 - x) return 1;
  int len = r - l + 1;
  if (lp[l] < len) return 2;
  if (rp[r] < len) return 2;
  int z = border(l, r);
  if (z + z < len) return 2;
  int c = S[l] - 'a';
  if (sm[r][c] - sm[l][c]) return 3;
  c = S[r] - 'a';
  if (sm[r - 1][c] - sm[l - 1][c]) return 3;
  if (RMQ(l, r) <= r) return 3;
  return 4;
}
int main() {
  scanf("%d%s", &n, S + 1);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; i++)
    for (int j = i + i; j <= n; j += i) d[j].push_back(i);
  for (int i = 1; i <= n; i++) {
    memcpy(sm[i], sm[i - 1], sizeof(sm[i]));
    ++sm[i][S[i] - 'a'];
  }
  t[0].work();
  reverse(S + 1, S + n + 1);
  t[1].work();
  reverse(S + 1, S + n + 1);
  pre_work();
  for (int i = 1; i <= n; i++) v[0][i] = i + lp[i] - 1;
  for (int i = 1; (1 << i) <= n; i++)
    for (int j = 1; j + (1 << i) - 1 <= n; j++)
      v[i][j] = min(v[i - 1][j], v[i - 1][j + (1 << (i - 1))]);
  scanf("%d", &m);
  while (m--) cout << Main() << '\n';
  return 0;
}
