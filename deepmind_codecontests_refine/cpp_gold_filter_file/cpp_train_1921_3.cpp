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
int used[maxn];
vector<int> gr[maxn];
int rec(int x) {
  if (used[x]) return 0;
  used[x] = true;
  int ans = 0;
  for (auto it : gr[x]) {
    ans += rec(it);
  }
  return ans + 1;
}
int main() {
  int n = g(), m = g();
  for (auto it : gv_andBiPair<int, int>(m)) {
    gr[it.first].push_back(it.second);
    gr[it.second].push_back(it.first);
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    int x = rec(i);
    ans *= (1LL << ((long long)x - 1));
  }
  cout << ans;
}
