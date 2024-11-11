#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long powm(long long base, long long exp, long long mod = 1000000007) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % mod;
    exp >>= 1, base = (base * base) % mod;
  }
  return ans;
}
long long a[100005];
int main() {
  long long n, ans = 0, curr = 0;
  cin >> n;
  for (long long i = 1; i < n + 1; i++) cin >> a[i];
  for (long long i = 1; i < n + 1; i++) {
    curr = 0;
    for (long long j = i; j < n + 1; j++) curr ^= a[j], ans = max(ans, curr);
  }
  cout << ans;
  return 0;
}
