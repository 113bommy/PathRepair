#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int inf = 1e9L + 7;
const long long INF = 1e18L + 7;
template <class n, class s>
ostream &operator<<(ostream &p, pair<n, s> x) {
  return p << "<" << x.first << ", " << x.second << ">";
}
template <class n>
auto operator<<(ostream &p, n y) ->
    typename enable_if<!is_same<n, string>::value,
                       decltype(y.begin(), p)>::type {
  int o = 0;
  p << "{";
  for (auto c : y) {
    if (o++) p << ", ";
    p << c;
  }
  return p << "}";
}
void dor() { cerr << '\n'; }
template <class n, class... s>
void dor(n p, s... y) {
  cerr << p;
  dor(y...);
}
template <class n, class s>
void mini(n &p, s y) {
  if (p > y) p = y;
}
template <class n, class s>
void maxi(n &p, s y) {
  if (p < y) p = y;
}
const int N = 101;
int n, ans, rozne;
int a[N];
int cnt[N];
bitset<N> ple[N][N * N];
void add(int w, int x) {
  for (int i = x - 1; i >= 0; --i) {
    for (int j = i * 100; j >= 0; --j) {
      if (ple[i][j].any() || (i + j == 0)) {
        ple[i + 1][j + w] |= ple[i][j];
        ple[i + 1][j + w][w] = 1;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    add(a[i], i);
    if (++cnt[a[i]] == 1) ++rozne;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 100; ++j) {
      if (ple[i][i * j].count() == 1 && ple[i][i * j][j]) {
        if (cnt[j] == i) {
          if (rozne <= 2)
            ans = max(ans, n);
          else
            ans = max(ans, i);
        } else {
          if (rozne == 1)
            ans = max(ans, n);
          else
            ans = max(ans, i);
        }
      }
    }
  }
  cout << ans << '\n';
}
