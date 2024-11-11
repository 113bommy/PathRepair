#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
long long f[100100], d[100100], dp[100100], ans, C;
int n, nn, k, a[100100], dig, mark[100100], ind;
vector<int> v;
bool luck(int x) {
  while (x > 0) {
    dig = x % 10;
    if (dig != 7 && dig != 4) return false;
    x /= 10;
  }
  return true;
}
inline long long c(int i, int j) {
  if (i < j) return 0;
  return (((f[i] * d[j]) % M) * d[i - j]) % M;
}
long long p(long long x, long long y) {
  if (y == 0) return 1;
  C = p(x, y / 2);
  C = (C * C) % M;
  if (y & 1) C = (C * x) % M;
  return C;
}
int main() {
  f[0] = 1;
  d[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    f[i] = (i * f[i - 1]) % M;
    d[i] = p(f[i], M - 2);
  }
  cin >> n >> k;
  nn = n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  v.push_back(0);
  for (int i = 0; i < n; i++)
    if (luck(a[i])) {
      nn--;
      if (a[i] == v.back())
        mark[ind]++;
      else {
        v.push_back(a[i]);
        ind++;
        mark[ind] = 1;
        ;
      }
    }
  if (n == 100000 && k == 100000) {
    cout << "here" << endl;
    return 0;
  }
  dp[0] = 1;
  for (int i = 1; i < v.size(); i++)
    for (int j = k; j >= 1; j--) dp[j] = (dp[j] + (dp[j - 1] * mark[i])) % M;
  for (int i = 0; i <= k; i++) ans = (ans + (c(nn, i) * dp[k - i])) % M;
  cout << ans << endl;
  return 0;
}
