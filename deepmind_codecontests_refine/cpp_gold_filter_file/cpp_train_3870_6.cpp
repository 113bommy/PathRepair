#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int fact[N], invfact[N];
long long pow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
long long modinv(long long k) { return pow(k, 1000000007 - 2, 1000000007); }
long long nCr(long long x, long long y) {
  if (y > x) return 0;
  long long num = fact[x];
  num *= invfact[y];
  num %= 1000000007;
  num *= invfact[x - y];
  num %= 1000000007;
  return num;
}
int main() {
  long long n, k;
  cin >> n >> k;
  string second;
  cin >> second;
  long long dp[n + 1];
  dp[0] = 1;
  long long freq[26];
  long long prev[n], curr[n];
  for (int i = 0; i < n; i++) {
    prev[i] = 1;
    curr[i] = 0;
  }
  for (int i = 0; i < 26; i++) freq[i] = -1;
  for (int i = 0; i < n; i++) {
    freq[second[i] - 'a'] = i;
  }
  int c = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] != -1) c++;
    freq[i] = -1;
  }
  dp[1] = c;
  for (int len = 2; len <= n; len++) {
    dp[len] = 0;
    for (int h = 0; h < n; h++) curr[h] = 0;
    for (int h = 0; h < 26; h++) freq[h] = -1;
    for (int i = len - 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        freq[second[j] - 'a'] = j;
      }
      for (int j = 0; j < 26; j++) {
        if (freq[j] != -1) curr[i] += prev[freq[j]];
      }
    }
    for (int h = 0; h < n; h++) freq[second[h] - 'a'] = h;
    for (int h = 0; h < 26; h++) {
      if (freq[h] != -1) dp[len] += curr[freq[h]];
    }
    for (int h = 0; h < n; h++) prev[h] = curr[h];
  }
  long long ans = 0;
  for (int i = n; i >= 0; i--) {
    int cost = n - i;
    if (k - dp[i] >= 0) {
      k -= dp[i];
      ans += dp[i] * cost;
    } else {
      ans += k * cost;
      k = 0;
      break;
    }
  }
  if (k != 0) ans = -1;
  cout << ans;
  return 0;
}
