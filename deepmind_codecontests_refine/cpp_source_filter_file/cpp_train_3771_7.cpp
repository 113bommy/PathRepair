#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return (!b) ? a : gcd(b, a % b);
}
int t = 1;
int ti;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  char la1 = 'a', la2 = 'a';
  string ans = "";
  for (int i = 1; i <= (int)s.size() - 1; i++) {
    if (s[i] >= la1) {
      ans += '0';
      la1 = s[i];
    } else if (s[i] >= la2) {
      ans += '1';
      la2 = s[i];
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
