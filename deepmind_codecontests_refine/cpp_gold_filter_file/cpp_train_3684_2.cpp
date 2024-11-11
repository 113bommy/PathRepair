#include <bits/stdc++.h>
using namespace std;
const int infi = 1e9;
const long long int infl = 1e18;
const int MOD = 1e9 + 7;
template <typename Map>
bool map_compare(Map const& lhs, Map const& rhs) {
  return lhs.size() == rhs.size() &&
         std::equal(lhs.begin(), lhs.end(), rhs.begin());
}
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);
int randint(int p = MOD) { return mt() % p; }
long long int randlong(long long int p = infl) { return mt() % p; }
long long int log_2(long long int n) {
  return (n > 1ll) ? 1ll + log_2(n / 2) : 0ll;
}
inline void add(long long int& a, long long int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline void sub(long long int& a, long long int b) {
  a -= b;
  if (a < 0) a += MOD;
}
template <class T>
struct cmp {
  bool operator()(const T& x, const T& y) const { return x > y; }
};
const long long int N = 510;
long long int cost[N][N];
long long int a[N];
stack<long long int> s;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= n; j++) {
      cin >> cost[i][j];
    }
  }
  vector<long long int> nodes;
  for (long long int i = 1; i <= n; i++) cin >> a[n + 1 - i];
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= n; j++) {
      for (long long int k = 1; k <= n; k++) {
        cost[a[j]][a[k]] =
            min(cost[a[j]][a[k]], cost[a[j]][a[i]] + cost[a[i]][a[k]]);
      }
    }
    long long int w = 0;
    for (long long int j = 1; j <= i; j++) {
      for (long long int k = 1; k <= i; k++) {
        w += cost[a[j]][a[k]];
      }
    }
    s.push(w);
  }
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  return 0;
}
