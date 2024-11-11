#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read(register T& t) {
  register T f = 1;
  register char ch = getchar();
  t = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') t = t * 10 + ch - '0', ch = getchar();
  t *= f;
  return t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
const long long p = 998244353;
inline long long power(register long long x, register long long k = p - 2) {
  register long long re = 1;
  for (; k; k >>= 1, x = (x * x) % p)
    if (k & 1) re = (re * x) % p;
  return re;
}
int n, m;
int head[100005], ne[200005], to[200005], total = 1;
int deg[100005];
inline void add(int a, int b) {
  deg[a]++;
  total++;
  to[total] = b;
  ne[total] = head[a];
  head[a] = total;
}
int fa[100005];
vector<int> cir;
vector<int> thd;
vector<int> mth;
void find_cir(int now) {
  if (cir.size()) return;
  if (deg[now] > 3) mth.push_back(now);
  if (deg[now] == 3) thd.push_back(now);
  for (int i = head[now]; i; i = ne[i])
    if (to[i] != fa[now]) {
      if (cir.size()) return;
      if (fa[to[i]]) {
        int qwq = now;
        while (qwq != to[i]) cir.push_back(qwq), qwq = fa[qwq];
        cir.push_back(to[i]);
        return;
      }
      fa[to[i]] = now;
      find_cir(to[i]);
    }
}
void reroot(int now) {
  for (int i = head[now]; i; i = ne[i])
    if (to[i] != fa[now]) fa[to[i]] = now, reroot(to[i]);
}
vector<int> lin[3];
void find_lin(int now, int fa, vector<int>& lin) {
  lin.push_back(now);
  for (int i = head[now]; i; i = ne[i])
    if (to[i] != fa) find_lin(to[i], now, lin);
}
void work() {
  memset(deg, 0, sizeof(deg));
  total = 1;
  memset(head, 0, sizeof(head));
  read(n, m);
  for (int i = 1, x, y; i <= m; i++) read(x, y), add(x, y), add(y, x);
  cir.clear();
  memset(fa, 0, sizeof(fa));
  static long long ans[100005];
  memset(ans, 0, sizeof(ans));
  for (int qwq = 1; qwq <= n; qwq++)
    if (!fa[qwq]) {
      thd.clear();
      mth.clear();
      fa[qwq] = qwq;
      find_cir(qwq);
      if (cir.size()) {
        for (auto i : cir) ans[i] = 1;
        printf("YES\n");
        for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
        printf("\n");
        return;
      }
      if (mth.size()) {
        int now = mth[0];
        ans[now] = 2;
        for (int i = head[now]; i; i = ne[i]) ans[to[i]] = 1;
        printf("YES\n");
        for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
        printf("\n");
        return;
      }
      if (thd.size() >= 2) {
        int a = thd[0], b = thd[1];
        memset(fa, 0, sizeof(fa));
        reroot(b);
        int aa = a;
        while (aa != b) ans[aa] = 2, aa = fa[aa];
        ans[b] = 2;
        for (int i = head[a]; i; i = ne[i])
          if (ans[to[i]] == 0) ans[to[i]] = 1;
        for (int i = head[b]; i; i = ne[i])
          if (ans[to[i]] == 0) ans[to[i]] = 1;
        printf("YES\n");
        for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
        printf("\n");
        return;
      }
      if (thd.size()) {
        int now = thd[0];
        lin[0].clear();
        lin[1].clear();
        lin[2].clear();
        int tnt = -1;
        for (int i = head[now]; i; i = ne[i]) find_lin(to[i], now, lin[++tnt]);
        sort(lin, lin + 3, [](vector<int>& a, vector<int>& b) {
          return a.size() < b.size();
        });
        long long a = lin[0].size() + 1, b = lin[1].size() + 1,
                  c = lin[2].size() + 1;
        if (a * c + b * c + a * b > a * b * c) continue;
        if (a * b * c > 1e6) {
          if (lin[0].size() >= 1 && lin[1].size() >= 2 && lin[2].size() >= 5) {
            while (lin[0].size() > 1) lin[0].pop_back();
            while (lin[1].size() > 2) lin[1].pop_back();
            while (lin[2].size() > 5) lin[2].pop_back();
          }
          if (lin[0].size() >= 1 && lin[1].size() >= 3 && lin[2].size() >= 3) {
            while (lin[0].size() > 1) lin[0].pop_back();
            while (lin[1].size() > 3) lin[1].pop_back();
            while (lin[2].size() > 3) lin[2].pop_back();
          }
          if (lin[0].size() >= 2 && lin[1].size() >= 2 && lin[2].size() >= 2) {
            while (lin[0].size() > 2) lin[0].pop_back();
            while (lin[1].size() > 2) lin[1].pop_back();
            while (lin[2].size() > 2) lin[2].pop_back();
          }
        }
        a = lin[0].size() + 1, b = lin[1].size() + 1, c = lin[2].size() + 1;
        ans[now] = a * b * c;
        long long tp;
        tp = ans[now];
        for (auto i : lin[0]) tp -= b * c, ans[i] = tp;
        tp = ans[now];
        for (auto i : lin[1]) tp -= a * c, ans[i] = tp;
        tp = ans[now];
        for (auto i : lin[2]) tp -= a * b, ans[i] = tp;
        printf("YES\n");
        for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
        printf("\n");
        return;
      }
    }
  printf("NO\n");
  return;
}
int main() {
  int T;
  read(T);
  while (T--) work();
  return 0;
}
