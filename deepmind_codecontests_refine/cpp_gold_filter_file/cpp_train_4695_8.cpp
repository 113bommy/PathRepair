#include <bits/stdc++.h>
using namespace std;
void doRoutine() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const long long INF = 2000000000000000000;
pair<long long, long long> foot;
pair<long long, long long> vec(pair<long long, long long> a,
                               pair<long long, long long> b) {
  return {b.first - a.first, b.second - a.second};
}
long long cp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first * b.second - a.second * b.first;
}
long long sc(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first * b.first + a.second * b.second;
}
long long len2(pair<long long, long long> v) {
  return v.first * v.first + v.second * v.second;
}
bool cmp_foot(pair<long long, long long> a, pair<long long, long long> b) {
  pair<long long, long long> v1 = vec(foot, a), v2 = vec(foot, b);
  long long r = cp(v1, v2);
  if (r != 0) {
    return r > 0;
  } else {
    return len2(v1) < len2(v2);
  }
}
bool bad(pair<long long, long long> a, pair<long long, long long> b,
         pair<long long, long long> c) {
  pair<long long, long long> v1 = vec(a, b), v2 = vec(a, c);
  return cp(v2, v1) >= 0;
}
vector<pair<long long, long long> > hull(
    vector<pair<long long, long long> > &a) {
  long long n = a.size();
  sort(a.begin(), a.end());
  foot = a[0];
  sort(a.begin() + 1, a.end(), cmp_foot);
  vector<pair<long long, long long> > res;
  for (long long i = 0; i < n; ++i) {
    while (res.size() > 1 && bad(res[res.size() - 2], res.back(), a[i])) {
      res.pop_back();
    }
    res.push_back(a[i]);
  }
  return res;
}
vector<long long> get_seq(vector<pair<long long, long long> > &a) {
  vector<long long> res;
  long long n = a.size();
  for (long long i = 0; i < n; ++i) {
    auto v1 = vec(a[i], a[(i + 1) % n]);
    auto v2 = vec(a[i], a[(i - 1 + n) % n]);
    res.push_back(sc(v1, v2));
    res.push_back(len2(vec(a[i], a[(i + 1) % n])));
  }
  return res;
}
vector<long long> pfunc(vector<long long> &a) {
  long long n = a.size();
  vector<long long> res(n + 1);
  res[0] = -1;
  res[1] = 0;
  for (long long i = 1; i < n; ++i) {
    long long x = res[i];
    while (x >= 0 && a[x] != a[i]) {
      x = res[x];
    }
    res[i + 1] = x + 1;
  }
  return res;
}
bool find(vector<long long> &a, vector<long long> &b) {
  vector<long long> s = b;
  s.push_back(INF);
  for (auto el : a) {
    s.push_back(el);
  }
  auto p = pfunc(s);
  for (auto el : p) {
    if (el == b.size()) {
      return true;
    }
  }
  return false;
}
signed main() {
  doRoutine();
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > a(n), b(m);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  for (long long i = 0; i < m; ++i) {
    cin >> b[i].first >> b[i].second;
  }
  auto ha = hull(a);
  auto hb = hull(b);
  if (ha.size() != hb.size()) {
    cout << "NO" << endl;
    return 0;
  }
  auto s = get_seq(ha), t = get_seq(hb);
  long long tmp = t.size();
  for (long long i = 0; i < tmp; ++i) {
    t.push_back(t[i]);
  }
  if (find(t, s)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
