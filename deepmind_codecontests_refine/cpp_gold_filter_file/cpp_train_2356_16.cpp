#include <bits/stdc++.h>
using namespace std;
static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
template <class T>
inline vector<T> rv(long long n) {
  vector<T> v(n);
  for (long long i = 0; i < (n); i++) cin >> v[i];
  return v;
}
template <class T>
inline void pv(const vector<T>& v) {
  for (long long i = 0; i < (v.size()); i++) cout << v[i] << " ";
  cout << endl;
}
template <class T>
inline void amax(T& a, const T& b) {
  if (a < b) a = b;
}
template <class T>
inline void amin(T& a, const T& b) {
  if (a > b) a = b;
}
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
struct Rd {
  template <typename T>
  Rd& operator>>(T& n) {
    cin >> n;
    return *this;
  }
  template <typename T>
  Rd& operator>>(vector<T>& v) {
    for (long long i = 0; i < v.size(); i++) {
      cin >> v[i];
    }
    return *this;
  }
  template <typename T, typename U>
  Rd& operator>>(vector<pair<T, U>>& v) {
    for (long long i = 0; i < v.size(); i++) {
      cin >> v[i].first >> v[i].second;
    }
    return *this;
  }
  template <typename T>
  Rd& operator>>(vector<vector<T>>& v) {
    for (long long i = 0; i < v.size(); i++) {
      for (long long j = 0; j < v[i].size(); j++) {
        cin >> v[i][j];
      }
    }
    return *this;
  }
} rd;
int main(int argc, char** argv) {
  long long n;
  rd >> n;
  vector<long long> a(n);
  rd >> a;
  long long ans = 0;
  for (long long i = (1); i < (n - 1); i++) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1] ||
        a[i] < a[i - 1] && a[i] < a[i + 1])
      ans++;
  }
  cout << ans << endl;
  return 0;
}
