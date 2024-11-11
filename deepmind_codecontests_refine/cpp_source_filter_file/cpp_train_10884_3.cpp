#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rread(T& num) {
  num = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') num = num * 10 + ch - '0', ch = getchar();
  num *= f;
}
inline int getgcd(int x, int y) {
  if (!x) return y;
  return getgcd(y % x, x);
}
inline long long getlcm(int x, int y) {
  return (long long)x / getgcd(x, y) * y;
}
inline long long getgcd(long long x, long long y) {
  if (!x) return y;
  return getgcd(y % x, x);
}
inline long long getlcm(long long x, long long y) {
  return x / getgcd(x, y) * y;
}
inline int power(int x, int k, int p) {
  int res = 1;
  for (; k; k >>= 1, x = (long long)x * x % p)
    if (k & 1) res = (long long)res * x % p;
  return res;
}
inline long long power(long long x, long long k, long long p) {
  long long res = 1;
  for (; k; k >>= 1, x = x * x % p)
    if (k & 1) res = res * x % p;
  return res;
}
const double pi = acos(-1);
inline void judge() { freopen("input.txt", "r", stdin); }
const int maxn = 1e5 + 5, inf = 1e9;
map<int, int> newx, newy;
int n, m, R, B;
long long ans, need;
int x[maxn], y[maxn], q[maxn], du[maxn];
int totx[maxn], toty[maxn], limx[maxn], limy[maxn], check[maxn];
namespace Maxflow {
const int maxn = 100005, maxm = 1000005, inf = 1e9;
int S, T;
int head[maxn], from[maxm], des[maxm], nxt[maxm], f[maxm], tot;
int cur[maxn], d[maxn], h[maxn], pre[maxn];
inline void init(int _S, int _T) {
  S = _S;
  T = _T;
  memset(head, 0, sizeof head);
  tot = 1;
}
inline int adde(int x, int y, int z) {
  from[++tot] = x;
  des[tot] = y;
  f[tot] = z;
  nxt[tot] = head[x];
  head[x] = tot;
  from[++tot] = y;
  des[tot] = x;
  f[tot] = 0;
  nxt[tot] = head[y];
  head[y] = tot;
  return tot;
}
inline int isap(int n) {
  int maxflow = 0, u = S;
  for (int(i) = (1); (i) <= (n); (i)++) pre[i] = d[i] = 0, cur[i] = head[i];
  h[d[0]] = n;
  while (d[S] < n) {
    if (u == T) {
      int minflow = inf, re = S;
      while (u != S) {
        if (f[pre[u]] < minflow) minflow = f[pre[u]], re = from[pre[u]];
        u = from[pre[u]];
      }
      maxflow += minflow;
      u = T;
      while (u != S) {
        f[pre[u]] -= minflow;
        f[pre[u] ^ 1] += minflow;
        u = from[pre[u]];
      }
      u = re;
    }
    bool flag = 0;
    for (int(p) = cur[(u)]; (p); (p) = nxt[(p)]) {
      if (f[p] && d[des[p]] == d[u] - 1) {
        u = des[p];
        pre[u] = p;
        flag = 1;
        break;
      }
      cur[u] = p;
    }
    if (flag) continue;
    cur[u] = head[u];
    int mind = n - 1;
    for (int(p) = cur[(u)]; (p); (p) = nxt[(p)])
      if (f[p] && d[des[p]] < mind) {
        mind = d[des[p]];
        cur[u] = p;
      }
    h[d[u]]--;
    if (!h[d[u]]) break;
    d[u] = mind + 1;
    h[d[u]]++;
    if (u != S) u = from[pre[u]];
  }
  return maxflow;
}
}  // namespace Maxflow
int main() {
  rread(n);
  rread(m);
  rread(R);
  rread(B);
  for (int(i) = (1); (i) <= (n); (i)++) rread(x[i]), rread(y[i]);
  for (int(i) = (1); (i) <= (n); (i)++) q[i] = x[i];
  sort(q + 1, q + n + 1);
  int cntx = 1;
  newx[q[1]] = 1;
  for (int(i) = (2); (i) <= (n); (i)++)
    if (q[i] != q[i - 1]) newx[q[i]] = ++cntx;
  for (int(i) = (1); (i) <= (n); (i)++) q[i] = y[i];
  sort(q + 1, q + n + 1);
  int cnty = 1;
  newy[q[1]] = 1;
  for (int(i) = (2); (i) <= (n); (i)++)
    if (q[i] != q[i - 1]) newy[q[i]] = ++cnty;
  for (int(i) = (1); (i) <= (n); (i)++)
    x[i] = newx[x[i]], y[i] = newy[y[i]], totx[x[i]]++, toty[y[i]]++;
  for (int(i) = (1); (i) <= (cntx); (i)++) limx[i] = totx[i];
  for (int(i) = (1); (i) <= (cnty); (i)++) limy[i] = toty[i];
  for (int(i) = (1); (i) <= (m); (i)++) {
    int t, l, d;
    rread(t);
    rread(l);
    rread(d);
    if (t == 1) {
      if (!newx.count(l)) continue;
      l = newx[l];
      limx[l] = min(limx[l], d);
    } else {
      if (!newy.count(l)) continue;
      l = newy[l];
      limy[l] = min(limy[l], d);
    }
  }
  int S = cntx + cnty + 1, T = S + 1, SS = T + 1, TT = SS + 1;
  Maxflow::init(SS, TT);
  for (int(i) = (1); (i) <= (cntx); (i)++) {
    int low = (totx[i] - limx[i] + 1) / 2, high = (totx[i] + limx[i]) / 2;
    if (low > high) return puts("-1"), 0;
    Maxflow::adde(S, i, high - low);
    du[S] -= low;
    du[i] += low;
  }
  for (int(i) = (1); (i) <= (cnty); (i)++) {
    int low = (toty[i] - limy[i] + 1) / 2, high = (toty[i] + limy[i]) / 2;
    if (low > high) return puts("-1"), 0;
    Maxflow::adde(i + cntx, T, high - low);
    du[i + cntx] -= low;
    du[T] += low;
  }
  for (int(i) = (1); (i) <= (n); (i)++)
    check[i] = Maxflow::adde(x[i], y[i] + cntx, 1);
  Maxflow::adde(T, S, inf);
  for (int(i) = (1); (i) <= (T); (i)++)
    if (du[i] > 0)
      Maxflow::adde(SS, i, du[i]), need += du[i];
    else
      Maxflow::adde(i, TT, -du[i]);
  if (Maxflow::isap(TT) != need)
    puts("-1");
  else {
    Maxflow::S = S;
    Maxflow::T = T;
    Maxflow::isap(T);
    for (int(i) = (1); (i) <= (n); (i)++)
      if (Maxflow::f[check[i]])
        ans += min(R, B);
      else
        ans += max(R, B);
    cout << ans << endl;
    for (int(i) = (1); (i) <= (n); (i)++)
      if (Maxflow::f[check[i]]) {
        if (R < B)
          putchar('r');
        else
          putchar('b');
      } else {
        if (R < B)
          putchar('b');
        else
          putchar('r');
      }
    puts("");
  }
  return 0;
}
