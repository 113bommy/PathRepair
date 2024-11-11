#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long maxn = (long long)2010;
const long double EPS = 1e-9;
const long long INF = (long long)1e18 + 18;
const long long mod = (long long)1e9 + 7;
long long n, a[maxn][maxn], dp1[maxn], dp2[maxn], s1 = -INF, s2 = -INF;
pair<long long, long long> p1, p2;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> a[i][j];
      dp1[i + j] += a[i][j];
      dp2[i - j + n - 1] += a[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i % 2 == j % 2) {
        if (dp1[i + j] + dp2[i - j + n - 1] - a[i][j] > s1) {
          s1 = dp1[i + j] + dp2[i - j + n - 1] - a[i][j];
          p1 = {i + 1, j + 1};
        }
      } else {
        if (dp1[i + j] + dp2[i - j + n - 1] - a[i][j] > s2) {
          s2 = dp1[i + j] + dp2[i - j + n - 1] - a[i][j];
          p2 = {i + 1, j + 1};
        }
      }
    }
  }
  cout << s1 + s2 << endl;
  cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second
       << endl;
  return 0;
}
