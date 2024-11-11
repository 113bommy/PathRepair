#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long mod(long long x) { return ((x % M + M) % M); }
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
bool isposs(int x, int y, int n, int m) {
  if (x < 0 || y < 0 || x >= n || y >= m) return 0;
  return 1;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans;
  for (int i = 0; i < (int)(n); ++i) {
    if (s[i] == '0' || s[i] == '1') continue;
    if (s[i] == '2') ans += "2";
    if (s[i] == '3') ans += "3";
    if (s[i] == '4') ans += "322";
    if (s[i] == '5') ans += "5";
    if (s[i] == '6') ans += "53";
    if (s[i] == '7') ans += "7";
    if (s[i] == '8') ans += "7222";
    if (s[i] == '9') ans += "7233";
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
