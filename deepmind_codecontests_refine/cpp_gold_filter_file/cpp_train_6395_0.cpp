#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int N = 100009;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long INF64 = 2e18;
const long double PI = 3.1415926535897932384626433832795;
const long double eps = 1e-9;
int main() {
  srand(time(NULL));
  cout << setprecision(10) << fixed;
  cerr << setprecision(10) << fixed;
  int t;
  cin >> t;
  for (int _ = 0; _ < (int)(t); ++_) {
    int n, p;
    cin >> n >> p;
    vector<pair<int, int> > edges;
    for (int i = 0; i < (int)(n); ++i)
      edges.push_back(make_pair(i, (i + 1) % n));
    for (int i = 0; i < (int)(n); ++i)
      edges.push_back(make_pair(i, (i + 2) % n));
    int d = 0;
    while (p > 0) {
      for (int i = 0; i < (int)(min(p, n)); ++i)
        edges.push_back(make_pair(i, (i + 3 + d) % n));
      p -= n;
      ++d;
    }
    for (int i = 0; i < (int)((int)(edges.size())); ++i)
      cout << edges[i].first + 1 << ' ' << edges[i].second + 1 << endl;
  }
  return 0;
}
