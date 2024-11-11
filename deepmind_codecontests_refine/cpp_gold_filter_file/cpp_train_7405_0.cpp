#include <bits/stdc++.h>
using namespace std;
const int MXN = 5e5 + 30;
const int MAXN = 5e3 + 300;
const long long INF = 1e9 + 7;
const long long BINF = 1e15;
const int mod = 1e9 + 7;
const long double EPS = 1e-15;
const long long dx[] = {0, 0, 1, -1};
const long long dy[] = {1, -1, 0, 0};
int n;
string second;
char a[MXN];
int q;
int x, y;
int dp[MXN];
int d[MXN];
int cnt[60];
int k = 52;
int ans[52][52];
int add(int a, int b) { return (a * 1LL + b) % mod; }
int mult(int a, int b) { return (a * 1LL * b) % mod; }
int sub(int a, int b) { return (a - b + mod) % mod; }
int fact[MXN];
int inv[MXN];
int res = 1;
int binpow(int a, int n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    int x = binpow(a, n / 2);
    return mult(x, x);
  } else {
    return mult(binpow(a, n - 1), a);
  }
}
int main() {
  cin >> second;
  n = second.size();
  for (int i = 0; i < n; i++) {
    if (second[i] >= 'a' && second[i] <= 'z') {
      second[i] = second[i] - 'a' + 1;
    } else {
      second[i] = second[i] - 'A' + 26 + 1;
    }
    cnt[second[i]]++;
  }
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = mult(fact[i - 1], i);
  }
  inv[n] = binpow(fact[n], mod - 2);
  inv[0] = 1;
  for (int i = n - 1; i >= 1; i--) {
    inv[i] = mult(inv[i + 1], (i + 1));
  }
  res = mult(fact[n / 2], fact[n / 2]);
  for (int i = 1; i <= k; i++) {
    res = mult(res, inv[cnt[i]]);
  }
  dp[0] = 1;
  for (int i = 1; i <= k; i++) {
    if (cnt[i] == 0) continue;
    for (int j = n / 2; j >= cnt[i]; j--) {
      dp[j] = add(dp[j], dp[j - cnt[i]]);
    }
  }
  for (int x = 1; x <= k; x++) {
    if (cnt[x] == 0) continue;
    for (int j = 0; j <= n / 2; j++) d[j] = dp[j];
    if (cnt[x] <= n / 2) ans[x][x] = dp[n / 2];
    for (int j = cnt[x]; j <= n / 2; j++) {
      d[j] = sub(d[j], d[j - cnt[x]]);
    }
    for (int y = 1; y <= k; y++) {
      if (y == x || cnt[y] == 0 || cnt[y] + cnt[x] > n / 2) continue;
      for (int j = cnt[y]; j <= n / 2; j++) {
        d[j] = sub(d[j], d[j - cnt[y]]);
      }
      ans[x][y] = d[n / 2] * 2LL % mod;
      for (int j = n / 2; j >= cnt[y]; j--) {
        d[j] = add(d[j], d[j - cnt[y]]);
      }
    }
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x >> y;
    cout << mult(ans[second[x - 1]][second[y - 1]], res) << '\n';
  }
}
