#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
const int MOD = 998244353;
long long f[maxn];
int lim[maxn];
long long frac[maxn], ifrac[maxn];
int arr[maxn], b[maxn];
int n;
long long fpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}
void init() {
  frac[0] = 1;
  for (int i = 1; i < maxn; i++) frac[i] = frac[i - 1] * i % MOD;
  ifrac[maxn - 1] = fpow(frac[maxn - 1], MOD - 2);
  for (int i = maxn - 2; i >= 0; i--) ifrac[i] = ifrac[i + 1] * (i + 1) % MOD;
  return;
}
long long A(int a, int b) {
  if (a < b || b < 0) return 0;
  return frac[a] * ifrac[a - b] % MOD;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    b[i] = arr[i] * 2;
  }
  sort(arr + 1, arr + 1 + n);
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    int dex = upper_bound(b + 1, b + 1 + n, arr[i]) - b;
    --dex;
    lim[i] = dex;
  }
  f[0] = 1;
  lim[0] = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++)
      f[i] = (f[i] + f[j] * A(n - 2 - lim[j], lim[i] - lim[j] - 1) % MOD) % MOD;
  }
  if (lim[n] == n - 1)
    cout << f[n] << "\n";
  else
    cout << 0 << "\n";
  return 0;
}
