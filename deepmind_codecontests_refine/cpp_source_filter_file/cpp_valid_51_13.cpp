#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mo = 998244353;
const int inv2 = 499122177;
const double jzm = 0.9994;
const int zero = 5000;
const int orG = 3, invG = 332748118;
const double Pi = acos(-1.0);
const double eps = 1e-3;
template <typename _T>
_T Fabs(_T x) {
  return x < 0 ? -x : x;
}
template <typename _T>
void read(_T &x) {
  _T f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
template <typename _T>
void print(_T x) {
  if (x < 0) {
    x = (~x) + 1;
    putchar('-');
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
int add(int x, int y, int p) { return x + y < p ? x + y : x + y - p; }
void Add(int &x, int y, int p) { x = add(x, y, p); }
int qkpow(int a, int s, int p) {
  int t = 1;
  while (s) {
    if (s & 1LL) t = 1ll * a * t % p;
    a = 1ll * a * a % p;
    s >>= 1LL;
  }
  return t;
}
int n, k, d[55], mp[55][55], t[55], fa[55], tota, totb, deg[55], summ, ans,
    ord[55][55], sta[55], stak;
bool cho[55][55], tmp[55][55], ap[55][55], fg[55];
struct edge {
  int u, v, w;
} a[2505], b[2505];
bool cmp(edge x, edge y) { return x.w < y.w; }
bool cmp1(int x, int y) { return t[x] < t[y]; }
double Rand() {
  return 1.0 * (rand() * RAND_MAX + rand()) / (RAND_MAX * RAND_MAX);
}
void makeSet(int x) {
  for (int i = 1; i <= x; i++) fa[i] = i;
}
int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }
void unionSet(int a, int b) {
  int u = findSet(a), v = findSet(b);
  if (u != v) fa[u] = v;
}
void work(int x) {
  for (int i = 1; i <= n; i++) {
    if (ord[x][i] <= k && !fg[findSet(ord[x][i])]) continue;
    if (ord[x][i] <= k && deg[ord[x][i]] == d[ord[x][i]]) continue;
    unionSet(ord[x][i], x);
    tmp[min(ord[x][i], x)][max(ord[x][i], x)] = 1;
    deg[ord[x][i]]++;
    deg[x]++;
    break;
  }
}
void sakura(double tp) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) tmp[i][j] = 0;
  for (int i = 1; i <= n; i++) deg[i] = fg[i] = 0;
  summ = 0;
  makeSet(n);
  int tim = 0;
  for (int i = 1; i <= tota; i++) {
    int u = a[i].u, v = a[i].v, w = a[i].w;
    if (!cho[u][v]) continue;
    if (Rand() < tp) {
      tmp[u][v] = 0;
      continue;
    }
    tmp[u][v] = 1;
    deg[u]++;
    deg[v]++;
    unionSet(u, v);
    tim++;
  }
  random_shuffle(a + 1, a + tota + 1);
  for (int i = 1; i <= tota; i++) {
    int u = a[i].u, v = a[i].v, w = a[i].w;
    if (tmp[u][v] || findSet(u) == findSet(v)) continue;
    if (Rand() > tp || deg[u] == d[u] || deg[v] == d[v]) continue;
    tmp[u][v] = 1;
    deg[u]++;
    deg[v]++;
    unionSet(u, v);
    tim++;
  }
  for (int i = k + 1; i <= n; i++) fg[findSet(i)] = 1;
  tim = 0;
  for (int i = 1; i <= k; i++) {
    if (fg[findSet(i)]) continue;
    int p = findSet(i), spc = 0;
    for (int j = 1; j <= k; j++)
      if (findSet(j) == p && deg[j] < d[j]) spc = j;
    if (!spc) {
      stak = 0;
      for (int j = 1; j <= k; j++)
        if (findSet(j) == p) sta[++stak] = j;
      for (int j = 1; j <= stak; j++) {
        int u = sta[j];
        fa[u] = u;
        deg[u] = 0;
        for (int l = 1; l <= k; l++) tmp[l][u] = tmp[u][l] = 0;
      }
      for (int j = 1; j <= stak; j++) work(sta[j]), fg[findSet(sta[j])] = 1;
    } else
      work(spc), fg[findSet(spc)] = 1;
  }
  for (int i = 1; i <= totb; i++)
    if (findSet(b[i].u) != findSet(b[i].v))
      unionSet(b[i].u, b[i].v), deg[b[i].u]++, deg[b[i].v]++,
          tmp[b[i].u][b[i].v] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (tmp[i][j]) summ += mp[i][j], tim++;
}
void nagisa() {
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) cho[i][j] = ap[i][j];
  summ = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (cho[i][j]) summ += mp[i][j];
  for (int t = 1; t <= 500; t++) {
    int now = summ;
    sakura(0.5);
    if (summ < now)
      for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) cho[i][j] = tmp[i][j];
    else
      summ = now;
  }
  if (ans > summ) {
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) ap[i][j] = cho[i][j];
    ans = summ;
  }
  double nowT = 5000.0;
  while (nowT > eps) {
    int now = summ;
    sakura(nowT);
    double t = Rand();
    if (ans > summ) {
      for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) ap[i][j] = cho[i][j] = tmp[i][j];
      ans = summ;
    } else if (exp(1.0 * (now - summ) / nowT) > t)
      for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) cho[i][j] = tmp[i][j];
    else
      summ = now;
    nowT *= jzm;
  }
}
signed main() {
  srand(time(NULL));
  read(n);
  read(k);
  for (int i = 1; i <= k; i++) read(d[i]);
  for (int i = k + 1; i <= n; i++) d[i] = n;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      read(mp[i][j]), mp[j][i] = mp[i][j];
      if (i <= k)
        a[++tota] = (edge){i, j, mp[i][j]};
      else
        b[++totb] = (edge){i, j, mp[i][j]};
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) t[j] = mp[i][j];
    for (int j = 1; j <= n; j++) ord[i][j] = j;
    sort(ord[i] + 1, ord[i] + n + 1, cmp1);
  }
  sort(b + 1, b + totb + 1, cmp);
  sakura(1.0);
  ans = summ;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) ap[i][j] = cho[i][j] = tmp[i][j];
  for (int i = 1; i <= 5; i++) nagisa();
  printf("%d\n", ans);
  return 0;
}
