#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MAXN = 1000010;
long long fact[MAXN];
int cnt[3];
long long pow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return ret;
}
long long rev(long long a) { return pow(a, mod - 2); }
long long comb(int n, int r) {
  return ((fact[n] * rev(fact[n - r])) % mod * rev(fact[r])) % mod;
}
int main() {
  int n;
  scanf(" %d", &n);
  int a;
  for (int(i) = (1); (i) <= (n); (i)++) {
    scanf(" %d", &a);
    cnt[a]++;
  }
  fact[0] = 1LL;
  for (int(i) = (1); (i) <= (n); (i)++) fact[i] = (fact[i - 1] * i) % mod;
  if (cnt[1] <= 2) {
    cout << fact[n] << endl;
    return 0;
  }
  long long T = 1LL;
  long long p1 = 1LL, p2 = 1LL, p3 = 0LL;
  for (int(i) = (1); (i) <= (cnt[1] / 2); (i)++) {
    T = (T * comb(cnt[1] - i * 2 + 2, 2)) % mod;
    p1 += (T * rev(fact[i])) % mod;
    p1 %= mod;
  }
  long long x = cnt[1];
  for (int(i) = (0); (i) <= (cnt[2] - 1); (i)++) {
    p2 = (p2 * x) % mod;
    x++;
  }
  x--;
  cerr << "p2" << ':' << p2 << endl;
  for (int(i) = (0); (i) <= (cnt[2]); (i)++) {
    p3 += ((comb(cnt[2], i) * fact[i]) % mod * p2) % mod;
    p3 %= mod;
    p2 = (p2 * rev(x)) % mod;
    x--;
  }
  cerr << "p1" << ':' << p1 << endl;
  cerr << "p3" << ':' << p3 << endl;
  cout << (p1 * p3) % mod << endl;
  return 0;
}
