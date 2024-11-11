#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 * 4;
inline int get() {
  int x;
  cin >> x;
  return x;
}
inline long long getlong() {
  long long x;
  cin >> x;
  return x;
}
inline string getString() {
  string s;
  cin >> s;
  return s;
}
template <typename T>
inline vector<T> getvector(int len) {
  vector<T> a(len);
  for (auto &it : a) cin >> it;
  return a;
}
inline vector<int> getvector(int len) {
  vector<int> a(len);
  for (auto &it : a) cin >> it;
  return a;
}
inline vector<pair<int, int>> getvector_andPairCnt(int len) {
  vector<pair<int, int>> a(len);
  int i = 1;
  for (auto &it : a) {
    it.second = i;
    i++;
    cin >> it.first;
  }
  return a;
}
double power_log(double power, double val) { return log(val) / log(power); }
template <typename T>
int sqr(T x) {
  return x * x;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto it : v) os << it << " ";
  os << "\n";
  return os;
}
template <typename T, typename H>
inline vector<pair<T, H>> getvector_andBiPair(int len) {
  vector<pair<T, H>> a(len);
  for (auto &it : a) {
    cin >> it.first >> it.second;
  }
  return a;
}
template <typename T>
inline set<T> vector_to_set(const vector<T> &vec) {
  set<T> s;
  for (auto &it : vec) s.insert(it);
  return s;
}
int main() {
  int n = get(), s = get();
  auto v = getvector(n);
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < (n / 2); i++) {
    if (v[i] > s) {
      ans += abs(v[i] - s);
    }
  }
  ans += abs(v[n / 2] - s);
  for (int i = (n / 2) + 1; i < n; i++) {
    if (v[i] < s) {
      ans += abs(v[i] - s);
    }
  }
  cout << ans;
}
