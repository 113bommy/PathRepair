#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int N = 2e5 + 1;
long long int mod_mul(long long int x, long long int y) {
  return ((x % MOD) * (y % MOD)) % MOD;
}
long long int mod_add(long long int x, long long int y) {
  return ((x % MOD) + (y % MOD)) % MOD;
}
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int sz = s.size();
  long long int req_sz = (sz + n - 1) / n;
  if (req_sz * n > sz) {
    for (int i = 0; i < req_sz; i++) {
      cout << 1;
      for (int j = 0; j < n - 1; j++) cout << 0;
    }
  } else {
    long long int i = sz - 1;
    while (s[i] - '0' == 9) {
      s[i] = '0';
      i--;
    }
    if (i < 0) {
      sz++;
      req_sz = (sz + n - 1) / n;
      for (int i = 0; i < req_sz; i++) {
        cout << 1;
        for (int j = 0; j < n - 1; j++) cout << 0;
      }
    } else {
      s[i] = s[i] + 1;
      long long int idx = -1;
      for (int j = n; j <= i; j++) {
        if (s[j] != s[j - n]) {
          idx = j;
          break;
        }
      }
      int f = 0;
      while (idx >= 0) {
        if (idx >= n && s[idx] - '0' > s[idx - n] - '0') {
          s[idx] = '0';
          f = 1;
          idx--;
        } else if (s[idx] == '9') {
          s[idx] = '0';
          f = 1;
          idx--;
        } else {
          break;
        }
      }
      if (idx == -1 && f) {
        sz++;
        req_sz = (sz + n - 1) / n;
        for (int i = 0; i < req_sz; i++) {
          cout << 1;
          for (int j = 0; j < n - 1; j++) cout << 0;
        }
      } else {
        if (idx < n && idx >= 0) {
          s[idx]++;
        }
        for (int j = max(n, idx); j < sz; j++) {
          s[j] = s[j - n];
        }
        cout << s << "\n";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  t = 1;
  while (t--) solve();
  return 0;
}
