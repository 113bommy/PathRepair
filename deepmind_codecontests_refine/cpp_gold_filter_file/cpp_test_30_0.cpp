#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  map<char, long long> mp;
  for (char c : s) {
    mp[c]++;
  }
  long long ans = 0;
  long long minn = INT_MAX;
  for (auto it : mp) {
    char c = it.first;
    long long l = 0, r = n - 1;
    long long cnt = 0;
    while (l < r && s[l] == s[r]) {
      l++;
      r--;
    }
    while (l < r && s[l] == c) {
      l++;
      cnt++;
    };
    while (r > l && s[r] == c) {
      cnt++;
      r--;
    }
    while (l < r && s[l] == s[r]) {
      while (l < r && s[l] == s[r]) {
        l++;
        r--;
      }
      while (l < r && s[l] == c) {
        l++;
        cnt++;
      };
      while (r > l && s[r] == c) {
        cnt++;
        r--;
      }
    }
    if (l >= r) {
      ans++;
      minn = min(minn, cnt);
    }
  }
  if (ans == 0) {
    cout << -1 << "\n";
    return;
  }
  cout << minn << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
