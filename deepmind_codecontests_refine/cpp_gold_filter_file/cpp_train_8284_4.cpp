#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  long long int ans = 0;
  string s;
  cin >> s;
  long long int current = 0;
  for (int i = s.length() - 1; i >= 0; --i) {
    if (s[i] == 'b')
      ++current;
    else {
      ans += current;
      current <<= 1LL;
      current %= MOD;
      ans %= MOD;
    }
  }
  cout << ans << '\n';
  return 0;
}
