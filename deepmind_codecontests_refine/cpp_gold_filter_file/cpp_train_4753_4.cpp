#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
template <typename T>
using vec = vector<T>;
using vi = vec<int>;
using vl = vec<ll>;
template <typename T>
using que = queue<T>;
template <typename T>
using deq = deque<T>;
template <typename T>
T id(T b) {
  return b;
};
template <typename T>
void chmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void chmin(T &x, T y) {
  if (x > y) x = y;
}
template <typename S, typename K>
bool contains(S &s, K k) {
  return s.find(k) != s.end();
}
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
constexpr ll TEN(int n) {
  if (n == 0)
    return 1LL;
  else
    return 10LL * TEN(n - 1);
}
const int MAX_N = 500;
int n, m, k;
string l[MAX_N];
int main() {
  fastio();
  cin >> n >> m >> k;
  for (size_t i = 0; i < size_t(n); i++) cin >> l[i];
  vi dp(k + 1, 0);
  for (size_t i = 0; i < size_t(n); i++) {
    vi psum(m + 1, 0);
    for (size_t j = 1; j <= size_t(m); j++) {
      psum[j] = psum[j - 1] + (l[i][j - 1] == '1');
    }
    int total = count(l[i].begin(), l[i].end(), '1');
    vi temp(k + 1, 1000000);
    if (total <= k) temp[total] = 0;
    for (size_t j = 0; j < size_t(m); j++)
      for (int l = j; l < m; l++) {
        int c = psum[l + 1] - psum[j];
        int d = l - j + 1;
        if (total - c <= k) chmin(temp[total - c], d);
      }
    vi dp2(k + 1, 1000000);
    for (size_t j = 0; j < size_t(k + 1); j++)
      for (size_t l = 0; l < size_t(k + 1); l++) {
        if (l + j > k) break;
        chmin(dp2[l + j], dp[j] + temp[l]);
      }
    dp = dp2;
  }
  cout << dp[k] << endl;
  return 0;
}
