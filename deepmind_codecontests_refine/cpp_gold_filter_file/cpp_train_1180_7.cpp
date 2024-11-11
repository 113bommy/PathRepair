#include <bits/stdc++.h>
using namespace std;
template <typename T0, typename T1>
std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) {
  for (typename map<T0, T1>::const_iterator p = v.begin(); p != v.end(); p++) {
    os << p->first << ": " << p->second << " ";
  }
  return os;
}
template <typename T0, typename T1>
std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) {
  os << v.first << ": " << v.second << " ";
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) {
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << endl;
  }
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i] << " ";
  }
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const set<T>& v) {
  vector<T> tmp(v.B, v.E);
  os << tmp;
  return os;
}
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> w(N);
  for (long long i = 0, _n = (N); (i) < (int)_n; ++i) cin >> w[i];
  int L = 0, R = 0;
  int maxi = -1;
  int maxv = 0;
  map<int, int> hi;
  long long ans = 0;
  while (1) {
    if (R == N) break;
    while (R < N && maxv < K) {
      R++;
      hi[w[R - 1]]++;
      if (hi[w[R - 1]] > maxv) {
        maxv = hi[w[R - 1]];
        maxi = w[R - 1];
      }
    }
    if (maxv < K) break;
    ans += N - R + 1;
    while (L < N - 1 && maxv == K) {
      L++;
      hi[w[L - 1]]--;
      if (w[L - 1] == maxi) {
        maxv--;
        break;
      }
      ans += N - R + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
