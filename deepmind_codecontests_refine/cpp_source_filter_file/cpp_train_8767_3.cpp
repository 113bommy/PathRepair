#include <bits/stdc++.h>
using namespace std;
template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const long long mod = 998244353;
void solve() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> m(n);
  for (int i = 0; i < int(n); i++) cin >> m[i];
  vector<long long> dp(n);
  vector<long long> dq(n);
  long long sum = 0;
  stack<pair<long long, long long>> s;
  for (int i = 0; i < int(n); i++) {
    long long cur = 1;
    while (!s.empty() && s.top().first >= m[i]) {
      sum -= s.top().first * s.top().second;
      cur += s.top().second;
      s.pop();
    }
    sum += m[i] * cur;
    s.push({m[i], cur});
    dp[i] = sum;
  }
  sum = 0;
  stack<pair<long long, long long>> t;
  for (int i = n - 1; i >= 0; i--) {
    long long cur = 1;
    while (!t.empty() && t.top().first >= m[i]) {
      sum -= t.top().first * t.top().second;
      cur += t.top().second;
      t.pop();
    }
    sum += m[i] * cur;
    t.push({m[i], cur});
    dq[i] = sum;
  }
  long long ma = 0;
  int p;
  for (int i = 0; i < int(n); i++) {
    if (ma < dp[i] + dq[i] - m[i]) {
      ma = dp[i] + dq[i];
      p = i;
    }
  }
  long long a = m[p];
  for (int i = p - 1; i >= 0; i--) {
    m[i] = min(a, m[i]);
    a = min(a, m[i]);
  }
  a = m[p];
  for (int i = int(p + 1); i < int(n); i++) {
    m[i] = min(a, m[i]);
    a = min(a, m[i]);
  }
  for (int i = 0; i < int(n); i++) cout << m[i] << ' ';
  return;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int query = 1;
  for (int i = 0; i < int(query); i++) {
    solve();
  }
}
