#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long n;
int cnt[N], k[N];
vector<int> a[N];
long long ans;
int mod = 998244353;
long long qmi(long long a, long long b, long long p) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * (long long)a % p;
    b >>= 1;
  }
  return res;
}
long long Fermat(long long a) { return qmi(a, mod - 2, mod); }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    a[i].resize(k[i] + 1);
    for (int j = 1; j <= k[i]; j++) {
      cin >> a[i][j];
      cnt[a[i][j]]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    long long tmp = 0;
    for (int j = 1; j <= k[i]; j++) {
      tmp += cnt[a[i][j]];
    }
    ans += ((tmp % mod) * Fermat(k[i])) % mod;
  }
  ans = ((ans % mod) * Fermat(1ll * n * n) % mod) % mod;
  cout << ans << endl;
}
