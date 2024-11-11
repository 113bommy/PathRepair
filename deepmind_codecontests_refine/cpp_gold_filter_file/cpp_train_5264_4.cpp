#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
void itval(istream_iterator<string> it) {}
template <typename T, typename... Args>
void itval(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  itval(++it, args...);
}
const long long int MOD = 1e9 + 7;
template <typename T>
inline void print(T x) {
  cout << x << "\n";
}
template <typename T>
inline void printvec(T x) {
  for (auto a : x) cout << a << ' ';
  cout << '\n';
}
struct custom {
  bool operator()(
      const pair<long long int, pair<long long int, long long int> > &p1,
      const pair<long long int, pair<long long int, long long int> > &p2)
      const {
    return p1.second.second < p2.second.second;
  }
};
long long int get_pow(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
const long long int N = 1e5 + 5, inf = 4e18;
bool cmp(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  return a.first < b.first;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long> v(n);
  for (long long int i = (long long int)0; i < (long long int)(n); i++)
    cin >> v[i];
  std::vector<pair<long long int, long long int> > want;
  for (long long int i = (long long int)0; i < (long long int)(n); i++) {
    long long int x = v[i];
    while (x > 0) {
      want.push_back({x, i});
      x = x / 2;
    }
  }
  sort(want.begin(), want.end(), cmp);
  int lo = -1, hi = want.size();
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2, cnt = 0;
    vector<bool> used(n, false);
    set<int> s;
    for (int j = mid; j >= 0; j--) {
      if (!used[want[j].second] && !s.count(want[j].first)) {
        used[want[j].second] = 1;
        cnt++;
        s.insert(want[j].first);
      }
    }
    if (cnt == n) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  vector<bool> used(n, false);
  set<int> s;
  for (int j = hi; j >= 0; j--) {
    if (!used[want[j].second] && !s.count(want[j].first)) {
      used[want[j].second] = 1;
      s.insert(want[j].first);
    }
  }
  printvec(s);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1;
  clock_t z = clock();
  for (long long int tes = (long long int)0; tes < (long long int)(test);
       tes++) {
    solve();
  }
  fprintf(stderr, "Total Time:%.4f\n", (double)(clock() - z) / CLOCKS_PER_SEC),
      fflush(stderr);
  return 0;
}
