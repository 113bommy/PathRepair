#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000 * 1000 * 1000 + 7;
int cnt[4], t[4], T[4];
int rev[4];
int h, w;
bool check(int a, int b, int c) {
  int x1 = bool(a & 2), y1 = a & 1;
  int x2 = bool(b & 2), y2 = b & 1;
  int x3 = bool(c & 2), y3 = c & 1;
  return ((x3 + x1) % 2 * (y2 + y1) % 2 + (y3 + y1) % 2 * (x2 + x1) % 2) % 2 ==
         0;
}
int gcd(int a, int b) { return min(a, b) == 0 ? a + b : gcd(b, a % b); }
int pow(int a, int b) {
  long long p = a;
  long long res = 1;
  for (int i = 1; i <= b; i *= 2, p = (p * p) % MOD)
    if (b & i) res = (res * p) % MOD;
  return res;
}
int main() {
  rev[2] = pow(2, MOD - 2);
  rev[3] = pow(3, MOD - 2);
  ios::sync_with_stdio(false);
  cin >> h >> w;
  h++, w++;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) cnt[i % 2 * 2 + j % 2]++;
  long long ans = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++) {
        if (!check(i, j, k)) continue;
        if (i < j || i < k) continue;
        if (j < k) continue;
        for (int h = 0; h < 4; h++) t[h] = cnt[h], T[h] = 0;
        long long x = 1;
        x = (x * t[i]) % MOD;
        t[i]--;
        T[i]++;
        x = (x * t[j]) % MOD;
        t[j]--;
        T[j]++;
        x = (x * t[k]) % MOD;
        t[k]--;
        T[k]++;
        for (int h = 0; h < 4; h++)
          for (int l = 2; l <= T[h]; l++) x = (x * rev[l]) % MOD;
        ans = (ans + x) % MOD;
      }
  for (int i = 0; i <= h; i++)
    for (int j = 0; j <= w; j++) {
      if (i == 0 && j == 0) continue;
      long long g = gcd(i, j) - 1;
      if (min(i, j) != 0) g *= 2;
      ans -= (g * (h - i) * (w - j)) % MOD;
      ans %= MOD;
    }
  ans = (ans + MOD) % MOD;
  cout << (ans * 6) % MOD << endl;
  {
    int _;
    cin >> _;
  }
  return 0;
}
