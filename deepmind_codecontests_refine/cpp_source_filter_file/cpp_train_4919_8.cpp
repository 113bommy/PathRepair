#include <bits/stdc++.h>
using namespace std;
long long mulmod(long long x, long long y) {
  return (x % 1000000007 * y % 1000000007) % 1000000007;
}
long long addmod(long long x, long long y) {
  return (x % 1000000007 + y % 1000000007) % 1000000007;
}
long long power(long long x, long long y) {
  long long res = 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
const long long MAXN = 1e5 + 10;
int spf[MAXN];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < MAXN; i++) spf[i] = i;
  for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
  for (int i = 3; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < MAXN; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
map<long long, long long> getf(long long x) {
  map<long long, long long> ret;
  while (x != 1) {
    ret[spf[x]]++;
    x = x / spf[x];
  }
  return ret;
}
void testcases() {
  long long n, s;
  cin >> n >> s;
  if (s < 2 * n - 1)
    cout << "NO"
         << "\n";
  else {
    cout << "YES"
         << "\n";
    for (int i = 1; i <= n - 1; i++) cout << 1 << " ";
    cout << s - (n - 1) << "\n";
    cout << n << "\n";
  }
}
int main() {
  sieve();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) testcases();
}
