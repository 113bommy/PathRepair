#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 220010, p = 179, mod = 1791791791;
long long int predp[maxn];
map<long long int, long long int> mp;
int main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
  long long int n, k;
  cin >> n >> k;
  predp[0] = 1;
  for (int d = 1; d < maxn; d++) {
    predp[d] = (predp[d - 1] * p) % mod;
  }
  vector<long long int> mas(n, 0);
  for (int d = 0; d < n; d++) {
    cin >> mas[d];
  }
  long long int ans = 0;
  for (int d = 0; d < n; d++) {
    vector<pair<long long int, long long int> > del;
    long long int n1 = mas[d];
    long long int hash1 = 0;
    long long int hash2 = 0;
    for (int i = 2; i * i <= mas[d] && i <= n1; i++) {
      if (n1 % i == 0) {
        long long int cnt = 0;
        while (n1 % i == 0) {
          n1 /= i;
          cnt++;
        }
        cnt %= k;
        hash1 += predp[i] * cnt;
        hash1 %= mod;
        hash2 += predp[i] * ((k - cnt) % k);
        hash2 %= mod;
      }
    }
    if (n1 != 1) {
      hash1 += predp[n1];
      hash1 %= mod;
      hash2 += predp[n1] * (k - 1);
      hash2 %= mod;
    }
    ans += mp[hash2];
    mp[hash1]++;
  }
  cout << ans;
}
