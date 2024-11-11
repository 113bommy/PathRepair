#include <bits/stdc++.h>
using namespace std;
struct triplet {
  int first, second, third;
  triplet(int _f, int _s, int _t) { first = _f, second = _s, third = _t; }
  bool operator<(const triplet &oth) const {
    if (first != oth.first) return first < oth.first;
    if (second != oth.second) return second < oth.second;
    return third < oth.third;
  }
};
template <class T1, class T2>
bool upmin(T1 &x, T2 v) {
  if (x > v) {
    x = v;
    return true;
  }
  return false;
}
template <class T1, class T2>
bool upmax(T1 &x, T2 v) {
  if (x < v) {
    x = v;
    return true;
  }
  return false;
}
long long get_ways(long long n) {
  long long res = 0;
  for (int i = 2; 1LL * i * i * i <= n; ++i) res += n / (1LL * i * i * i);
  return res;
}
void solve() {
  long long M;
  cin >> M;
  long long lb = 1, ub = 1e16, ans = -1;
  while (lb <= ub) {
    long long mid = (lb + ub) / 2;
    if (get_ways(mid) >= M)
      ans = mid, ub = mid - 1;
    else
      lb = mid + 1;
  }
  if (get_ways(ans) == M)
    cout << ans << "\n";
  else
    cout << -1 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
