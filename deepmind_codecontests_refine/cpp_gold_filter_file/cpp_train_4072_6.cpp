#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAX_N = 300300;
constexpr int MAX = 300300;
constexpr int MOD = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int n;
int arr[MAX_N];
int cnt[MAX_N];
int pre[MAX_N];
int mob[MAX_N];
int prime[MAX_N];
int pre_d[MAX_N];
int main() {
  scanf(" %d", &n);
  int g = 0;
  for (int i = 0; i < n; ++i) {
    scanf(" %d", &arr[i]);
    g = gcd(g, arr[i]);
    cnt[arr[i]] = 1;
  }
  if (g != 1) {
    printf("-1\n");
    return 0;
  }
  if (cnt[1]) {
    printf("1\n");
    return 0;
  }
  mob[1] = 1;
  for (int d = 2; d < MAX; ++d) {
    if (!prime[d]) {
      for (int j = 2 * d; j < MAX; j += d) {
        prime[j] = d;
      }
      mob[d] = -1;
    } else if (d % (prime[d] * prime[d]) != 0) {
      mob[d] = mob[prime[d]] * mob[d / prime[d]];
    }
  }
  for (int d = 1; d < MAX; ++d) {
    pre_d[d] = 0LL;
    for (int i = d; i < MAX; i += d) {
      pre_d[d] += cnt[i];
    }
  }
  for (int k = 2; k <= 6; ++k) {
    ll ans = 0LL;
    for (int d = 1; d < MAX; ++d) {
      ll cur = mob[d];
      ll p = 0LL;
      for (int i = 0; i < k; ++i) {
        cur = cur * pre_d[d];
      }
      ans = (ans + cur);
    }
    if (ans != 0) {
      printf("%d\n", k);
      return 0;
    }
  }
  printf("7\n");
  return 0;
}
