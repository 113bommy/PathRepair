#include <bits/stdc++.h>
const bool debugging = 1;
using namespace std;
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  for (auto v : V) {
    os << v << " ";
  }
  return os << "";
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  for (auto s : S) {
    os << s << " ";
  }
  return os << "";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << P.first << " " << P.second;
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "\n";
  for (auto m : M) {
    os << m << "\n";
  }
  return os << "";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long N, K;
  cin >> N >> K;
  vector<long long> current(N);
  for (long long i = 0; i < N; i++) {
    cin >> current[i];
  }
  long long highest;
  cin >> highest;
  set<long long> points;
  for (long long i = 1; i < N; i++) {
    long long point;
    cin >> point;
    points.insert(point);
  }
  long long ans = K;
  long long final_points = current[K - 1] + highest;
  for (long long i = K - 2; i >= 0; i--) {
    auto it = points.upper_bound(final_points - current[i]);
    if (it != points.begin()) {
      ans--;
      points.erase(--it);
    } else {
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}
