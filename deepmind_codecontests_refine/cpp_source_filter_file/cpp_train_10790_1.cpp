#include <bits/stdc++.h>
using namespace std;
inline long long int MOD(long long int a) {
  return (a % 1000000007 + 1000000007) % 1000000007;
}
inline long long int modAdd(long long int a, long long int b) {
  return MOD(MOD(a) + MOD(b));
}
inline long long int modSub(long long int a, long long int b) {
  return MOD(MOD(a) - MOD(b));
}
inline long long int modMul(long long int a, long long int b) {
  return MOD(MOD(a) * MOD(b));
}
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool isprime(long long int x) {
  if (x < 2) return false;
  if (x < 4) return true;
  if (!(x & 1)) return false;
  for (int i = 3; i * i <= x; i += 2)
    if (x % i == 0) return false;
  return true;
}
string toBinary(long long int n) {
  string r;
  while (n != 0) {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n /= 2;
  }
  return r;
}
long long int bi_ex(long long int x, long long int n) {
  long long int pro = 1;
  while (n > 0) {
    if (n % 2 == 1) pro = ((pro % 1000000007) * (x % 1000000007)) % 1000000007;
    x = ((x % 1000000007) * (x % 1000000007)) % 1000000007;
    n >>= 1;
  }
  return pro % 1000000007;
}
long long int powr(long long int n, long long int x) {
  if (x == 0) return 1;
  if (!(x & 1))
    return powr(n * n, x >> 1);
  else
    return n * powr(n * n, (x - 1) >> 1);
}
long long int A[100002], N;
int fun() {
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    int x = A[i];
    int j = i - 1;
    while (j >= 1 && A[j] > x) {
      A[j + 1] = A[j];
      j--;
      cnt++;
    }
    A[j + 1] = x;
  }
  return cnt;
}
signed main() {
  fastIO();
  long long int t = 1, mini, q, c, i, j, a, b, sum, m, mx, d, k, n, count;
  string st, stt, ts;
  c = 0;
  while (t--) {
    cin >> a >> b >> c;
    mx = max({a, b, c});
    d = min(a, b);
    q = mx - d;
    if (q > c) {
      d += c;
      cout << d * 2 << endl;
      continue;
    }
    c -= q;
    c /= 2;
    c *= 2;
    cout << mx * 2 + c << endl;
  }
  return 0;
}
