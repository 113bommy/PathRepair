#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
long long a[N], t[N], x[N], y[N], s[N];
int id[N], used[N], c[N];
vector<int> V[400];
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  long long ans = 0, cur = 0;
  for (int i = 0; i < n; i++) cin >> a[i], cur += (i + 1) * a[i];
  ans = cur;
  for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
  auto cross = [&](int u, int v, int w) {
    return (x[v] - x[u]) * (y[w] - y[u]) - (x[w] - x[u]) * (y[v] - y[u]);
  };
  auto convex_hull = [&](vector<int> &a) {
    vector<int> b;
    for (int i : a) {
      while (b.size() > 1 && cross(b[b.size() - 2], b.back(), i) <= 0)
        b.pop_back();
      b.push_back(i);
    }
    a = b;
  };
  int m = 500;
  auto build = [&](int from, int to, int flag = 1) {
    int j = from / m;
    V[j].clear();
    int cnt = 0;
    long long tot = 0;
    for (int i = from; i < to; i++)
      if (!used[i]) tot += a[i];
    long long sum = 0;
    if (!flag) {
      for (int i = from; i < to; i++) id[i] = i;
      sort(id + from, id + to, [](int i, int j) { return a[i] > a[j]; });
    }
    for (int i = from; i < to; i++) {
      if (used[i])
        cnt++;
      else {
        sum += a[i];
        y[i] = (i + 1 - cnt) * 1LL * a[i] + tot - sum;
        x[i] = -a[i];
      }
    }
    vector<int> v;
    for (int i = from; i < to; i++) {
      int k = id[i];
      if (used[k]) continue;
      v.push_back(k);
    }
    for (int i = 0, k; i < v.size(); i = k) {
      auto cur = make_pair(y[v[i]], v[i]);
      for (k = i; k < v.size() && x[v[i]] == x[v[k]]; k++) {
        if (y[v[k]] < cur.first) {
          cur.first = y[v[k]];
          cur.second = v[k];
        }
      }
      V[j].push_back(cur.second);
    }
    convex_hull(V[j]);
    c[j] = cnt, t[j] = tot;
  };
  auto calc = [&](int u, long long p) {
    assert(abs(y[u]) <= 1.5e12);
    assert(abs(x[u]) <= 1.5e7);
    return p * x[u] + y[u];
  };
  for (int i = 0; i < n; i += m) build(i, min(n, i + m), 0);
  auto get = [&](int id, long long x) {
    auto ret = make_pair(LONG_LONG_MAX, -1);
    if (V[id].empty()) return ret;
    int st = 0, en = V[id].size() - 1;
    while (en - st > 2) {
      int mid1 = (st * 2 + en) / 3;
      int mid2 = (st + en * 2) / 3;
      long long ret1 = calc(V[id][mid1], x);
      long long ret2 = calc(V[id][mid2], x);
      if (ret1 < ret2) {
        en = mid2;
      } else {
        st = mid1;
      }
    }
    assert(st <= en);
    for (int i = st; i <= en; i++) {
      int u = V[id][i];
      long long cur = calc(u, x);
      if (cur < ret.first) {
        ret.first = cur;
        ret.second = u;
      }
    }
    return ret;
  };
  cur = s[n];
  long long cost = ans;
  for (int i = n - 1; i > 0; i--) {
    long long tsum = 0, csum = 0;
    long long dmin = LONG_LONG_MAX;
    int u = -1;
    int flag = 0;
    for (int j = 0; j < (n - 1) / m + 1; j++) {
      tsum += t[j];
      if (V[j].empty()) {
        csum += c[j];
        continue;
      }
      flag = 1;
      auto sol = get(j, csum);
      if (dmin > cur - tsum + sol.first) {
        dmin = cur - tsum + sol.first;
        u = sol.second;
      }
      csum += c[j];
    }
    assert(flag);
    cur -= a[u];
    cost -= dmin;
    used[u] = 1;
    build(u / m * m, min((u / m + 1) * m, n));
    ans = max(ans, cost);
  }
  ans = max(ans, 0LL);
  cout << ans << endl;
  return 0;
}
