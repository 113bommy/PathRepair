#include <bits/stdc++.h>
using namespace std;
long long n, c0, c1;
map<pair<long long, long long>, long long> m;
set<pair<long long, long long> > u;
void add(long long x, long long y,
         priority_queue<pair<long long, pair<long long, long long> > > &q) {
  if (u.find(make_pair(x, y)) != u.end()) return;
  u.insert(make_pair(x, y));
  q.push(make_pair(-(x * c0 + y * c1), make_pair(x, y)));
}
long long mod = 1e10;
vector<long long> create(long long x) {
  vector<long long> res;
  if (x == 0) {
    res.push_back(0);
    return res;
  }
  while (x) {
    res.push_back(x % mod);
    x /= mod;
  }
  return res;
}
vector<long long> mul(vector<long long> v, long long x) {
  vector<long long> res;
  long long ost = 0;
  for (long long i = 0; i < (long long)(v.size()); i++) {
    res.push_back(v[i] * x);
    res[i] += ost;
    ost = res[i] / mod;
    res[i] %= mod;
  }
  if (ost) res.push_back(ost);
  return res;
}
vector<long long> sum(vector<long long> a, vector<long long> b) {
  vector<long long> res;
  long long n = max(a.size(), b.size());
  long long ost = 0;
  for (long long i = 0; i < (long long)(n); i++) {
    res.push_back(ost);
    if (i < a.size()) res[i] += a[i];
    if (i < b.size()) res[i] += b[i];
    ost = res[i] / mod;
    res[i] %= mod;
  }
  if (ost) res.push_back(ost);
  return res;
}
vector<long long> sub(vector<long long> a, vector<long long> b) {
  vector<long long> res = a;
  for (long long i = 0; i < (long long)(b.size()); i++) {
    res[i] -= b[i];
    if (res[i] < 0) {
      res[i] += mod;
      if (i + 1 < res.size())
        res[i + 1]--;
      else
        return mul(create(1e18), 1e8);
    }
  }
  return res;
}
bool check(vector<long long> a, vector<long long> b) {
  while (a.size() < b.size()) a.push_back(0);
  while (a.size() > b.size()) b.push_back(0);
  for (long long i = a.size() - 1; i >= 0; i--) {
    if (a[i] == b[i]) continue;
    if (a[i] > b[i])
      return true;
    else
      return false;
  }
}
void write(vector<long long> ans) {
  bool ok = false;
  for (long long ii = 0; ii < (long long)(ans.size()); ii++) {
    long long i = ans.size() - 1 - ii;
    if (!ok && ans[i] == 0) continue;
    if (ok) {
      long long m = mod / 10;
      while (m) {
        long long x = ans[i] / m;
        cout << x;
        ans[i] -= x * m;
        m /= 10;
      }
    } else
      cout << ans[i];
    ok = true;
  }
  if (!ok) cout << 0;
  cout << '\n';
}
int main(void) {
  cin >> n >> c0 >> c1;
  if (c0 > c1) swap(c0, c1);
  vector<long long> ans =
      sum(create((n - 1) * c1), mul(create(n * (n - 1) / 2), c0));
  priority_queue<pair<long long, pair<long long, long long> > > q;
  add(0, 1, q);
  m[make_pair(0, 1)] = 1;
  n--;
  while (n > 0) {
    vector<long long> res = ans;
    long long s = -q.top().first;
    pair<long long, long long> p = q.top().second;
    q.pop();
    m[make_pair(p.first + 1, p.second)] += m[p];
    m[make_pair(p.first, p.second + 1)] += m[p];
    if (p.second == 1) m[make_pair(p.first + 1, p.second)]++;
    add(p.first + 1, p.second, q);
    add(p.first, p.second + 1, q);
    long long k = m[p];
    long long r = n;
    long long l = n - k + 1;
    if (l < 0) {
      k += l;
      l = 0;
    }
    while (l <= r && c0 + s > l * c0) {
      l++;
      k--;
    }
    if (l > r) break;
    res = sum(res, create(k * (c0 + s)));
    res = sub(res, mul(create((l + r) * (r - l + 1) / 2), c0));
    n = l - 1;
    if (check(res, ans)) break;
    ans = res;
  }
  write(ans);
  return 0;
}
