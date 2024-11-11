#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void f123(const char* name, Arg1&& arg1) {
  if (0) return;
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void f123(const char* names, Arg1&& arg1, Args&&... args) {
  if (0) return;
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  f123(comma + 1, args...);
}
auto clk = clock();
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
long long rng(long long lim) {
  uniform_int_distribution<long long> uid(0, lim - 1);
  return uid(rang);
}
const long long N = 3e6 + 7, M = 1000000007, inf = INT_MAX;
const long long INF = LLONG_MAX;
vector<pair<long long, long long> > vec;
long long lb1(vector<pair<long long, long long> >& v, long long k) {
  pair<long long, long long> p = {k, -1};
  return (lower_bound(vec.begin(), vec.end(), p) - vec.begin());
  ;
}
long long lsr(vector<pair<long long, long long> >& v, long long k) {
  return lb1(v, k);
};
long long grt(vector<pair<long long, long long> >& v, long long k) {
  return (long long)v.size() - lb1(v, k + 1);
}
long long n, h, m, k;
long long ans, val;
void work(long long ti) {
  long long half = m / 2;
  if (ti >= half) ti -= half;
  long long s1, e1, x, y;
  if (ti >= k) {
    long long s1 = ti - k, e1 = ti;
    long long x = lb1(vec, e1);
    long long y = lb1(vec, s1 + 1);
    long long bw = x - y;
    s1 = ti + half - k, e1 = ti + half;
    x = lb1(vec, e1);
    y = lb1(vec, s1 + 1);
    bw += x - y;
    if (ans > bw) {
      ans = bw;
      val = ti;
    }
  } else {
    s1 = ti + half - k, e1 = ti + half;
    x = lb1(vec, e1);
    y = lb1(vec, s1 + 1);
    long long bw = x - y;
    bw += grt(vec, m - (k - ti)) + lsr(vec, ti);
    if (ans > bw) {
      ans = bw;
      val = ti;
    }
  }
}
void solve() {
  cin >> n >> h >> m >> k;
  for (long long i = 0; i < (long long)n; i++) {
    long long hi, mi;
    cin >> hi >> mi;
    vec.push_back({mi, i + 1});
  }
  sort(vec.begin(), vec.end());
  ans = n, val = 0;
  for (long long i = 0; i < (long long)n; i++) work(vec[i].first);
  long long half = m / 2;
  vector<long long> res;
  long long ti = val;
  for (long long i = 0; i < (long long)n; i++) {
    long long mi = vec[i].first, id = vec[i].second;
    if (ti >= k) {
      long long s1 = ti - k, e1 = ti;
      if (s1 < mi and mi < e1)
        res.push_back(id);
      else if (s1 + half < mi and mi + half < e1)
        res.push_back(id);
    } else {
      long long s1 = ti + half - k, e1 = ti + half;
      if (s1 < mi and mi < e1)
        res.push_back(id);
      else {
        if (mi > (m - (k - ti)))
          res.push_back(id);
        else if (mi < ti)
          res.push_back(id);
      }
    }
  }
  assert(val < (m / 2));
  cout << res.size() << " " << val << '\n';
  sort(res.begin(), res.end());
  for (auto& i : res) cout << i << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  while (test--) solve();
}
