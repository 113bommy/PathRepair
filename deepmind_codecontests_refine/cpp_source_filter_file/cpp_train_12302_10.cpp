#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int L[200200], R[200200], l[200200], p[200200];
inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int inv(int u) {
  return u < 2 ? u : (long long)mod / u * (mod - inv(mod % u)) % mod;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", L + i);
  for (int i = 1; i <= n; i++) scanf("%d", R + i), R[i]++, l[i] = R[i] - L[i];
  R[0] = 1;
  l[0] = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    p[i] = ((long long)l[i] * l[i - 1] % mod -
            max(0, (min(R[i], R[i - 1]) - max(L[i], L[i - 1])))) *
           inv((long long)l[i] * l[i - 1]) % mod;
    add(p[i], mod);
    add(ans, p[i]);
    if (i > 1) {
      add(ans, 2LL * p[i] * p[i - 2] % mod);
      int c = max(0, min(R[i], min(R[i - 1], R[i - 2])) -
                         max(L[i], max(L[i - 1], L[i - 2])));
      int a = max(0, min(R[i - 2], R[i - 1]) - max(L[i - 2], L[i - 1])) - c;
      int b = max(0, min(R[i], R[i - 1]) - max(L[i], L[i - 1])) - c;
      int tmp = (long long)a * (l[i - 2] - 1) % mod * l[i] % mod;
      add(tmp, (long long)b * (l[i] - 1) % mod * l[i - 2] % mod);
      add(tmp, (long long)c * (l[i] - 1) % mod * (l[i - 2] - 1) % mod);
      add(tmp, (long long)(l[i - 1] - a - b - c) * l[i - 2] % mod * l[i] % mod);
      int tot = (long long)l[i - 2] * l[i - 1] % mod * l[i] % mod;
      add(ans, 2LL * tmp * inv(tot) % mod);
    }
    add(p[i], p[i - 1]);
  }
  cout << ans << endl;
  return 0;
}
