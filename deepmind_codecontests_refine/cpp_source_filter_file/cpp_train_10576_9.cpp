#include <bits/stdc++.h>
#pragma GCC optimization("O3")
using namespace std;
template <typename T>
inline void Cin(T& first) {
  char c;
  T sign = 1;
  first = 0;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) first = first * 10 + c - '0';
  first *= sign;
}
template <typename T>
inline void Out(T first) {
  if (first > 9) Out(first / 10);
  putchar(first % 10 + '0');
}
template <typename T>
inline void Cout(T first, char c) {
  if (first < 0) putchar('-');
  first = abs(first);
  Out(first);
  putchar(c);
}
template <typename T, typename... Args>
inline void Cin(T& a, Args&... args) {
  Cin(a);
  Cin(args...);
}
template <typename T, typename... Args>
inline void Cout(T a, char c, Args... args) {
  Cout(a, c);
  Cout(args...);
}
const int N = 2205;
const int inf = 1e9 + 3;
const pair<long long, int> iinf = make_pair(1ll * inf * inf, 0);
int n, k, a[N], b[N];
vector<vector<pair<long long, int> > > f;
pair<long long, int> operator+(const pair<long long, int>& a,
                               const pair<long long, int>& b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
bool Check(int irene) {
  for (int i = 0; i <= n; ++i) fill(f[i].begin(), f[i].end(), iinf);
  f[0][0] = make_pair(0, 0);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i) f[i][j] = min(f[i][j], f[i - 1][j]);
      if (j) f[i][j] = min(f[i][j], f[i][j - 1]);
      if (i && j && i <= j)
        f[i][j] = min(f[i][j],
                      f[i - 1][j - 1] + make_pair(a[i] + b[j] - 2 * irene, 1));
    }
  }
  return f[n][n].second >= k;
}
void Enter() {
  cin >> n >> k;
  f.resize(n + 1);
  f[0].resize(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i], f[i].resize(n + 1);
  for (int i = 1; i <= n; ++i) cin >> b[i];
}
void Solve() {
  int low = -inf, high = inf;
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (Check(mid))
      high = mid - 1;
    else
      low = mid + 1;
  }
  Check(low);
  cout << f[n][n].first + 2 * k * low;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("test"
            ".inp",
            "r")) {
    freopen(
        "test"
        ".inp",
        "r", stdin);
    freopen(
        "test"
        ".out",
        "w", stdout);
  }
  Enter(), Solve();
  return 0;
}
