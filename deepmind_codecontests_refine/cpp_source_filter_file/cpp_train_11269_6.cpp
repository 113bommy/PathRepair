#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007, nmax = 1000005;
char c;
long long k, w, ans, temp;
int pote[nmax], potmod[nmax], siln[nmax], siln2[nmax], siln3[nmax];
int pot(int a, int n) {
  if (!n) return 1;
  int tt = pot(a, n / 2);
  long long tempe = (long long)tt * tt;
  tempe %= mod;
  if (n & 1) {
    tempe *= a;
    tempe %= mod;
  }
  return int(tempe);
}
int pot2(int a) {
  if (potmod[a]) return potmod[a];
  int tt = pot(siln[a], mod - 2);
  potmod[a] = tt;
  return tt;
}
int main() {
  cin >> k >> w;
  pote[0] = siln[0] = siln2[0] = siln3[0] = 1;
  for (int i = 1; i <= (int)k + 3; ++i) {
    temp = (long long)pote[i - 1] * k;
    pote[i] = temp % mod;
    temp = (long long)siln[i - 1] * (k - i + 1);
    siln[i] = temp % mod;
    temp = (long long)siln2[i - 1] * (k - i);
    siln2[i] = temp % mod;
    temp = (long long)siln3[i - 1] * (k - i - 1);
    siln3[i] = temp % mod;
  }
  for (int l = 1; l <= (int)k; ++l) {
    if (w >= l + 2) {
      temp = ((long long)siln[l] * siln[l]) % mod;
      temp *= pot(k, w - l);
      temp %= mod;
      ans += temp;
      if (0) cout << temp << endl;
      temp = ((long long)siln[l + 1] * siln[l + 1]) % mod;
      temp *= pot(k, w - l - 2);
      temp %= mod;
      ans += mod - temp;
      if (0) cout << temp << endl;
    } else if (w == l + 1) {
      temp = (long long)siln[l] * siln[l] % mod;
      temp *= k;
      temp %= mod;
      ans += temp;
      temp = (long long)siln2[l] * siln2[l] % mod;
      temp *= k;
      temp %= mod;
      ans += mod - temp;
    } else if (w == l) {
      temp = (long long)siln[l] * siln[l] % mod;
      ans += temp;
      temp = (long long)siln3[l - 1] * siln3[l - 1] % mod;
      temp *= k;
      temp %= mod;
      temp *= k - 1;
      temp %= mod;
      ans += mod - temp;
    } else {
      temp = (long long)siln[l] * pot2(l - w) % mod;
      temp *= temp;
      temp %= mod;
      temp *= pote[l - w];
      temp %= mod;
      ans += temp;
      temp = (long long)siln[l + 1] * pot2(l - w + 2) % mod;
      temp *= temp;
      temp %= mod;
      temp *= pote[l - w + 2];
      temp %= mod;
      ans += mod - temp;
    }
    ans %= mod;
    if (0) cout << l << ": " << ans << endl;
  }
  cout << ans;
  if (0) {
    scanf("%c", &c);
    scanf("%c", &c);
  }
  return 0;
}
