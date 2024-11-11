#include <bits/stdc++.h>
using namespace std;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) { return n | (1LL << i); }
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline double dist(double ix, double iy, double jx, double jy) {
  return sqrt(((ix - jx) * (ix - jx)) + ((iy - jy) * (iy - jy)));
}
int marked[1000000 / 64 + 2];
bool isPrime(int x) {
  return (x > 1) &&
         ((x == 2) ||
          ((x & 1) && (!((marked[x >> 6] & (1 << ((x & 63) >> 1)))))));
}
void seive(int n) {
  int i, j;
  for (i = 3; i * i <= n; i += 2) {
    if (!(marked[i >> 6] & (1 << ((i & 63) >> 1)))) {
      for (j = i * i; j <= n; j += i << 1) {
        marked[j >> 6] |= (1 << ((j & 63) >> 1));
      }
    }
  }
}
long long bigMod(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) (r *= a) %= 1000000007;
    b >>= 1;
    (a *= a) %= 1000000007;
  }
  return r;
}
long long add(long long a, long long b) {
  long long ret = a + b;
  if (ret >= 1000000007) ret -= 1000000007;
  return ret;
}
long long sub(long long a, long long b) {
  long long ret = a - b;
  if (ret < 0) ret += 1000000007;
  return ret;
}
int bigChild[100007], so_far, now, col[100007], cnt[100007], n;
bool big[100007];
long long ans[100007];
vector<int> edge[100007];
int tree[100007];
vector<pair<int, int> > q[100007];
void update(int idx, int val) {
  while (idx <= n + 1) {
    ;
    tree[idx] += val;
    idx += (idx & -idx);
  }
}
int query(int idx) {
  int sum = 0;
  while (idx) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
int fsz(int i, int pre) {
  int ret = 1, mx = 0;
  for (auto it : edge[i]) {
    if (it == pre) continue;
    int p = fsz(it, i);
    if (mx < p) {
      mx = p;
      bigChild[i] = it;
    }
    ret += p;
  }
  return ret;
}
void add(int i, int pre, int x) {
  ;
  update(cnt[col[i]] + 1, -1);
  ;
  cnt[col[i]] += x;
  update(cnt[col[i]] + 1, +1);
  for (auto it : edge[i])
    if (it != pre && !big[it]) add(it, i, x);
}
void dfs(int i, int pre, bool keep) {
  for (auto it : edge[i])
    if (it != pre && it != bigChild[i]) dfs(it, i, 0);
  if (bigChild[i]) dfs(bigChild[i], i, 1), big[bigChild[i]] = 1;
  add(i, pre, 1);
  for (auto it : q[i]) {
    ans[it.second] = query(100001 + 1) - query(it.first);
  }
  if (bigChild[i]) big[bigChild[i]] = 0;
  if (keep == 0) {
    add(i, pre, -1);
  }
}
int main() {
  int i, u, v, m;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &col[i]);
  for (i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    q[u].push_back({v, i});
  }
  update(1, n);
  ;
  fsz(1, -1);
  ;
  dfs(1, -1, 0);
  ;
  for (i = 0; i < m; i++) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
