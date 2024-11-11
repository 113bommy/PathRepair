#include <bits/stdc++.h>
using namespace std;
template <class C>
void min_self(C &a, C b) {
  a = min(a, b);
}
template <class C>
void max_self(C &a, C b) {
  a = max(a, b);
}
long long mod(long long n, long long m = 1000000007) {
  n %= m, n += m, n %= m;
  return n;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
unordered_map<long long, int, custom_hash> safe_map;
const int MAXN = 2e5 + 5;
const int LOGN = 21;
const long long INF = 1e14;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> ind[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int test = 1; test < t + 1; test++) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      ind[i].clear();
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ind[x - 1].push_back(i);
    }
    int ans = 1e8;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < ind[i].size(); j++) {
        ans = min(ans, ind[i][j] - ind[i][j - 1] + 1);
      }
    }
    if (ans == 1e8) ans = -1;
    cout << ans, cout << "\n";
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
