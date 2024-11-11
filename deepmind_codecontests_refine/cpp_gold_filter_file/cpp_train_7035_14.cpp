#include <bits/stdc++.h>
using namespace std;
template <typename T>
T ii() {
  T a;
  cin >> a;
  return a;
}
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
bool OK(string &p, string &t, vector<int> &ar, int k) {
  unordered_set<int, custom_hash> keys;
  for (int i = (0); i <= (k - 1); i++) keys.insert(ar[i]);
  int j = 0, m = t.length();
  int n = p.length();
  for (int i = (0); i <= (n - 1); i++) {
    if (keys.count(i + 1)) continue;
    if (p[i] == t[j]) ++j;
    if (j == m) return true;
  }
  return false;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string p, t;
  cin >> p >> t;
  int n = p.length();
  vector<int> ar(n);
  for (auto &it : ar) cin >> it;
  int start = 0, end = n;
  while (start < end) {
    int mid = start + end + 1 >> 1;
    if (OK(p, t, ar, mid))
      start = mid;
    else
      end = mid - 1;
  }
  cout << (start) << "\n";
  return 0;
}
