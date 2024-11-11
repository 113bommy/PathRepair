#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long modpow(long long x, long long n, long long m) {
  if (n == 0) return 1 % m;
  long long u = modpow(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2 == 1) u = (u * x) % m;
  return u;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) cin >> i;
  vector<vector<int>> facts(100001);
  for (int i = 1; i <= 100000; i++) {
    for (int j = 1; j * j <= i; j++) {
      if (i % j) continue;
      facts[i].push_back(j);
      if (i / j != j) facts[i].push_back(i / j);
    }
  }
  for (int i = 1; i <= 100000; i++) {
    sort(facts[i].begin(), facts[i].end());
  }
  vector<int> cts(100002);
  cts[1] = n;
  for (int i : v) {
    cts[i + 1] -= 1;
  }
  for (int i = 2; i <= 100000; i++) {
    cts[i] += cts[i - 1];
  }
  long long ans = 1;
  for (int i = 2; i <= 100000; i++) {
    if (!cts[i]) continue;
    long long anst = 1;
    for (int j = 0; j < facts[i].size(); j++) {
      if (facts[i][j] != i) {
        long long ct = cts[facts[i][j]] - cts[facts[i][j + 1]];
        long long val = modpow(j + 1, ct, MOD);
        anst *= val;
        anst %= MOD;
      } else {
        long long ct = cts[i];
        long long val = modpow(j + 1, ct, MOD) - modpow(j, ct, MOD);
        if (val < 0) val += MOD;
        anst *= val;
        anst %= MOD;
      }
    }
    ans += anst;
    ans % +MOD;
  }
  cout << ans;
  return 0;
}
