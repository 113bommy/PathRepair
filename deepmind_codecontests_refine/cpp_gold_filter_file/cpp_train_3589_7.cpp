#include <bits/stdc++.h>
using namespace std;
template <typename TYPE>
inline void chkmax(TYPE &first, TYPE second) {
  first < second ? first = second : 0;
}
template <typename TYPE>
inline void chkmin(TYPE &first, TYPE second) {
  second < first ? first = second : 0;
}
template <typename TYPE>
void readint(TYPE &first) {
  first = 0;
  int f = 1;
  char c;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) first = first * 10 + c - '0';
  first *= f;
}
const int MAXN = 800005;
const long long INF = 1ll << 60;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void exgcd(int a, int b, int &first, int &second) {
  if (!b) {
    first = 1, second = 0;
    return;
  }
  exgcd(b, a % b, first, second);
  int t = first;
  first = second;
  second = t - (a / b) * second;
}
int n, m, stot, invn, invm;
vector<int> a[MAXN], b[MAXN], ta, tb;
map<int, int> ma, mb;
long long dis[MAXN];
bool hap[MAXN];
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    pq;
struct Edge {
  int v;
  long long c;
  Edge *next;
} pool[MAXN * 3], *h[MAXN];
int etot = 0;
inline void addEdge(int u, int v, long long c) {
  Edge *p = &pool[++etot];
  p->v = v;
  p->c = c;
  p->next = h[u];
  h[u] = p;
}
void read(int d, vector<int> *a) {
  int n, first;
  readint(n);
  while (n--) {
    readint(first);
    a[first % d].push_back(first / d);
  }
}
int gma(int first) { return ma.count(first) ? ma[first] : ma[first] = ++stot; }
int gmb(int first) { return mb.count(first) ? mb[first] : mb[first] = ++stot; }
void dijkstra(int src) {
  for (int i = 1; i <= stot; ++i) dis[i] = INF;
  dis[src] = 0;
  pq.push(make_pair(0, src));
  while (!pq.empty()) {
    pair<long long, int> pr = pq.top();
    pq.pop();
    int u = pr.second;
    if (pr.first > dis[u]) continue;
    for (Edge *p = h[u]; p; p = p->next)
      if (dis[p->v] > dis[u] + p->c) {
        dis[p->v] = dis[u] + p->c;
        pq.push(make_pair(dis[p->v], p->v));
      }
  }
}
long long solve(vector<int> a, vector<int> b) {
  ma.clear();
  ta.clear();
  mb.clear();
  tb.clear();
  for (int i = 1; i <= stot; ++i) h[i] = NULL, hap[i] = 0;
  stot = etot = 0;
  int src = ++stot;
  for (int i = 0; i < a.size(); ++i) {
    int first = 1ll * a[i] * invm % n;
    addEdge(src, gma(first), a[i]);
    addEdge(gma(first), gmb(1ll * a[i] * invn % m), 0);
    hap[gma(first)] = 1;
    ta.push_back(first ? first - 1 : n - 1);
    tb.push_back(1ll * a[i] * invn % m);
    tb.push_back((1ll * a[i] * invn + m - 1) % m);
    a[i] = first;
  }
  for (int i = 0; i < b.size(); ++i) {
    int first = 1ll * b[i] * invn % m;
    addEdge(src, gmb(first), b[i]);
    addEdge(gmb(first), gma(1ll * b[i] * invm % n), 0);
    hap[gmb(first)] = 1;
    tb.push_back(first ? first - 1 : m - 1);
    ta.push_back(1ll * b[i] * invm % n);
    ta.push_back((1ll * b[i] * invm + n - 1) % n);
    b[i] = first;
  }
  for (auto first : ta) a.push_back(first);
  for (auto first : tb) b.push_back(first);
  sort(a.begin(), a.end());
  auto edu = unique(a.begin(), a.end());
  a.erase(edu, a.end());
  sort(b.begin(), b.end());
  edu = unique(b.begin(), b.end());
  b.erase(edu, b.end());
  for (int i = 1; i < a.size(); ++i)
    addEdge(gma(a[i - 1]), gma(a[i]), 1ll * (a[i] - a[i - 1]) * m);
  addEdge(gma(a.back()), gma(a[0]), 1ll * (a[0] - a.back() + n) * m);
  for (int i = 1; i < b.size(); ++i)
    addEdge(gmb(b[i - 1]), gmb(b[i]), 1ll * (b[i] - b[i - 1]) * n);
  addEdge(gmb(b.back()), gmb(b[0]), 1ll * (b[0] - b.back() + m) * n);
  dijkstra(src);
  long long ans = -1;
  for (int i = 2; i <= stot; ++i)
    if (!hap[i]) chkmax(ans, dis[i]);
  return ans;
}
int main() {
  readint(n), readint(m);
  int d = gcd(n, m);
  if (d > 200000) return 0 * printf("-1\n");
  read(d, a);
  read(d, b);
  for (int i = 0; i < d; ++i)
    if (!a[i].size() && !b[i].size()) return 0 * printf("-1\n");
  n /= d, m /= d;
  int temp;
  exgcd(n, m, invn, temp);
  if (invn < 0) invn += m;
  exgcd(n, m, temp, invm);
  if (invm < 0) invm += n;
  long long ans = 0;
  for (int i = 0; i < d; ++i) chkmax(ans, solve(a[i], b[i]) * d + i);
  printf("%lld\n", ans);
  return 0;
}
