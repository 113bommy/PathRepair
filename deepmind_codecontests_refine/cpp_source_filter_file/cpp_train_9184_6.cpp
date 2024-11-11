#include <bits/stdc++.h>
using namespace std;
int long long inline power(int long long a, int long long b, int long long p) {
  a %= p;
  int long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return ans;
}
int long long inv(int long long n, int long long p) {
  return power(n, p - 2, p);
}
bool inline isPrime(int long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int long long gcd(int long long a, int long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int long long t, n, m, i, j, k, l, r, h;
  cin >> n >> h >> l >> r;
  int long long b[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int long long dp[n + 1][h];
  int long long c[h], d[h];
  memset(dp, 0, sizeof(dp));
  memset(c, 0, sizeof(h));
  c[0] = 1;
  for (i = 0; i < n; i++) {
    memcpy(d, c, sizeof(c));
    memset(c, 0, sizeof(c));
    for (j = 0; j < h; j++) {
      if (d[j] == 0) continue;
      int long long j1 = l <= ((j + b[i + 1]) % h) && ((j + b[i + 1]) % h) <= r;
      int long long j2 =
          l <= ((j + b[i + 1] - 1) % h) && ((j + b[i + 1] - 1) % h) <= r;
      dp[i + 1][(j + b[i + 1]) % h] =
          max(dp[i + 1][(j + b[i + 1]) % h], dp[i][j] + j1);
      dp[i + 1][(j + b[i + 1] - 1) % h] =
          max(dp[i + 1][(j + b[i + 1] - 1) % h], dp[i][j] + j2);
      c[(j + b[i + 1]) % h] = 1;
      c[(j + b[i + 1] - 1) % h] = 1;
    }
  }
  int long long mx = 0;
  for (i = 0; i < h; i++) {
    mx = max(mx, dp[n][i]);
  }
  cout << mx << "\n";
}
