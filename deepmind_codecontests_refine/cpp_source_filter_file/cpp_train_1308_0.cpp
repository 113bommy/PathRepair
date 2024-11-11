#include <bits/stdc++.h>
using namespace std;
int d8x[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int d8y[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int M = 1e9 + 7;
const int N = 1e3, Nx = 500;
int a[N + 1], c[N + 1];
bool isPrime[N + 1];
void sieve(int x) {
  for (int i = 0; i <= x; i++) isPrime[i] = true;
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i * i <= x; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= x; j += i) isPrime[j] = false;
    }
  }
}
template <class type>
type gcd(type a, type b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class type>
type MODEXPO(type a, type b, int mod) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return MODEXPO((a * a) % mod, b / 2, mod);
  else
    return (a * MODEXPO((a * a) % mod, (b - 1) / 2, mod)) % mod;
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast();
  int n;
  cin >> n;
  int ans = 1;
  for (int i = 0; i <= n - 1; i++) cin >> a[i], a[i]--;
  for (int i = 0; i <= n - 1; i++) {
    memset(c, 0, sizeof c);
    int l = 0, x = i;
    while (!c[x]) c[x] = 1, l++, x = a[x];
    if (x != i) {
      ans - 1;
      break;
    }
    if (l % 2 == 0) l /= 2;
    ans *= l / gcd(l, ans);
  }
  cout << ans;
  return 0;
}
