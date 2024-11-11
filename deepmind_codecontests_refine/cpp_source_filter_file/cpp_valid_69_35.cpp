#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long fn(string a, string b) {
  long long n = a.size(), m = b.size(), j = 0;
  for (long long i = 0; i < m; i++) {
    if (b[i] == a[j]) {
      j++;
      if (j >= n) {
        return m - n;
      }
    }
  }
  if (j >= n) {
    return m - n;
  }
  return m - j + n - j;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long ttt;
  cin >> ttt;
  vector<string> v;
  long long x = 1;
  while (x <= 1e9) {
    string s = "";
    long long z = x;
    while (z) {
      s += (char)('0' + z % 10);
      z /= 10;
    }
    reverse(s.begin(), s.end());
    v.push_back(s);
    x *= 2;
  }
  while (ttt--) {
    string s;
    cin >> s;
    long long n = s.size();
    long long ans = inf;
    for (auto x : v) {
      ans = min(ans, fn(x, s));
    }
    cout << ans << endl;
  }
}
