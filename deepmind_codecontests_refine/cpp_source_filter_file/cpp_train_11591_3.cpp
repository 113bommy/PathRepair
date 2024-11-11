#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int cMin(T& a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline int cMax(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline string to_str(T v) {
  ostringstream os;
  os << v;
  return os.str();
}
const double pi = acos(-1.0);
const double eps = 1e-9;
template <class T>
inline T isqr(T v) {
  return v * v;
}
template <class T>
inline T iabs(T v) {
  return v < 0 ? -v : v;
}
template <class T>
inline int isgn(T v) {
  return iabs(v) <= eps ? 0 : (v < 0 ? -1 : 1);
}
template <typename T>
inline T next() {
  static char buf[64];
  scanf("%s", buf);
  istringstream is(buf);
  T v;
  is >> v;
  return v;
}
inline int nextInt() {
  int v = 0;
  scanf("%d", &v);
  return v;
}
const int NN = 4000 + 8;
int N, K;
pair<int, int> src[NN];
int dp[86400 + 8] = {0};
int sum[86400 + 8] = {0};
int main(int argc, char* argv[]) {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < (int)(N); ++i)
    scanf("%d%d", &src[i].first, &src[i].second);
  if (N == K) {
    puts("86400");
    return 0;
  }
  for (int i = 0; i < (int)(N); ++i) sum[src[i].first]++;
  for (int i = 1; i <= (int)(86400); ++i) sum[i] += sum[i - 1];
  sort(src, src + N);
  int ans = 0;
  ans = src[K].first - 1;
  for (int k = 0; k < (int)(N); ++k) {
    int curT = src[k].first;
    int curD = src[k].second;
    for (int t = 86400; t >= curT + curD; --t) cMax(dp[t], dp[t - curD] + 1);
  }
  for (int t = 1; t <= 86400; ++t) {
    int c = sum[t - 1] - dp[t];
    if (c > K) continue;
    int lo = t, hi = 86401, mi;
    while (lo + 1 < hi) {
      mi = (lo + hi) >> 1;
      if (sum[mi] - sum[t - 1] + c <= K)
        lo = mi;
      else
        hi = mi;
    }
    cMax(ans, lo - t + 1);
  }
  printf("%d\n", ans);
  return 0;
}
