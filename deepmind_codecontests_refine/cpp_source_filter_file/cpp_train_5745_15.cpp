#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace std {
template <>
struct hash<pair<int, int>> {
  size_t operator()(const pair<int, int> &x) const {
    long long P = 38923, Q = 109797901;
    return (size_t)((x.first * P + x.second) % Q);
  }
};
};  // namespace std
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
void print(T t) {
  cout << t << endl;
}
template <typename T, typename... Args>
void print(T t, Args... args) {
  cout << t << " ";
  print(args...);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int t = min((int)0, (int)tt); t < max((int)0, (int)tt); t += 1) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = min((int)0, (int)n); i < max((int)0, (int)n); i += 1)
      cin >> a[i];
    bool pos = true;
    for (int i = min((int)0, (int)n - 1); i < max((int)0, (int)n - 1); i += 1) {
      m -= (a[i + 1] - k) - a[i];
      if (m < 0) {
        pos = false;
        break;
      }
    }
    if (pos)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
