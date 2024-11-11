#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
long long dp[MAXN];
struct line {
  long long m, b;
  long long eval(long long x) { return m * x + b; }
  long double isect(const line &o) {
    return (long double)(o.m - m) / (long double)(b - o.b);
  }
};
deque<line> dq;
long long query(long long x) {
  while (dq.size() >= 2 && dq.back().eval(x) <= dq[dq.size() - 2].eval(x))
    dq.pop_back();
  return dq.back().eval(x);
}
void add(long long m, long long b) {
  line l = line{m, b};
  while (dq.size() >= 2 && l.isect(dq[0]) >= l.isect(dq[1])) dq.pop_front();
  dq.push_front(l);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<pair<long long, long long>, long long>> rect(n);
  for (int i = 0; i < n; i++) {
    long long x, y, a;
    cin >> x >> y >> a;
    rect[i] = make_pair(pair<long long, long long>{x, y}, a);
  }
  sort(rect.begin(), rect.end());
  dp[0] = 0;
  add(0, 0);
  for (int i = 0; i < n; i++) {
    long long ans = rect[i].first.first * rect[i].first.second - rect[i].second;
    ans += query(rect[i].first.second);
    dp[i + 1] = ans;
    add(-rect[i].first.first, dp[i + 1]);
  }
  long long mx = 0;
  for (int i = 1; i <= n; i++) mx = max(mx, dp[i]);
  cout << mx << endl;
}
