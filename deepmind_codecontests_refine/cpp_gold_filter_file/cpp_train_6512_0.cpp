#include <bits/stdc++.h>
using namespace std;
void Rd(int &res) {
  res = 0;
  char p;
  while (p = getchar(), p < '0')
    ;
  do {
    res = (res * 10) + (p ^ 48);
  } while (p = getchar(), p >= '0');
}
void Max(int &x, int y) {
  if (x < y) x = y;
}
struct W {
  int to, nx, d;
} Lis[100005 << 1];
int Head[100005], tot = 1;
void Add(int x, int y, int d) {
  Lis[tot].to = y, Lis[tot].nx = Head[x], Lis[tot].d = d;
  Head[x] = tot++;
}
int n, P;
long long ans;
int q[100005], sz, cntson[100005], Mxson[100005], phi;
int fast(int x, int p) {
  int re = 1;
  while (p) {
    if (p & 1) re = (long long)re * x % P;
    x = (long long)x * x % P, p >>= 1;
  }
  return re;
}
bool vis[100005];
void dfs_pre(int x, int f) {
  cntson[x] = 1, Mxson[x] = 0, q[sz++] = x;
  for (int i = Head[x], to; i && (to = Lis[i].to, 1); i = Lis[i].nx)
    if (to != f && !vis[to])
      dfs_pre(to, x), cntson[x] += cntson[to], Max(Mxson[x], cntson[to]);
}
map<pair<int, int>, int> mp;
map<int, int> pm;
void dfs_pro(int x, int f, int v1, int c, int v2, int fac) {
  mp[pair<int, int>(v1, c)]++, pm[v2]++;
  for (int i = Head[x], to; i && (to = Lis[i].to, 1); i = Lis[i].nx)
    if (to != f && !vis[to])
      dfs_pro(to, x, (v1 * 10LL + Lis[i].d) % P, c + 1,
              (v2 + (long long)fac * Lis[i].d) % P, fac * 10LL % P);
}
void dfs(int x) {
  sz = 0;
  dfs_pre(x, x);
  int pl = cntson[x], rt = x;
  for (int i = 0; i < sz; i++) {
    int p = q[i];
    Max(Mxson[p], cntson[x] - cntson[p]);
    if (Mxson[p] < pl) pl = Mxson[p], rt = p;
  }
  mp.clear(), pm.clear();
  dfs_pro(rt, rt, 0, 0, 0, 1);
  ans--;
  for (map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end();
       it++) {
    int lp = (long long)(P - (it->first).first) *
             fast(fast(10, (it->first).second), phi) % P;
    map<int, int>::iterator it1 = pm.find(lp);
    if (it1 != pm.end()) ans += (long long)(it->second) * (it1->second);
  }
  for (int i = Head[rt], to; i && (to = Lis[i].to, 1); i = Lis[i].nx)
    if (!vis[to]) {
      mp.clear(), pm.clear();
      dfs_pro(to, rt, Lis[i].d % P, 1, Lis[i].d % P, 10 % P);
      for (map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end();
           it++) {
        int lp = (long long)(P - (it->first).first) *
                 fast(fast(10, (it->first).second), phi) % P;
        map<int, int>::iterator it1 = pm.find(lp);
        if (it1 != pm.end()) ans -= (long long)(it->second) * (it1->second);
      }
    }
  vis[rt] = 1;
  for (int i = Head[rt], to; i && (to = Lis[i].to, 1); i = Lis[i].nx)
    if (!vis[to]) dfs(to);
}
int main() {
  Rd(n), Rd(P);
  if (P == 1) {
    cout << (long long)n * (n - 1) << endl;
    return 0;
  }
  phi = P;
  int t = P;
  for (int i = 2; (long long)i * i <= phi; i++)
    if (t % i == 0) {
      phi = phi / i * (i - 1);
      while (t % i == 0) t /= i;
    }
  if (t > 1) phi = phi / t * (t - 1);
  phi--;
  for (int i = 1, x, y, z; i < n; i++)
    Rd(x), Rd(y), Rd(z), x++, y++, Add(x, y, z), Add(y, x, z);
  dfs(1);
  cout << ans << endl;
  return 0;
}
