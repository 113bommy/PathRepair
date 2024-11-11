#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
using namespace std;
using graph = vector<vector<long long>>;
using wgraph = vector<vector<pair<long long, long long>>>;
template <class A, class B>
ostream &operator<<(ostream &o, pair<A, B> &p) {
  return o << "(" << p.first << ", " << p.second << ")";
}
template <class RandomIt>
ostream &printIterable(ostream &o, RandomIt first, RandomIt second) {
  for (; first < second; ++first) o << (*first) << " ";
  return o;
}
template <class A>
istream &operator>>(istream &is, vector<A> &a) {
  for (auto &v : a) is >> v;
  return is;
}
template <class A>
ostream &operator<<(ostream &o, vector<A> &a) {
  return printIterable(o, a.begin(), a.end());
}
template <class A>
ostream &operator<<(ostream &o, set<A> &a) {
  return printIterable(o, a.begin(), a.end());
}
template <class A>
ostream &operator<<(ostream &o, multiset<A> &a) {
  return printIterable(o, a.begin(), a.end());
}
void init() {}
struct node {
  bool reachable;
  char value;
  node *last;
};
void operator|=(node &a, node &b) {
  if (b.reachable) {
    a.reachable = true;
    a.last = &b;
  }
}
void test_case() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  node dp[n + 1][2 * k + 1];
  for (long long i = 0; i <= n; i++)
    for (long long j = -k; j <= k; j++) dp[i][j + k] = {false, '\0', nullptr};
  dp[0][k].reachable = true;
  for (long long i = 0; i < n; i++) {
    for (long long j = -k + 1; j < k; j++) {
      if (dp[i][j + k].reachable) {
        if (s[i] == 'W')
          dp[i + 1][j + k + 1] |= dp[i][j + k],
              dp[i + 1][j + k + 1].value = 'W';
        else if (s[i] == 'L')
          dp[i + 1][j + k - 1] |= dp[i][j + k],
              dp[i + 1][j + k - 1].value = 'L';
        else if (s[i] == 'D')
          dp[i + 1][j + k] |= dp[i][j + k], dp[i + 1][j + k].value = 'D';
        else {
          dp[i + 1][j + k] |= dp[i][j + k], dp[i + 1][j + k].value = 'D';
          dp[i + 1][j + k - 1] |= dp[i][j + k],
              dp[i + 1][j + k - 1].value = 'L';
          dp[i + 1][j + k + 1] |= dp[i][j + k],
              dp[i + 1][j + k + 1].value = 'W';
        }
      }
    }
  }
  node *curr = nullptr;
  if (dp[n][0].reachable) curr = &dp[n][0];
  if (dp[n][k << 1].reachable) curr = &dp[n][k << 1];
  if (curr == nullptr) {
    cout << "NO\n";
    return;
  }
  string ans = "";
  while (curr != nullptr && curr->last != nullptr) {
    ans += curr->value;
    curr = curr->last;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  bool MULTITEST = false;
  init();
  long long tt = 1;
  if (MULTITEST) cin >> tt;
  while (tt--) test_case();
}
