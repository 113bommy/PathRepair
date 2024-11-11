#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6;
const long long MOD = (int)1e9 + 7;
int a[100100];
struct bit {
  long long s[N + 1000];
  inline void add(int x, long long k) {
    for (; x <= N; x += (x & (-x))) s[x] = (s[x] + k) % MOD;
  }
  inline long long sum(int x) {
    long long res = 0;
    for (; x; x -= (x & (-x))) res = (res + s[x]) % MOD;
    return res;
  }
  inline long long val(int x) { return (sum(x) - sum(x - 1) + MOD) % MOD; }
} seq;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    long long renew = (seq.sum(a[i]) + 1LL) * (long long)a[i] % MOD;
    seq.add(a[i], renew - seq.val(a[i]));
  }
  printf("%I64d\n", seq.sum(N));
  return 0;
}
