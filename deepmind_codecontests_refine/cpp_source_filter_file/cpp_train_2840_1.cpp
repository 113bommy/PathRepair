#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, long long> num;
vector<long long> v;
vector<pair<long long, pair<long long, long long> > > res;
void go2(long long x, long long k) {
  for (long long i = 0; i < 21; ++i) {
    res.push_back({0, {(1 << i) * x, (1 << i) * x}});
  }
  vector<long long> v;
  for (long long i = 0; i < 21; ++i) {
    if ((1 << i) & k) {
      v.push_back(i);
    }
  }
  long long curr = 0;
  for (long long i = 0; i < v.size(); ++i) {
    res.push_back({0, {curr, (1 << v[i]) * x}});
    curr += ((1 << v[i]) * x);
  }
}
void go1(long long x) {
  for (long long k = 0; k < (1 << 20); ++k) {
    if (((x * k) % (1 << 20)) == 1) {
      go2(x, k);
      go2(x, k + 1);
      res.push_back({1, {x * k, x * (k + 1)}});
      break;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long x;
  cin >> x;
  res.push_back({1, {x, x}});
  go1(x);
  go1(x + 2);
  if (x ^ (x + 2) == 2) {
    res.push_back({1, {x, x + 2}});
  } else {
    res.push_back({1, {x + 2, x + 4}});
  }
  go2(2, (x - 1) / 2);
  res.push_back({1, {x - 1, x}});
  cout << res.size() << endl;
  for (auto h : res) {
    if (h.first == 0) {
      cout << h.second.first << ' ' << "+" << ' ' << h.second.second << endl;
    } else {
      cout << h.second.first << ' ' << "^" << ' ' << h.second.second << endl;
    }
  }
  return 0;
}
