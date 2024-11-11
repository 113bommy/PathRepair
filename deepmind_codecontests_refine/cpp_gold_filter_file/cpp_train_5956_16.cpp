#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 998244353;
long long h[N], fact[N], finv[N];
long long choose(int n, int k);
long long pwr(long long x, long long e);
void mul(long long &x, long long y);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = finv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (i * fact[i - 1]) % mod;
    finv[i] = pwr(fact[i], mod - 2);
  }
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  int A = 0;
  for (int i = 0; i < n; ++i) {
    if (h[i] != h[(i + 1) % n]) {
      ++A;
    }
  }
  long long ans = 0;
  for (int cnt = 1; cnt <= A; ++cnt) {
    long long temp = choose(A, cnt);
    mul(temp, pwr(k - 2, A - cnt));
    if (cnt % 2 == 1) {
      mul(temp, pwr(2, cnt - 1));
    } else {
      long long temp2 = (pwr(2, cnt) - choose(cnt, cnt / 2) + mod);
      mul(temp2, pwr(2, mod - 2));
      mul(temp, temp2);
    }
    ans = (ans + temp) % mod;
  }
  mul(ans, pwr(k, n - A));
  cout << ans << endl;
}
long long choose(int n, int k) {
  if (k < 0 or k > n) {
    return 0;
  }
  long long ans = fact[n];
  mul(ans, finv[k]);
  mul(ans, finv[n - k]);
  return ans;
}
long long pwr(long long x, long long e) {
  long long res = 1;
  while (e) {
    if (e & 1) {
      mul(res, x);
    }
    mul(x, x);
    e /= 2;
  }
  return res;
}
void mul(long long &x, long long y) {
  x *= y;
  x %= mod;
}
