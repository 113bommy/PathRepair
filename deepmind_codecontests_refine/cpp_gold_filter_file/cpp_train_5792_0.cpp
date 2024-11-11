#include <bits/stdc++.h>
using namespace std;
long long di[] = {0, 1, 0, -1};
long long dj[] = {1, 0, -1, 0};
long long fine(long long i, long long j, long long n, long long m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
  for (T element : a) {
    os << element << " ";
  }
  return os;
}
template <class T>
istream &operator>>(istream &in, vector<T> &a) {
  for (T &t : a) {
    in >> t;
  }
  return in;
}
struct wave {
  long long l, r, a;
};
long long get_sum(vector<long long> &pref, long long pos) {
  if (pos < 0) {
    return 0;
  }
  return pref[pos];
}
struct Building {
  long long demolish;
  long long renovation;
  long long last_day;
  Building() {
    demolish = 0;
    last_day = -1;
    renovation = 0;
  }
  Building(long long renovation, long long demolish) {
    this->renovation = renovation;
    this->demolish = demolish;
  }
  bool operator<(const Building &other) const {
    return tie(demolish, renovation, last_day) <
           tie(other.demolish, other.renovation, other.last_day);
  }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<Building> build(m);
  for (auto &building : build) {
    cin >> building.renovation;
  }
  for (auto &building : build) {
    cin >> building.demolish;
  }
  map<long long, long long> temp_days;
  for (long long i = 0; i < n; i++) {
    temp_days[a[i]] = i;
  }
  map<long long, long long> last_days;
  vector<pair<pair<long long, long long>, long long>> suff_vec;
  for (auto t : temp_days) {
    suff_vec.emplace_back(t, t.second);
  }
  suff_vec.push_back({{(long long)(1e10), -1}, -1});
  for (long long i = suff_vec.size() - 2; i >= 0; i--) {
    suff_vec[i].second = max(suff_vec[i].second, suff_vec[i + 1].second);
    last_days[suff_vec[i].first.first] = suff_vec[i].second;
  }
  for (long long i = 0; i < m; i++) {
    auto p = last_days.lower_bound({build[i].renovation});
    if (p == last_days.end()) {
      build[i].last_day = -1;
    } else {
      build[i].last_day = p->second;
    }
  }
  sort(build.begin(), build.end());
  vector<pair<long long, long long>> demolish_order;
  for (long long i = 0; i < m; i++) {
    demolish_order.emplace_back(build[i].last_day, build[i].demolish);
  }
  sort(demolish_order.begin(), demolish_order.end());
  multiset<long long> demolish_list;
  long long bank = 0;
  long long used = 0;
  long long cur_day = 0;
  for (auto [day, cost] : demolish_order) {
    if (day == -1) continue;
    while (cur_day <= day) {
      bank += a[cur_day];
      cur_day++;
    }
    if (cost <= bank) {
      demolish_list.insert(-cost);
      bank -= cost;
    } else {
      if (!demolish_list.empty()) {
        auto p = demolish_list.begin();
        if (-*p > cost) {
          bank += -*p;
          bank -= cost;
          demolish_list.erase(p);
          demolish_list.insert(-cost);
        }
      }
    }
  }
  cout << demolish_list.size();
}
