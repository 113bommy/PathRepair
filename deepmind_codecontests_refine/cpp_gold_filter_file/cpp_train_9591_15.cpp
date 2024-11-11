#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1e18;
const long long int mod = 1e9 + 7;
inline long long int add(long long int x, long long int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline long long int sub(long long int x, long long int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline long long int mul(long long int x, long long int y) {
  return ((x % mod) * (y % mod)) % mod;
}
inline long long int power(long long int a, long long int b) {
  long long int x = 1;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline long long int inv(long long int a) { return power(a, mod - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t start = clock();
  long long int n, k;
  cin >> n >> k;
  long long int ans = 0, s = 0, e = 0;
  vector<long long int> a(n + 1), vis(n + 1, 1);
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= n; j++) vis[j] = 1;
    for (long long int c = i; c <= n; c += k) vis[c] = 0;
    for (long long int c = i; c > 0; c -= k) vis[c] = 0;
    s = 0, e = 0;
    for (long long int j = 1; j <= n; j++) {
      if (vis[j]) {
        if (a[j] == -1)
          s++;
        else
          e++;
      }
    }
    ans = max(ans, abs(e - s));
  }
  cout << ans << endl;
  clock_t end = clock();
  cerr << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds"
       << endl;
  return 0;
}
