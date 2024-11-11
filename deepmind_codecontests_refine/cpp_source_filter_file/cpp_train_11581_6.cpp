#include <bits/stdc++.h>
using namespace std;
mt19937 rng(1337 * 1337);
const int maxn = 1e6 + 10, MOD = 1e9 + 7;
string s;
long long prefix[maxn], suffix[maxn], power[maxn];
long long exp(long long int base, long long exponent) {
  long long res = 1;
  while (exponent) {
    if (exponent & 1) res = (base * res) % MOD;
    exponent = exponent / 2;
    base = (base * base) % MOD;
  }
  return res;
}
long long inverse(long long n) { return exp(n, MOD - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  power[0] = 1;
  int p = rng();
  for (int i = 1; i < maxn - 5; i++) power[i] = (power[i - 1] * p) % MOD;
  while (t--) {
    cin >> s;
    int n = (int)s.size();
    if (n == 1) {
      cout << s << "\n";
      continue;
    }
    int i = -1, j = n;
    string ans, ans2, ans3;
    while (i + 1 < j) {
      if (i + 1 == j - 1)
        ans += s[++i];
      else if (s[i + 1] == s[j - 1]) {
        ans += s[++i];
        j--;
      } else
        break;
    }
    if (i + 1 == j) {
      cout << s << "\n";
      continue;
    }
    for (int i = 0; i < ans.size(); i++) {
      ans2 += ans[i];
      ans3 += ans[i];
    }
    int l = i + 1, r = j - 1;
    prefix[0] = 0;
    prefix[1] = s[0];
    for (int i = 2; i <= n; i++) {
      prefix[i] = (prefix[i - 1] + (s[i - 1] * power[i - 1]) % MOD) % MOD;
    }
    suffix[0] = 0;
    suffix[1] = s[n - 1];
    for (int i = n - 2, j = 2; i >= 0 and j <= n; i--, j++) {
      suffix[j] = (suffix[j - 1] + (s[i] * power[j - 1]) % MOD) % MOD;
    }
    int id1 = l;
    for (int i = l; i <= r; i++) {
      long long hash1 =
          ((prefix[i + 1] - prefix[l] + MOD) % MOD * inverse(power[l])) % MOD;
      long long hash2 = ((suffix[n - l] - suffix[n - i - 1] + MOD) % MOD *
                         inverse(power[n - i - 1])) %
                        MOD;
      if (hash1 == hash2) {
        id1 = i;
      }
    }
    int id2 = r;
    for (int i = r; i >= l; i--) {
      long long hash1 =
          ((prefix[r + 1] - prefix[i] + MOD) % MOD * inverse(power[i])) % MOD;
      long long hash2 = ((suffix[n - i] - suffix[n - r - 1] + MOD) % MOD *
                         inverse(power[n - r - 1])) %
                        MOD;
      if (hash1 == hash2) {
        id2 = i;
      }
    }
    for (int i = l; i <= id1; i++) ans2 += s[i];
    for (int i = id2; i <= r; i++) ans3 += s[i];
    for (int i = (int)ans.size() - 1; i >= 0; i--) {
      ans2 += ans[i];
      ans3 += ans[i];
    }
    if ((int)ans2.size() > (int)ans3.size())
      cout << ans2 << "\n";
    else
      cout << ans3 << "\n";
  }
}
