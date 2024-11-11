#include <bits/stdc++.h>
using namespace std;
template <typename T>
void pr(vector<T> &v) {
  for (int i = 0; i < (int)(v).size(); i++) cout << v[i] << " ";
  cout << '\n';
  ;
}
template <typename T>
void pr(vector<vector<T>> &v) {
  for (int i = 0; i < (int)(v).size(); i++) {
    pr(v[i]);
  }
}
template <typename T>
void re(T &x) {
  cin >> x;
}
template <typename T>
void re(vector<T> &a) {
  for (int i = 0; i < (int)(a).size(); i++) re(a[i]);
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest) {
  re(first);
  re(rest...);
}
template <typename T>
void pr(T x) {
  cout << x << '\n';
  ;
}
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  cout << first << " ";
  pr(rest...);
  cout << '\n';
  ;
}
void ps() {
  cout << '\n';
  ;
}
template <class T, class... Ts>
void ps(const T &t, const Ts &...ts) {
  cout << t;
  if (sizeof...(ts)) cout << " ";
  ps(ts...);
}
const long long MOD = 1000000007;
long double PI = 4 * atan(1);
long double eps = 1e-12;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long d, n, m;
  cin >> d >> n >> m;
  vector<pair<long long, long long>> gs;
  gs.push_back(make_pair(0, 0));
  for (int i = 0; i < m; i++) {
    long long x, p;
    cin >> x >> p;
    gs.push_back(make_pair(x, p));
  }
  sort(gs.begin(), gs.end());
  vector<int> next(m + 1);
  stack<pair<long long, long long>> st;
  st.push(make_pair(d, 0));
  for (int i = gs.size() - 1; i >= 1; i--) {
    while (st.top().second >= gs[i].second) st.pop();
    next[i] = st.top().first;
    st.push(gs[i]);
  }
  gs.push_back(make_pair(d, 0));
  long long fuel = n;
  long long ans = 0;
  for (int i = 1; i < m + 1; i++) {
    fuel -= gs[i].first - gs[i - 1].first;
    if (fuel < 0) {
      cout << -1 << '\n';
      ;
      return 0;
    }
    if (fuel >= next[i] - gs[i].first) continue;
    ans += min(n - fuel, next[i] - gs[i].first - fuel) * gs[i].second;
    fuel += min(n - fuel, next[i] - gs[i].first - fuel);
  }
  cout << ans << '\n';
  ;
}
