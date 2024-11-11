#include <bits/stdc++.h>
using namespace std;
void setIO(const string& name = "") {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  if (name.length()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
long long n, q;
vector<long long> a, diff;
vector<long long> s, e;
long long solve(vector<long long>& x) {
  if (true) {
    s.resize((long long)(x).size());
    stack<long long> ss;
    s[0] = -1;
    ss.push(0);
    for (auto(i) = 1; (i) < ((long long)(x).size()); (i)++) {
      while (!ss.empty() and x[ss.top()] <= x[i]) {
        ss.pop();
      }
      if (ss.empty()) {
        s[i] = -1;
      } else {
        s[i] = ss.top();
      }
      ss.push(i);
    }
    for (auto&(c) : (s)) {
      c++;
    }
  }
  if (true) {
    reverse(x.begin(), x.end());
    e.resize((long long)(x).size());
    stack<long long> ee;
    e[0] = -1;
    ee.push(0);
    for (auto(i) = 1; (i) < ((long long)(x).size()); (i)++) {
      while (!ee.empty() and x[ee.top()] < x[i]) {
        ee.pop();
      }
      if (ee.empty()) {
        e[i] = -1;
      } else {
        e[i] = ee.top();
      }
      ee.push(i);
    }
    reverse(e.begin(), e.end());
    for (auto&(c) : (e)) {
      c = (long long)(x).size() - 2 - c;
    }
    reverse(x.begin(), x.end());
  }
  long long ans = 0;
  for (auto(i) = 0; (i) < ((long long)(x).size()); (i)++) {
    ans += (e[i] - i + 1) * (i - s[i] + 1) * x[i];
  }
  return ans;
}
signed main() {
  setIO();
  if (true) {
    cin >> n >> q;
    a.resize(n);
    for (auto&(c) : (a)) {
      cin >> c;
    }
    if (n == 2) {
      long long l, r;
      while (q--) {
        cin >> l >> r;
        l--, r--;
        assert(l == 0 and r == 1);
        cout << abs(a.back() - a.front()) << '\n';
      }
      return 0;
    }
    diff.resize(n - 1);
    for (auto(i) = 1; (i) < (n); (i)++) {
      diff[i - 1] = abs(a[i] - a[i - 1]);
    }
  };
  if (true) {
    long long l, r;
    while (q--) {
      cin >> l >> r;
      --l, --r;
      vector<long long> cur;
      for (auto(i) = l; (i) < (r); (i)++) {
        cur.emplace_back(diff[i]);
      }
      cout << solve(cur) << '\n';
    }
  };
  return 0;
}
