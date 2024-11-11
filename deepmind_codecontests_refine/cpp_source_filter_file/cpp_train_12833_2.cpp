#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool d = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') d = 0;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return d ? x : -x;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar('0' + x % 10);
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
inline void writep(long long x) {
  write(x);
  putchar(' ');
}
inline unsigned long long rnd() {
  return ((unsigned long long)rand() << 30 ^ rand()) << 4 | rand() % 4;
}
const int N = 1e5 + 5, M = 2e5 + 5, mo = 1e9 + 7;
int p[M], opt, mn[M];
bool used[M];
vector<long long> v;
void init(int n) {
  for (int i = (int)(2); i <= (int)(n); i++) {
    if (!used[i]) p[++opt] = mn[i] = i;
    for (int j = 1; j <= opt && p[j] * i <= n; j++) {
      used[i * p[j]] = 1;
      mn[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
  for (int i = (int)(2); i <= (int)(n); i++)
    if (!used[i] && i <= 447) v.push_back(i);
}
struct tree {
  int mx[N << 2], a[N];
  void buildtree(int k, int l, int r) {
    if (l == r) {
      mx[k] = a[l];
      return;
    }
    int mid = l + r >> 1;
    buildtree(k << 1, l, mid);
    buildtree(k << 1 | 1, mid + 1, r);
    mx[k] = max(mx[k << 1], mx[k << 1 | 1]);
  }
  int find(int k, int l, int r, int L, int R) {
    if (l >= L && r <= R) return mx[k];
    int mid = l + r >> 1;
    if (R <= mid) return find(k << 1, l, mid, L, R);
    if (L > mid) return find(k << 1 | 1, mid + 1, r, L, R);
    return max(find(k << 1, l, mid, L, R), find(k << 1 | 1, mid + 1, r, L, R));
  }
} T[86];
int b[N], pos[M], fac[N], inv[N];
int ksm(int x, int p) {
  int res = 1;
  for (; p; p >>= 1, x = (long long)x * x % mo) {
    if (p & 1) res = (long long)res * x % mo;
  }
  return res;
}
int tot, root[N], las[N], lson[N * 30], rson[N * 30], zyk[N * 30], myh[N * 30];
void ins(int &k, int pre, int l, int r, int pos, int x, int y) {
  k = ++tot;
  lson[k] = lson[pre];
  rson[k] = rson[pre];
  zyk[k] = (long long)zyk[pre] * x % mo;
  myh[k] = (long long)myh[pre] * y % mo;
  if (l == r) return;
  int mid = l + r >> 1;
  if (pos <= mid)
    ins(lson[k], lson[pre], l, mid, pos, x, y);
  else
    ins(rson[k], rson[pre], mid + 1, r, pos, x, y);
}
int query(int k, int pre, int l, int r, int L, int R) {
  if (!k) return 1;
  if (l >= L && r <= R) return (long long)myh[k] * zyk[pre] % mo;
  int mid = l + r >> 1;
  if (R <= mid) return query(lson[k], lson[pre], l, mid, L, R);
  if (L > mid) return query(rson[k], rson[pre], mid + 1, r, L, R);
  int ssw = query(lson[k], lson[pre], l, mid, L, R);
  int ksg = query(rson[k], rson[pre], mid + 1, r, L, R);
  return (long long)ssw * ksg % mo;
}
int main() {
  init(M - 1);
  int n = read();
  for (int i = (int)(1); i <= (int)(n); i++) b[i] = read();
  for (int i = (int)(0); i <= (int)((int)v.size() - 1); i++) pos[v[i]] = i;
  for (int i = (int)(1); i <= (int)(n); i++) {
    int x = b[i];
    b[i] = 1;
    while (x != 1) {
      if (mn[x] > 447)
        b[i] = mn[x];
      else
        T[pos[mn[x]]].a[i]++;
      x /= mn[x];
    }
  }
  zyk[0] = myh[0] = 1;
  for (int i = (int)(fac[0] = inv[0] = 1); i <= (int)(n); i++) {
    fac[i] = (long long)fac[i - 1] * b[i] % mo;
    int INV = ksm(b[i], mo - 2);
    inv[i] = (long long)inv[i - 1] * INV % mo;
    if (las[b[i]])
      ins(root[i], root[i - 1], 1, n, las[b[i]], b[i], INV);
    else
      root[i] = root[i - 1];
    las[b[i]] = i;
  }
  for (int i = (int)(0); i <= (int)((int)v.size() - 1); i++)
    T[i].buildtree(1, 1, n);
  int Q = read(), la = 0;
  while (Q--) {
    int l = (read() + la) % n + 1, r = (read() + la) % n + 1;
    if (l > r) swap(l, r);
    int ans = (long long)fac[r] * inv[l - 1] % mo;
    int jb = query(root[r], root[l - 1], 1, n, l, r);
    ans = (long long)ans * jb % mo;
    for (int i = (int)(0); i <= (int)((int)v.size() - 1); i++) {
      int ssw = T[i].find(1, 1, n, l, r);
      ans = (long long)ans * ksm(v[i], ssw) % mo;
    }
    writeln(la = ans);
  }
}
