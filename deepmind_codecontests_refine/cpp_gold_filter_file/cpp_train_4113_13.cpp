#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool smin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool smax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
const long long N = 800 + 10;
long long n, mark[N];
vector<pair<long long, pair<long long, long long> > > vc;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  n *= 2;
  for (long long i = 2; i <= n; i++) {
    for (long long j = 1; j < i; j++) {
      long long x;
      cin >> x;
      vc.push_back({x, {i, j}});
    }
  }
  fill(mark, mark + N, -1);
  sort(vc.begin(), vc.end());
  reverse(vc.begin(), vc.end());
  for (auto x : vc) {
    long long v = x.second.first, u = x.second.second;
    if (mark[v] != -1 || mark[u] != -1) continue;
    mark[v] = u, mark[u] = v;
  }
  for (long long i = 1; i <= n; i++) cout << mark[i] << ' ';
  cout << endl;
}
