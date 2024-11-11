#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int maxn = 1000;
long long f[maxn];
int main() {
  f[0] = 1;
  for (long long i = 1; i < 1000; i++) f[i] = (f[i - 1] * 2) % MOD;
  string s;
  cin >> s;
  long long len = s.size();
  long long ans = 0, k = (len - 1) * 2;
  for (long long i = 0; i < len; i++) {
    if (s[i] == '1') ans += f[k - i] % MOD;
  }
  cout << ans << endl;
  return 0;
}
