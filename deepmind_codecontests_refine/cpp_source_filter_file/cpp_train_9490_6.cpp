#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string cts(char x) {
  string t(1, x);
  return t;
}
long long rand(long long a, long long b) { return a + rng() % (b - a + 1); }
const int MOD = 1e9 + 7;
const int inf = (int)1e9 + 500;
const long long oo = (long long)1e18 + 500;
template <typename T>
void chmax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void chmin(T& a, T b) {
  a = min(a, b);
}
int n, m;
int A[200005];
int idx[200005];
vector<int> V[200005];
long long total;
bool check(int days) {
  vector<int> events[200005];
  unordered_set<int> done;
  for (long long i = 1; i <= (long long)n; ++i) {
    if (V[i].empty()) continue;
    auto it = upper_bound((V[i]).begin(), (V[i]).end(), days);
    if (it != V[i].begin()) --it;
    if (*it <= days) {
      events[*it].push_back(A[i]);
      done.insert(i);
    }
  }
  int burles = 0;
  int extra = 0;
  for (long long i = 1; i <= (long long)days; ++i) {
    ++burles;
    if (days >= 200005) continue;
    for (auto v : events[i]) {
      if (v <= burles) {
        burles -= v;
        v = 0;
      } else {
        v -= burles;
        burles = 0;
        extra += v;
      }
    }
  }
  for (long long i = 1; i <= (long long)n; ++i) {
    if (!done.count(i)) extra += A[i];
  }
  return burles >= extra * 2;
}
int32_t __attribute__((optimize("Ofast"), target("arch=sandybridge"))) main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (long long i = 1; i <= (long long)n; ++i) idx[i] = 0;
  cin >> n >> m;
  for (long long i = 1; i <= (long long)n; ++i) {
    cin >> A[i];
  }
  for (long long i = 1; i <= (long long)m; ++i) {
    int d, t;
    cin >> d >> t;
    V[t].push_back(d);
  }
  for (long long i = 1; i <= (long long)2e5; ++i) {
    sort((V[i]).begin(), (V[i]).end());
  }
  int lo = 0, hi = 2 * 200005;
  while (lo < hi - 1) {
    int mid = (lo + hi) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid;
  }
  cout << hi;
}
