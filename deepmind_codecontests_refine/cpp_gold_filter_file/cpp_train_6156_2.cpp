#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0, f = 0, l = 0;
  while (s[f] == s[0]) f++;
  while (s[n - 1 - l] == s[n - 1]) l++;
  if (s[0] != s[n - 1])
    ans = f + l + 1;
  else
    ans = (f + 1) * (l + 1);
  std::cout << ans % MOD << '\n';
  return 0;
}
