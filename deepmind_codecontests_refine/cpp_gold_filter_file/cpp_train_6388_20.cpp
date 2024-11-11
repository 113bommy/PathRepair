#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b,
                 long long mod = (long long)(1e9 + 7)) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1, mod) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  scanf("%d", &t);
  stringstream ss;
  for (int _ = 0; _ < t; _++) {
    int n;
    scanf("%d", &n);
    ss << max(0, n - 2) << endl;
  }
  printf("%s", ss.str().c_str());
  return 0;
}
