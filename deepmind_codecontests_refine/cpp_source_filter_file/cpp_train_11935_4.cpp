#include <bits/stdc++.h>
using namespace std;
struct problem {
  long long a, t, ind;
};
bool operator<(problem a, problem b) {
  return a.a < b.a || (a.a == b.a && a.t < b.t) ||
         (a.a == b.a && a.t < b.t && a.ind < b.ind);
}
bool cmp(problem a, problem b) {
  return a.t < b.t || (a.t == b.t && a.a < b.a);
}
long long n, t;
set<problem> s;
bool f(long long k) {
  auto m = s.lower_bound({k, -1, -1});
  vector<problem> v;
  while (m != s.end()) {
    v.push_back(*m);
    ++m;
  }
  if (v.size() < k) {
    return false;
  }
  sort(v.begin(), v.end(), cmp);
  long long time = 0;
  for (int i = 0; i < v.size() && i < k; ++i) {
    time += v[i].t;
    if (time > t) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> n >> t;
  for (int i = 0; i < n; ++i) {
    problem p;
    cin >> p.a >> p.t;
    s.insert({p.a, p.t, i});
  }
  long long l = 0;
  long long r = n + 1;
  while (l + 1 < r) {
    long long k = (l + r) / 2;
    if (f(k)) {
      l = k;
    } else {
      r = k;
    }
  }
  auto m = s.lower_bound({l, -1, -1});
  vector<problem> v;
  while (m != s.end()) {
    v.push_back(*m);
    ++m;
  }
  sort(v.begin(), v.end(), cmp);
  vector<long long> ans;
  for (int i = 0; i < v.size() && i < l; ++i) {
    ans.push_back(v[i].ind);
  }
  cout << l << "\n" << ans.size() << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
}
