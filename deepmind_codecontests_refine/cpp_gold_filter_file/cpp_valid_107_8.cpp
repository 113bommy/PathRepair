#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
void ckmn(T& a, T b) {
  a = min(a, b);
}
template <typename T>
void ckmx(T& a, T b) {
  a = max(a, b);
}
void rd(int& x) { scanf("%i", &x); }
void rd(long long& x) { scanf("%lld", &x); }
void rd(char* x) { scanf("%s", x); }
void rd(double& x) { scanf("%lf", &x); }
void rd(string& x) { scanf("%s", &x); }
template <typename T1, typename T2>
void rd(pair<T1, T2>& x) {
  rd(x.first);
  rd(x.second);
}
template <typename T>
void rd(vector<T>& x) {
  for (T& i : x) rd(i);
}
template <typename T, typename... A>
void rd(T& x, A&... args) {
  rd(x);
  rd(args...);
}
template <typename T>
void rd() {
  T x;
  rd(x);
  return x;
}
int ri() {
  int x;
  rd(x);
  return x;
}
template <typename T>
vector<T> rv(int n) {
  vector<T> x(n);
  rd(x);
  return x;
}
template <typename T>
void ra(T a[], int n, int st = 1) {
  for (int i = 0; i < n; ++i) rd(a[st + i]);
}
template <typename T1, typename T2>
void ra(T1 a[], T2 b[], int n, int st = 1) {
  for (int i = 0; i < n; ++i) rd(a[st + i]), rd(b[st + i]);
}
template <typename T1, typename T2, typename T3>
void ra(T1 a[], T2 b[], T3 c[], int n, int st = 1) {
  for (int i = 0; i < n; ++i) rd(a[st + i]), rd(b[st + i]), rd(c[st + i]);
}
void re(vector<int> E[], int m, bool dir = 0) {
  for (int i = 0, u, v; i < m; ++i) {
    rd(u, v);
    E[u].push_back(v);
    if (!dir) E[v].push_back(u);
  }
}
template <typename T>
void re(vector<pair<int, T>> E[], int m, bool dir = 0) {
  for (int i = 0, u, v; i < m; ++i) {
    T w;
    rd(u, v, w);
    E[u].push_back({v, w});
    if (!dir) E[v].push_back({u, w});
  }
}
const int N = 205;
const long long inf = 1e18;
pair<long long, long long> dp[N][N];
int x[N], y[N];
long long cross(int x1, int y1, int x2, int y2) {
  return (long long)x1 * y2 - (long long)x2 * y1;
}
long long area(int i, int j, int k) {
  return abs(cross(x[i] - x[j], y[i] - y[j], x[k] - x[j], y[k] - y[j]));
}
int main() {
  int n, k;
  rd(n, k);
  ra(x, y, n);
  long long top = 8e16, bot = 0, ans = 0, mid;
  while (top >= bot) {
    mid = top + bot >> 1;
    for (int len = 2; len <= n; len++) {
      for (int l = 1; l + len - 1 <= n; l++) {
        int r = l + len - 1;
        if (len == 2)
          dp[l][r] = {0, 0};
        else {
          dp[l][r] = {-inf, 0};
          for (int k = l + 1; k < r; k++) {
            pair<long long, long long> tmp = {
                dp[l][k].first + dp[k][r].first,
                dp[l][k].second + dp[k][r].second + area(l, k, r)};
            if (tmp.second >= mid) {
              tmp.first++;
              tmp.second = 0;
            }
            ckmx(dp[l][r], tmp);
          }
        }
      }
    }
    if (dp[1][n].first >= k + 1)
      bot = mid + 1, ans = mid;
    else
      top = mid - 1;
  }
  printf("%lld\n", ans);
  return 0;
}
