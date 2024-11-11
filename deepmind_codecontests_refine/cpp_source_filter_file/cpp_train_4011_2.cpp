#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX / 2, MOD = 1000000007, N = (int)2e5 + 10;
const long long INFL = LLONG_MAX / 2;
template <typename T, typename U>
static void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static void amax(T &x, U y) {
  if (x < y) x = y;
}
long long s, x;
int main() {
  scanf("%lld%lld", &s, &x);
  long long tp = x;
  long long cnt = 0;
  long long cur = (s - x) / 2;
  if (cur * 2 + x != s || cur & x != 0 || x > s) {
    puts("0");
    return 0;
  }
  while (tp) {
    cnt += (1 & tp);
    tp >>= 1;
  }
  long long ans = (1LL << cnt);
  if (s == x) ans -= 2;
  printf("%lld\n", ans);
  return 0;
}
