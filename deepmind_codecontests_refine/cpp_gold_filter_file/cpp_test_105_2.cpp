#include <bits/stdc++.h>
namespace FastRead {
char __buff[5000];
long long __lg = 0, __p = 0;
char nc() {
  if (__lg == __p) {
    __lg = fread(__buff, 1, 5000, stdin);
    __p = 0;
    if (!__lg) return EOF;
  }
  return __buff[__p++];
}
template <class T>
void read(T& __x) {
  T __sgn = 1;
  char __c;
  while (!isdigit(__c = nc()))
    if (__c == '-') __sgn = -1;
  __x = __c - '0';
  while (isdigit(__c = nc())) __x = __x * 10 + __c - '0';
  __x *= __sgn;
}
}  // namespace FastRead
using namespace FastRead;
using namespace std;
const long long N = 2e5 + 10;
const long long M = 1e6 + 10;
const long double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long n;
long long d[N], fish[N];
struct dish {
  long long fish, meat, m;
} a[N];
struct segm {
  long long l, r, ind;
};
struct cmps {
  bool operator()(segm a, segm b) { return a.l < b.l; }
};
bool inline cmp(segm a, segm b) { return a.r < b.r; }
vector<segm> G[2 * M];
bool mark[N], vis[2 * M];
multiset<segm, cmps> s;
void init() {
  for (long long i = 1; i <= n; i++)
    G[d[i]].clear(), mark[i] = 0, vis[d[i]] = 0;
}
void Test() {
  long long i, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i].fish >> a[i].meat >> a[i].m;
    d[i] = a[i].fish + a[i].meat - a[i].m;
    long long L = d[i] - min(d[i], a[i].meat);
    long long R = min(d[i], a[i].fish);
    G[d[i]].push_back({L, R, i});
  }
  long long diversity = 0;
  for (long long t = 1; t <= n; t++) {
    i = d[t];
    if (vis[i]) continue;
    vis[i] = 1;
    sort(G[i].begin(), G[i].end(), cmp);
    s.clear();
    for (auto j : G[i]) s.insert(j);
    for (j = 0; j < G[i].size(); j++) {
      long long ind = G[i][j].ind;
      long long l = G[i][j].l;
      long long r = G[i][j].r;
      if (mark[ind]) continue;
      mark[ind] = 1;
      ++diversity;
      while (!s.empty() && s.begin()->l <= r) {
        mark[s.begin()->ind] = 1;
        fish[s.begin()->ind] = r;
        s.erase(s.begin());
      }
    }
  }
  cout << diversity << '\n';
  for (i = 1; i <= n; i++)
    cout << a[i].fish - fish[i] << ' ' << a[i].m - (a[i].fish - fish[i])
         << '\n';
  cout << '\n';
  init();
}
signed main() {
  long long q;
  cin >> q;
  while (q--) Test();
  return 0;
}
