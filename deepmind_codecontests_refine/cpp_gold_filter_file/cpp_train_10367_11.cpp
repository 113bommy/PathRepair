#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
long long fact[N * 2];
long long powermod(long long a, int p) {
  if (p == 0)
    return 1;
  else if (p % 2 == 0)
    return powermod((a * a) % mod, p / 2);
  else
    return (a * powermod(a, p - 1)) % mod;
}
long long h;
long long Com(long long n, long long r) {
  long long ans = fact[n];
  long long f = (fact[r] * fact[n - r]) % mod;
  f = powermod(f, mod - 2);
  ans = (ans * f) % mod;
  return ans;
}
long long ways1(long long a, long long b) {
  if (a < b) return 0;
  if (a == 0 && b == 0) return 1;
  return Com(a - 1, b - 1);
}
long long ways2(long long a, long long b) { return ways1(a - b * h, b); }
int main() {
  long long f, w;
  cin >> f >> w >> h;
  long long a = 0, b = 0;
  long long x = f + w, temp;
  fact[0] = 1;
  for (int i = 1; i <= x; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
  for (int i = 0; i <= x; i++) {
    if (i == 0) {
      if (f == 0 && w == 0) b++, a++;
    } else if (i == 1) {
      if (f == 0 || w == 0) {
        temp = max(w, f);
        b++;
        if (w == 0 || w > h) a++;
      }
    } else {
      int c = (i + 1) / 2;
      int c2 = i - c;
      long long a1 = ways1(f, c);
      long long a2 = ways1(w, c2);
      a1 = (a1 * a2) % mod;
      b += a1;
      b %= mod;
      a1 = ways1(f, c);
      a2 = ways2(w, c2);
      a1 = (a1 * a2) % mod;
      a += a1;
      a %= mod;
      swap(c, c2);
      a1 = ways1(f, c);
      a2 = ways1(w, c2);
      a1 = (a1 * a2) % mod;
      b += a1;
      b %= mod;
      a1 = ways1(f, c);
      a2 = ways2(w, c2);
      a1 = (a1 * a2) % mod;
      a += a1;
      a %= mod;
    }
  }
  b = powermod(b, mod - 2);
  b *= a;
  b %= mod;
  cout << b << endl;
}
