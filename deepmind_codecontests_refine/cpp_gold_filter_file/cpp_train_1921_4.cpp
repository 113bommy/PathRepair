#include <bits/stdc++.h>
using namespace std;
void build(long long v, long long tl, long long tr, long long st[],
           long long lz[], bool f[], long long a[]) {
  if (tl == tr) {
    st[v] = a[tl];
    lz[v] = 0LL;
    f[v] = false;
    return;
  }
  build((v << 1), tl, ((tl + tr) >> 1), st, lz, f, a);
  build((v << 1) | 1, ((tl + tr) >> 1) + 1, tr, st, lz, f, a);
  st[v] = st[(v << 1)] + st[(v << 1) | 1];
  lz[v] = 0LL;
  f[v] = false;
  return;
}
void push(long long v, long long tl, long long tr, long long st[],
          long long lz[], bool f[]) {
  if (f[v]) {
    st[(v << 1)] = lz[(v << 1)] = st[(v << 1) | 1] = lz[(v << 1) | 1] = 0LL;
    f[(v << 1)] = f[(v << 1) | 1] = true;
    f[v] = false;
  }
  st[(v << 1)] += lz[v] * (((tl + tr) >> 1) - tl + 1);
  lz[(v << 1)] += lz[v];
  st[(v << 1) | 1] += lz[v] * (tr - ((tl + tr) >> 1));
  lz[(v << 1) | 1] += lz[v];
  lz[v] = 0LL;
  return;
}
void update(long long v, long long tl, long long tr, long long l, long long r,
            long long val, bool set, long long st[], long long lz[], bool f[]) {
  if (l > r) {
    return;
  }
  if (l == tl && tr == r) {
    if (set) {
      st[v] = lz[v] = 0LL;
      f[v] = true;
    }
    st[v] += val * (tr - tl + 1);
    lz[v] += val;
    return;
  }
  push(v, tl, tr, st, lz, f);
  update((v << 1), tl, ((tl + tr) >> 1), l, min(r, ((tl + tr) >> 1)), val, set,
         st, lz, f);
  update((v << 1) | 1, ((tl + tr) >> 1) + 1, tr, max(l, ((tl + tr) >> 1) + 1),
         r, val, set, st, lz, f);
  st[v] = st[(v << 1)] + st[(v << 1) | 1];
  return;
}
long long query(long long v, long long tl, long long tr, long long l,
                long long r, long long st[], long long lz[], bool f[]) {
  if (l > r) {
    return 0LL;
  }
  if (l == tl && tr == r) {
    return st[v];
  }
  push(v, tl, tr, st, lz, f);
  return query((v << 1), tl, ((tl + tr) >> 1), l, min(r, ((tl + tr) >> 1)), st,
               lz, f) +
         query((v << 1) | 1, ((tl + tr) >> 1) + 1, tr,
               max(l, ((tl + tr) >> 1) + 1), r, st, lz, f);
}
void build(int v, int tl, int tr, int a[], long long st[]) {
  if (tl == tr) {
    st[v] = a[tl];
    return;
  }
  int tm = ((tl + tr) / 2);
  build(2 * v, tl, tm, a, st);
  build(2 * v + 1, tm + 1, tr, a, st);
  st[v] = st[v * 2] + st[v * 2 + 1];
  return;
}
void update(int v, int tl, int tr, int pos, int val, long long st[]) {
  if (tl == tr && tl == pos) {
    st[v] = val;
    return;
  }
  if (tl > pos || tr < pos) {
    return;
  }
  int tm = ((tl + tr) / 2);
  update(2 * v, tl, tm, pos, val, st);
  update(2 * v + 1, tm + 1, tr, pos, val, st);
  st[v] = st[v * 2] + st[v * 2 + 1];
  return;
}
long long query(int v, int tl, int tr, int l, int r, long long st[]) {
  if (tl == l && tr == r) {
    return st[v];
  }
  if (l > r) {
    return 0LL;
  }
  int tm = ((tl + tr) / 2);
  return query(v * 2, tl, tm, l, std::min(tm, r), st) +
         query(v * 2 + 1, tm + 1, tr, std::max(tm + 1, l), r, st);
}
long long fn(long long x, long long rn[]) {
  if (x == rn[x])
    return x;
  else
    return rn[x] = fn(rn[x], rn);
}
bool un(long long x, long long y, long long rn[], long long sz[]) {
  x = fn(x, rn);
  y = fn(y, rn);
  if (x == y) return false;
  if (sz[x] < sz[y]) swap(x, y);
  sz[x] += sz[y];
  rn[y] = x;
  return true;
}
long long power(long long k) {
  long long temp = 1;
  for (long long i = 0; i <= k - 1; i++) {
    temp = temp * 2;
  }
  return temp;
}
bool compare(const pair<long long, long long> &a,
             const pair<long long, long long> &b) {
  return a.second < b.second;
}
pair<int, int> mostFrequent(long long arr[], long long n) {
  unordered_map<long long, long long> hash;
  for (long long i = 0; i < n; i++) hash[arr[i]]++;
  long long max_count = 0, res = -1;
  for (auto i : hash) {
    if (max_count < i.second) {
      res = i.first;
      max_count = i.second;
    }
  }
  pair<long long, long long> temp;
  temp.first = res;
  temp.second = max_count;
  return temp;
}
long long div(long long n) {
  if (n % 2 == 0) return 2;
  for (long long i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return i;
  }
  return n;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool sec(const pair<long long, long long> &a,
         const pair<long long, long long> &b) {
  return (a.first > b.first);
}
bool sec1(const pair<long long, long long> &a,
          const pair<long long, long long> &b) {
  return (a.second < b.second);
}
vector<long long> v[26];
vector<bool> vis(26, 0);
set<char> st[26];
long long vert = 0;
long long ed = 0;
void dfs(long long t) {
  vis[t] = 1;
  ed = ed + v[t].size();
  for (auto u : v[t]) {
    if (vis[u] == 0) {
      dfs(u);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long rnk[51];
  long long sz[51];
  for (long long i = 0; i <= 50; i++) {
    rnk[i] = i;
    sz[i] = 1;
  }
  for (long long i = 0; i <= m - 1; i++) {
    long long u, v;
    cin >> u >> v;
    un(u, v, rnk, sz);
  }
  set<long long> uset;
  vector<long long> vec;
  for (long long i = 1; i <= n; i++) {
    if (uset.find(fn(i, rnk)) == uset.end()) {
      uset.insert(fn(i, rnk));
      vec.push_back(sz[fn(i, rnk)]);
    }
  }
  sort(vec.begin(), vec.end(), greater<int>());
  long long sum = 1;
  for (long long i = 0; i <= (long long)vec.size() - 1; i++) {
    long long temp = power(vec[i] - 1);
    sum = sum * temp;
  }
  cout << sum;
  return 0;
}
