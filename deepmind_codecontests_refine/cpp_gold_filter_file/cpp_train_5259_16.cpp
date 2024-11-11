#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int maxn = 1e9, minn = -1e9;
long long modpow(long long base, long long exp, int modulus) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  scanf("%d", &n);
  int arr[100005];
  for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
  int ans = 0;
  int d[100005];
  for (int i = 0; i < 100005; ++i) d[i] = 0;
  for (int i = 0; i < n; ++i) {
    d[arr[i]] = 1 + d[arr[i] - 1];
    ans = max(ans, d[arr[i]]);
  }
  printf("%d\n", n - ans);
  return 0;
}
