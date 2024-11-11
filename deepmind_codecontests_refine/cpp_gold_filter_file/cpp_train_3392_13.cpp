#include <bits/stdc++.h>
using namespace std;
set<int> solve(vector<long long> a) {
  int n = a.size();
  vector<pair<int, int>> v;
  long long cur = 1;
  long long nxt = 2;
  v.push_back(make_pair(0, 0));
  for (int i = 0; i < n; i++) {
    long long x;
    x = a[i];
    while (1) {
      if (x == cur) {
        v.back().first++;
        break;
      }
      if (x < nxt) {
        v.back().second++;
        break;
      }
      v.push_back(make_pair(0, 0));
      cur *= 2;
      nxt *= 2;
    }
  }
  v.push_back(make_pair(0, 0));
  vector<int> b;
  while (1) {
    int x = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].first == 0) {
        x = i;
        break;
      }
      v[i].first--;
    }
    if (x == 0) break;
    b.push_back(x);
  }
  int last = 0;
  set<int> ans;
  for (int i = (int)v.size() - 1; i >= 0; i--) {
    while (v[i].first + v[i].second != 0) {
      if (last >= b.size()) {
        cout << -1;
        exit(0);
      }
      if (i >= b[last]) {
        cout << -1;
        exit(0);
      }
      if (v[i].first)
        v[i].first--;
      else
        v[i].second--;
      last++;
    }
  }
  ans.insert(b.size());
  while (1) {
    v[0].second += b.back();
    b.pop_back();
    for (int i = 0; i >= 0; i--) {
      while (v[i].first + v[i].second != 0) {
        if (last >= b.size()) {
          return ans;
        }
        if (v[i].first)
          v[i].first--;
        else
          v[i].second--;
        last++;
      }
    }
    ans.insert(b.size());
  }
  assert(false);
}
vector<long long> get_distribution(long long n) {
  long long cur = 1;
  vector<long long> res;
  while (n > 0) {
    if (n >= cur) {
      res.push_back(cur);
      n -= cur;
    } else {
      res.push_back(n);
      return res;
    }
    cur *= 2;
  }
  return res;
}
int test_dim;
vector<long long> gen_test() {
  vector<long long> a;
  test_dim = rand() + 1;
  int n = test_dim;
  for (int i = 0; i < n; i++) {
    long long x = (rand() << 32) + (rand() << 16) + rand();
    auto distr = get_distribution(x);
    a.insert(a.end(), distr.begin(), distr.end());
  }
  sort(a.begin(), a.end());
  return a;
}
int main() {
  srand(time_t(NULL));
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  auto ans = solve(a);
  for (auto el : ans) cout << el << " ";
  return 0;
}
