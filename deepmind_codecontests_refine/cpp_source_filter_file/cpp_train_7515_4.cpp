#include <bits/stdc++.h>
using namespace std;
const long long N = 1000009;
vector<long long> primeFactors(long long n) {
  vector<long long> pfact;
  while (n % 2 == 0) {
    pfact.push_back(2);
    n = n / 2;
  }
  long long i;
  for (i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      pfact.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) pfact.push_back(n);
  return pfact;
}
long long s[N];
long long a[N];
long long n;
long long func(long long mod) {
  long long res = 0;
  for (long long i = 1; i <= n; i++) {
    res += min(s[i] % mod, mod - s[i] % mod);
  }
  return res;
}
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  if (s[n] == 1) {
    cout << -1 << "\n";
    return;
  }
  vector<long long> push_front = primeFactors(s[n]);
  long long ans = 1e17;
  for (auto el : push_front) {
    ans = min(ans, func(el));
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
