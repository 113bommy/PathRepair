#include <bits/stdc++.h>
using namespace std;
long long n, tmp, k[1000005], ans, val[1000005], inv[1000005];
vector<int> v[1000005];
long long fastp(long long base, long long exp) {
  if (exp == 0) return 1ll;
  long long tmp = fastp(base, exp / 2);
  tmp = (tmp * tmp) % 998244353ll;
  if (exp % 2) tmp *= base;
  return tmp % 998244353ll;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i < 1000005; i++) inv[i] = fastp(i, 998244353ll - 2);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++) {
      cin >> tmp;
      val[tmp] += (inv[n] * inv[k[i]]) % 998244353ll;
      val[tmp] %= 998244353ll;
      v[i].push_back(tmp);
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k[i]; j++)
      ans = (ans + (val[v[i][j]] * inv[n]) % 998244353ll) % 998244353ll;
  cout << ans << "\n";
  return 0;
}
