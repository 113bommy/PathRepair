#include <bits/stdc++.h>
using namespace std;
template <class T>
T sq(T x) {
  return x * x;
}
const long long inf = 2147383647;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
const long long maxint = 2147483647;
const long long minint = -2147483648;
struct fence {
  int x, y;
} arr[110];
long long mod = 1000000007;
int n;
long long memo[101][2][3001];
int done[101][2][3001];
long long dp(int type, int dir, int len) {
  if (len < 0) return 0;
  if (len == 0) return 1;
  if (done[type][dir][len]) return memo[type][dir][len];
  long long res = 0;
  int i;
  int tx, ty;
  tx = arr[type].x;
  ty = arr[type].y;
  if (dir) swap(tx, ty);
  for (i = 0; i < n; i++) {
    if (i == type) continue;
    if (arr[i].x == ty) {
      res = (res + dp(i, 0, len - arr[i].x)) % mod;
    }
    if (arr[i].x != arr[i].y && arr[i].y == ty) {
      res = (res + dp(i, 1, len - arr[i].y)) % mod;
    }
  }
  done[type][dir][len] = 1;
  return memo[type][dir][len] = res;
}
int main() {
  int l;
  scanf("%d %d", &n, &l);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d %d", &arr[i].x, &arr[i].y);
  }
  long long res = 0;
  for (i = 0; i < n; i++) {
    res = (res + dp(i, 0, l - arr[i].x)) % mod;
    if (arr[i].x != arr[i].y) res = (res + dp(i, 1, l - arr[i].y)) % mod;
  }
  printf("%lld\n", res);
  return 0;
}
