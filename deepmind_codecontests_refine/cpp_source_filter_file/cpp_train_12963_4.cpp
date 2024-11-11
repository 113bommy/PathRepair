#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 * 4;
inline int g() {
  int x;
  cin >> x;
  return x;
}
inline long long gl() {
  long long x;
  cin >> x;
  return x;
}
inline char gc() {
  char x;
  cin >> x;
  return x;
}
inline string gs() {
  string s;
  cin >> s;
  return s;
}
template <typename T>
inline vector<T> gv(int len) {
  vector<T> a(len);
  for (auto &it : a) cin >> it;
  return a;
}
inline vector<int> gv(int len) {
  vector<int> a(len);
  for (auto &it : a) cin >> it;
  return a;
}
inline vector<pair<int, int>> gv_andPairCnt(int len) {
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
T sqr(T x) {
  return x * x;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto it : v) os << it << " ";
  os << "\n";
  return os;
}
template <typename T, typename H>
inline vector<pair<T, H>> gv_andBiPair(int len) {
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
const long long md = 1e9 + 7;
int main() {
  int n = g();
  vector<int> f(maxn), m(maxn);
  for (int i = 0; i < (n); ++i) {
    char p = gc();
    int l = g(), r = g();
    if (p == 'M') {
      m[l]++, m[r + 1]--;
    } else {
      f[l]++, f[r + 1]--;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    f[i] += f[i - 1];
    m[i] += m[i - 1];
    ans = max(ans, min(f[i], m[i]));
  }
  cout << ans;
}
