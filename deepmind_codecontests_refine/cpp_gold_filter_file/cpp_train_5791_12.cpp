#include <bits/stdc++.h>
using namespace std;
template <class T>
void DBGpair(T a, string s = "") {
  return;
}
template <class T>
void DBGvec(vector<T> &a) {}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7;
const long long INF = 1e9;
void setIO(string filename) {
  if (fopen((filename + ".in").c_str(), "r")) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
  }
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t a) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(a + FIXED_RANDOM);
  }
  template <class T>
  size_t operator()(T a) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    hash<T> x;
    return splitmix64(x(a) + FIXED_RANDOM);
  }
  template <class T, class H>
  size_t operator()(pair<T, H> a) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    hash<T> x;
    hash<H> y;
    return splitmix64(x(a.first) * 37 + y(a.ssecond) + FIXED_RANDOM);
  }
};
template <class T, class H>
using umap = unordered_map<T, H, custom_hash>;
template <class T>
using uset = unordered_set<T, custom_hash>;
void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &i : a) cin >> i;
  umap<string, int> cnt;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 9; j++) {
      for (int k = 0; k < 9; k++) {
        if (j + k > 9) continue;
        string x = a[i].substr(j, k);
        cnt[x]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    string ans = a[i];
    int mlen = 10;
    for (int j = 0; j < 9; j++) {
      for (int k = 1; k < 9; k++) {
        if (j + k > 9) continue;
        string x = a[i].substr(j, k);
        cnt[x]--;
      }
    }
    for (int j = 0; j < 9; j++) {
      for (int k = 1; k < 9; k++) {
        if (j + k > 9) continue;
        string x = a[i].substr(j, k);
        if (cnt[x] == 0 && k < mlen) {
          mlen = k;
          ans = x;
        }
      }
    }
    for (int j = 0; j < 9; j++) {
      for (int k = 0; k < 9; k++) {
        if (j + k > 9) continue;
        string x = a[i].substr(j, k);
        cnt[x]++;
      }
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) solve();
  return 0;
}
