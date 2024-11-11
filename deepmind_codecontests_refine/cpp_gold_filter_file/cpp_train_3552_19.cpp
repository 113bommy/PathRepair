#include <bits/stdc++.h>
using namespace std;
long long key = 503, mod = 1e9 + 7;
long long solve(long long s, long long e, vector<long long> temp) {
  long long n = e - s + 1, ans = 0;
  vector<int> d1(n), d2(n);
  for (int t = 0, l = 0, r = -1; t < n; t++) {
    int k = (t > r) ? 1 : min(d1[l + r - t], r - t + 1);
    while (t - k >= 0 && t + k < n && temp[t - k + s] == temp[t + k + s]) k++;
    d1[t] = k--;
    ans += d1[t];
    if (t + k > r) l = t - k, r = t + k;
  }
  for (int t = 0, l = 0, r = -1; t < n; t++) {
    int k = (t > r) ? 0 : min(d2[l + r - t + 1], r - t + 1);
    while (t - k >= 0 && t + k < n && temp[t - k - 1 + s] == temp[t + k + s])
      k++;
    d2[t] = k--;
    ans += d2[t];
    if (t + k > r) l = t - k - 1, r = t + k;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, ans = 0;
  cin >> n >> m;
  string a[n + 1];
  for (long long i = 1; i < n + 1; i++) cin >> a[i];
  vector<long long> pk(27);
  pk[0] = 1;
  for (long long i = 1; i < 27; i++) pk[i] = (pk[i - 1] * key) % mod;
  for (long long i = 1; i < m + 1; i++) {
    vector<long long> temp(n, 0), mask(n, 0);
    for (long long j = i; j < m + 1; j++) {
      int isP[n];
      for (long long k = 1; k < n + 1; k++) {
        long long pos = (int)a[k][j - 1] - 'a';
        temp[k - 1] = (temp[k - 1] + pk[pos]) % mod;
        mask[k - 1] = mask[k - 1] ^ (1 << pos);
        if (mask[k - 1] == 0 || (mask[k - 1] & (mask[k - 1] - 1)) == 0)
          isP[k - 1] = 1;
        else
          isP[k - 1] = 0;
      }
      for (long long k = 0; k < n; k++) {
        if (isP[k] == 0)
          continue;
        else {
          long long st = k;
          while (k < n && isP[k] == 1) k++;
          ans += solve(st, k - 1, temp);
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
