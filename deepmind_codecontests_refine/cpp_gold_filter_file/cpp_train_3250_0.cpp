#include <bits/stdc++.h>
using namespace std;
long long string_to_number(string s) {
  long long g = 0;
  long long t = 1;
  for (int i = 0; i < s.length(); i++) {
    g += (s[s.length() - 1 - i] - '0') * t;
    t *= 10;
  }
  return g;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  string s;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i = 1; i < 10; i++) {
      s = char(i + '0');
      for (long long j = 0; j < 11; j++) {
        long long temp = string_to_number(s);
        if (temp <= n) {
          ans++;
          s += char(i + '0');
        } else
          break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
