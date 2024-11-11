#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)(5e5) + 322;
const long long INF = (long long)(1e9) + 7;
const long long mod = (long long)(1e9) + 7;
const double eps = 1e-9;
template <typename T>
struct Fenwick {
  vector<T> tree;
  long long size;
  Fenwick(long long _size) {
    size = _size;
    tree = vector<T>(size + 1);
  }
  void add(long long i, T val) {
    for (; i < size; i += (i & -i)) {
      tree[i] += val;
    }
  }
  T get(long long i) {
    T res = 0;
    for (; i > 0; i -= (i & -i)) {
      res += tree[i];
    }
    return res;
  }
};
Fenwick<long long> cnt(N), sum(N);
set<pair<long long, long long>> s, S;
vector<long long> v[N];
long long n, X[N], t[N], p[N], l[N], T, res[N], idx[N], invid[N], a[N];
vector<pair<long long, pair<long long, long long>>> cur;
void add(long long x) {
  long long id = idx[x];
  sum.add(id, t[x] * X[x]);
  cnt.add(id, X[x]);
}
void del(long long x) {
  long long id = idx[x];
  sum.add(id, -1 * t[x] * X[x]);
  cnt.add(id, -1 * X[x]);
}
long long get(long long time) {
  long long l = 0, r = N / 2;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (sum.get(mid) > time) {
      r = mid;
    } else {
      l = mid;
    }
  }
  long long ans = cnt.get(l);
  if (sum.get(l) == time) return ans;
  long long id = invid[l + 1];
  if (t[id]) ans += (time - sum.get(l)) / t[id];
  return ans;
}
void dfs(long long x, long long par = 0, long long sum = 0) {
  sum += l[x] * 2;
  if (sum > T) return;
  add(x);
  res[x] = get(T - sum);
  for (auto it : v[x]) {
    if (it == par) continue;
    dfs(it, x, sum);
  }
  del(x);
}
long long getAns(long long x, long long par = 0) {
  long long ans = res[x];
  vector<long long> c;
  for (auto it : v[x]) {
    if (it == par) continue;
    c.push_back(getAns(it, x));
  }
  sort(c.begin(), c.end());
  reverse(c.begin(), c.end());
  if (x == 1) {
    if ((long long)(c.size()) >= 1) ans = max(ans, c[0]);
  } else {
    if ((long long)(c.size()) >= 2) ans = max(ans, c[1]);
  }
  return ans;
}
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> T;
  for (long long i = 1; i <= n; ++i) cin >> X[i];
  for (long long i = 1; i <= n; ++i) cin >> t[i];
  for (long long i = 1; i <= n; ++i) {
    cur.push_back(make_pair(t[i], make_pair(X[i], i)));
  }
  sort(cur.begin(), cur.end());
  for (long long i = 0; i <= n - 1; ++i) {
    idx[cur[i].second.second] = i + 1;
    invid[i + 1] = cur[i].second.second;
  }
  for (long long i = 2; i <= n; ++i) {
    cin >> p[i] >> l[i];
    v[i].push_back(p[i]);
    v[p[i]].push_back(i);
  }
  dfs(1);
  cout << getAns(2, 1);
  return 0;
}
