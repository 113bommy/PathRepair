#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
inline void solve() {
  string s;
  cin >> s;
  vector<int> lps(s.length(), 0);
  int i = 1, len = 0, n = s.length();
  while (i < n) {
    if (s[i] == s[len]) {
      ++len;
      lps[i] = len;
      ++i;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        ++i;
      }
    }
  }
  if (!lps[n - 1]) {
    cout << "Just a legend";
    return;
  }
  int q = n - 1;
  unordered_map<long long int, long long int> mp;
  for (int i = 0; i < n - 1; i++) mp[lps[i]]++;
  int p = 1;
  while (1) {
    p = lps[q];
    if (!p) break;
    if (mp[p]) {
      for (int i = 0; i < p; i++) cout << s[i];
      return;
    }
    q = lps[q];
  }
  cout << "Just a legend";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
