#include <bits/stdc++.h>
using namespace std;
const long long int INF = 9223372036854775807LL;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroint-loops")
long long int power(long long int b, long long int e, long long int m) {
  if (b == 0) return 0;
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long int power(long long int b, long long int e) {
  if (b == 0) return 0;
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
bool isPowerOfTwo(long long int x) { return (x && !(x & (x - 1))); }
bool prime[100005];
void sieve() {
  fill(prime, prime + 100005, true);
  prime[0] = prime[1] = false;
  for (long long int i = 2; i * i < 100005; i++) {
    if (prime[i]) {
      for (long long int j = i * i; j < 100005; j += i) prime[j] = false;
    }
  }
}
void solve() {
  sieve();
  long long int n;
  cin >> n;
  if (n > 2)
    cout << "2\n";
  else
    cout << "1\n";
  for (long long int i = 2; i <= n + 1; i++) {
    if (prime[i])
      cout << 1 << " ";
    else
      cout << 2 << " ";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int tt = 1;
  while (tt--) {
    solve();
    cout << "\n";
  }
  return 0;
}
