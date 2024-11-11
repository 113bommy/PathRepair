#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long c = gcd(a, b);
  return ((a / c) * (b / c) * c);
}
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, ans;
  long long n, minl, maxl, h = 0, snow = 0, l;
  cin >> s >> n;
  l = s.size();
  for (auto x : s) {
    if (x == '?') h++;
    if (x == '*') snow++;
  }
  minl = l - h * 2 - snow * 2;
  if (snow != 0) {
    maxl = INF;
  } else {
    maxl = l - h;
  }
  if (n < minl || n > maxl) {
    cout << "Impossible" << endl;
    return 0;
  }
  long long k = n - minl;
  if (snow == 0) {
    for (int i = int(0); i < int(l - 1); ++i) {
      if (s[i] == '*' || s[i] == '?') continue;
      if (s[i + 1] != '?') {
        ans += s[i];
      } else if (k != 0) {
        ans += s[i];
        k--;
      }
    }
    if (s[l - 1] != '?') ans += s[l - 1];
  } else {
    for (int i = int(0); i < int(l - 1); ++i) {
      if (s[i] == '*' || s[i] == '?') continue;
      if (s[i + 1] != '?' && s[i + 1] != '*') {
        ans += s[i];
      } else if (s[i + 1] == '*' && k != 0) {
        for (int j = int(0); j < int(k); ++j) ans += s[i];
        k = 0;
      }
    }
    if (s[l - 1] != '?' && s[l - 1] != '*') ans += s[l - 1];
  }
  cout << ans << endl;
}
