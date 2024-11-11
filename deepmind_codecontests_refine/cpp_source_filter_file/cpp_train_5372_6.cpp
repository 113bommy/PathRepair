#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int inf = 1e9 + 10;
constexpr ll INF = (ll)4e18 + 10;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
template <typename T>
using MaxHeap = priority_queue<T>;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = (0); i < (int)(n); ++i) cin >> a[i];
  if (k == 1) {
    ll ans = n * (n + 1) / 2;
    cout << ans << endl;
    return 0;
  }
  map<int, int> mp;
  int x = k;
  for (int i = (2); i < (int)(sqrt(k) + 1); ++i) {
    while (x % i == 0) {
      x /= i;
      mp[i]++;
    }
    if (x == 1) break;
  }
  if (x != 1) mp[x]++;
  vector<int> div;
  for (auto [a, b] : mp) div.emplace_back(a);
  int s = (int)(div).size();
  vector<vector<int>> vec(s, vector<int>(n + 1));
  for (int i = (0); i < (int)(s); ++i)
    for (int j = (0); j < (int)(n); ++j) {
      int cnt = 0;
      while (a[j] % div[i] == 0) {
        cnt++;
        a[j] /= div[i];
      }
      vec[i][j + 1] = vec[i][j] + cnt;
    }
  ll ans = 0;
  for (int i = (0); i < (int)(n); ++i) {
    int M = 0;
    for (int j = (0); j < (int)(s); ++j) {
      chmax(M, (int)(lower_bound((vec[j]).begin(), (vec[j]).end(),
                                 vec[j][i] + mp[div[j]]) -
                     vec[j].begin()));
    }
    ans += n + 1 - M;
  }
  cout << ans << endl;
  return 0;
}
