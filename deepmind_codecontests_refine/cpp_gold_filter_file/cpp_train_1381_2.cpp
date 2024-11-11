#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long p = 1, data = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    data = data * 10 + (ch ^ 48);
    ch = getchar();
  }
  return p * data;
}
inline long long qpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = a * r;
    a = a * a;
    b >>= 1;
  }
  return r;
}
inline long long gcd(long long a, long long b) {
  if (!a || !b) return (!a) ? b : a;
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b)
    x = 1, y = 0;
  else {
    exgcd(b, a % b, y, x);
    y -= x * (a / b);
  }
}
const int mod = 1e9 + 7, maxn = 2e5 + 5;
int a[maxn], b[maxn], cnt[maxn], last[maxn], n, ok;
int fa[maxn << 1], val[maxn << 1], vis[maxn << 1];
int find(int x) { return fa[x] = fa[x] == x ? x : find(fa[x]); }
void unite(int x, int y) {
  if (x != y) fa[x] = y, val[y] += val[x];
}
void work(int x, int t, int p) {
  int u = find(p), v = find(last[x]), tu = find(p + n), tv = find(last[x] + n);
  if (!t) {
    if (a[last[x]] != x) {
      unite(v, u);
      unite(tv, tu);
    } else {
      unite(tv, u);
      unite(v, tu);
    }
  } else {
    if (b[last[x]] != x) {
      unite(v, u);
      unite(tv, tu);
    } else {
      unite(tv, u);
      unite(v, tu);
    }
  }
}
int main() {
  int T = read();
  while (T--) {
    n = read(), ok = 1;
    for (int i = 1; i <= n; i++)
      last[i] = cnt[i] = 0, fa[i] = i, fa[i + n] = i + n, val[i] = 0,
      val[i + n] = 1;
    for (int i = 1; i <= n; i++) a[i] = read(), cnt[a[i]]++;
    for (int i = 1; i <= n; i++) b[i] = read(), cnt[b[i]]++;
    for (int i = 1; i <= n; i++)
      if (cnt[i] != 2) {
        ok = 0;
        break;
      }
    if (!ok) {
      puts("-1");
      continue;
    }
    for (int i = 1; i <= n; i++) {
      int ta = a[i];
      if (last[ta] == i) continue;
      if (last[ta])
        work(ta, 0, i);
      else
        last[ta] = i;
    }
    for (int i = 1; i <= n; i++) {
      int tb = b[i];
      if (last[tb] == i) continue;
      if (last[tb])
        work(tb, 1, i);
      else
        last[tb] = i;
    }
    vector<int> ans;
    for (int i = 1; i <= 2 * n; i++) vis[i] = 0, fa[i] = find(i);
    for (int i = 1; i <= n; i++) {
      if (!vis[fa[i]] && !vis[fa[i + n]]) {
        if (val[fa[i]] > val[fa[i + n]])
          vis[fa[i + n]] = 1;
        else
          vis[fa[i]] = 1;
      }
    }
    for (int i = 1; i <= n; i++)
      if (vis[fa[i + n]]) ans.push_back(i);
    printf("%d\n", ans.size());
    for (auto x : ans) printf("%d ", x);
    puts("");
  }
  return 0;
}
