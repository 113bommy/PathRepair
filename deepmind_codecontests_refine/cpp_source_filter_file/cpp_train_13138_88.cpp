#include <bits/stdc++.h>
#pragma Ofast
using namespace std;
long long base = 311;
long long mod = 1000000007;
long long n, z, ans = -1;
long long Hash[1111111], POW[1111111];
long long gethash(int i, int j) {
  return (Hash[j] - Hash[i - 1] * POW[j - i + 1] + mod * mod) % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  string s;
  cin >> s;
  n = s.length();
  POW[0] = 1;
  Hash[0] = s[0] - 'a' + 1;
  for (long long i = 1; i < n; i++) {
    POW[i] = POW[i - 1] * base % mod;
    Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1) % mod;
  }
  for (int k = 0; k < n - k; k++) {
    int x = gethash(0, k);
    int y = gethash(n - 1 - k, n - 1);
    if (x != y) continue;
    for (int i = 1; i < n - 1; i++) {
      z = gethash(i, i + k);
      if (x == z) {
        ans = k;
        break;
      }
    }
  }
  if (ans == -1)
    cout << "Just a legend";
  else
    for (int i = 0; i <= ans; i++) cout << s[i];
}
