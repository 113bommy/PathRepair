#include <bits/stdc++.h>
using namespace std;
const int maxN = 300005;
const int mod = 1e9 + 7;
int n, a[maxN], c[maxN], fact[maxN], sum[maxN];
vector<int> pr[maxN];
int inv(int a) {
  int n = mod - 2, res = 1;
  while (n) {
    if (n & 1) res = (1LL * res * a) % mod;
    a = (1LL * a * a) % mod;
    n /= 2;
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    for (int j = 2; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        int cnt = 0;
        while (a[i] % j == 0) {
          ++cnt;
          a[i] /= j;
        }
        pr[j].push_back(cnt);
      }
    }
    if (a[i] > 1) {
      pr[a[i]].push_back(1);
    }
  }
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (1LL * fact[i - 1] * i) % mod;
  }
  for (int i = 0; i < n; ++i) {
    c[i] = fact[n - 1];
    c[i] = (1LL * c[i] * inv(fact[n - 1 - i])) % mod;
    c[i] = (1LL * c[i] * inv(fact[i])) % mod;
    sum[i] = c[i];
    if (i > 0) sum[i] += sum[i - 1];
    sum[i] %= mod;
  }
  int res = 0;
  for (int i = 2; i < maxN; ++i) {
    sort(pr[i].begin(), pr[i].end());
    int L = n - (int)pr[i].size(), R = (int)pr[i].size() - 1;
    for (auto& x : pr[i]) {
      res = (res + 1LL * sum[L] * x) % mod;
      res = (res - 1LL * sum[R] * x) % mod;
      if (res < 0) res += mod;
      ++L;
      --R;
    }
  }
  cout << res << "\n";
  return 0;
}
