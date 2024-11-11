#include <bits/stdc++.h>
using namespace std;
const long long MAX = 4e5 + 7;
long long MOD;
void print(bool a) { cout << (a ? "YES" : "NO") << '\n'; }
long long fa[MAX], size[MAX];
long long find(long long x) {
  if (fa[x] == x) {
    return x;
  }
  return fa[x] = find(fa[x]);
}
void merge(long long a, long long b) {
  size[find(a)] += size[find(b)];
  size[find(b)] = 0;
  fa[find(b)] = find(a);
}
long long quick_pow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1LL) ret = ret * x % MOD;
    y >>= 1LL;
    x = x * x % MOD;
  }
  return ret;
}
signed main() {
  long long N, M;
  cin >> N >> M >> MOD;
  for (long long i = 1; i <= N; i++) {
    fa[i] = i;
    size[i] = 1;
  }
  long long tot = N;
  while (M--) {
    long long a, b;
    cin >> a >> b;
    if (find(a) != find(b)) {
      tot--;
      merge(a, b);
    }
  }
  if (tot == 1) {
    cout << 1 % MOD << '\n';
  } else {
    long long ans = quick_pow(N, tot - 2);
    for (long long i = 1; i <= N; i++) {
      if (find(i) == i) {
        ans = ans * size[i] % MOD;
      }
    }
    cout << ans << '\n';
  }
}
