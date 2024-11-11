#include <bits/stdc++.h>
using namespace std;
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) is >> x;
  return is;
}
ostream& operator<<(ostream& os, const pair<int, int>& unit) {
  return os << "y = " << unit.first << "x + " << unit.second;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
  }
  return os;
}
const int P = 1000000007;
int norm(int x) { return x >= P ? x - P : x; }
void add(int& x, int y) {
  if ((x += y) >= P) x -= P;
}
pair<long long, long long> operator+(const pair<long long, long long>& lhs,
                                     const pair<long long, long long>& rhs) {
  return pair<long long, long long>(lhs.first + rhs.first,
                                    lhs.second + rhs.second);
}
pair<long long, long long> operator-(const pair<long long, long long>& lhs) {
  return pair<long long, long long>(-lhs.first, -lhs.second);
}
pair<long long, long long> operator-(const pair<long long, long long>& lhs,
                                     const pair<long long, long long>& rhs) {
  return lhs + (-rhs);
}
long long operator^(const pair<long long, long long>& lhs,
                    const pair<long long, long long>& rhs) {
  return lhs.first * rhs.first + lhs.second * rhs.second;
}
long long operator*(const pair<long long, long long>& lhs,
                    const pair<long long, long long>& rhs) {
  return lhs.first * rhs.second - lhs.second * rhs.first;
}
long long dfrac(long long x, long long y) {
  if (x < 0) return (x - y + 1) / y;
  return x / y;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> u(m), v(m), w(m);
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i];
    --v[i];
  }
  vector<int> dp(n, numeric_limits<int>::min());
  dp[0] = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    add(ans, *max_element(dp.begin(), dp.end()));
    vector<int> ndp(n, numeric_limits<int>::min());
    for (int j = 0; j < m; ++j) {
      ndp[u[j]] = max(ndp[u[j]], dp[v[j]] + w[j]);
      ndp[v[j]] = max(ndp[v[j]], dp[u[j]] + w[j]);
    }
    swap(dp, ndp);
  }
  vector<pair<long long, long long> > pts;
  for (int i = 0; i < m; ++i) {
    int val = max(dp[u[i]], dp[v[i]]);
    pts.emplace_back(w[i], val - w[i] * n);
  }
  sort(pts.begin(), pts.end());
  vector<pair<long long, long long> > stk;
  for (const auto& pt : pts) {
    if (!stk.empty() && stk.back().first == pt.first) stk.pop_back();
    while (stk.size() > 1 && ((stk[stk.size() - 1] - stk[stk.size() - 2]) *
                              (pt - stk[stk.size() - 1])) >= 0) {
      stk.pop_back();
    }
    stk.push_back(pt);
  }
  auto contrib = [&](long long l, long long r,
                     const pair<long long, long long>& lne) {
    l = max(l, (long long)n);
    r = min(r, (long long)q);
    if (l <= r)
      ans = (ans + (r - l + 1) * lne.second % P +
             (l + r) * (r - l + 1LL) / 2 % P * lne.first) %
            P;
    if (ans < 0) ans += P;
  };
  long long cur = numeric_limits<long long>::min();
  for (int i = 0; i + 1 < stk.size(); ++i) {
    long long nxt = dfrac(stk[i].second - stk[i + 1].second,
                          stk[i + 1].first - stk[i].first);
    contrib(cur + 1, nxt, stk[i]);
    cur = nxt;
  }
  contrib(cur + 1, numeric_limits<long long>::max(), stk.back());
  cout << ans << '\n';
  return 0;
}
