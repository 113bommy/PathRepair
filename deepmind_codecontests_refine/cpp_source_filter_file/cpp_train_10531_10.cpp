#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
const long long INF = 1011111111;
const long long LLINF = 1000111000111000111LL;
const long double EPS = 1e-10;
const long double PI = 3.14159265358979323;
using namespace std;
long long powm(long long base, long long exp, long long mod = MOD) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % mod;
    exp >>= 1, base = (base * base) % mod;
  }
  return ans;
}
const long long N = 1000005;
long long mk[N], pref[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, x;
  cin >> n >> x;
  long long bada = (1LL << n);
  if (x >= bada) {
    cout << bada - 1 << '\n';
    for (long long i = 1; i < bada; i++) cout << (i ^ (i - 1)) << " ";
  } else {
    for (long long i = 1; i < n + 1; i++) mk[i] = 1;
    mk[x] = 0;
    for (long long i = 1; i < bada; i++)
      if (mk[i]) mk[i ^ x] = 0;
    cout << (bada - 1) / 2 << '\n';
    long long cnt = 1;
    for (long long i = 1; i < bada; i++)
      if (mk[i]) pref[cnt++] = i;
    for (long long i = 1; i < cnt; i++) cout << (pref[i] ^ pref[i - 1]) << " ";
  }
  return 0;
}
