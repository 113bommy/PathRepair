#include <bits/stdc++.h>
using namespace std;
const long long maxm = 2e5 + 5;
const long long mod = 1e9 + 7;
char s[maxm];
long long d[3];
long long n;
signed main() {
  cin >> n;
  scanf("%s", s + 1);
  long long p = 1;
  for (long long i = 1; i <= n; i++) {
    if (s[i] == 'a') {
      d[0] += p;
    } else if (s[i] == 'b') {
      d[1] += d[0];
    } else if (s[i] == 'c') {
      d[2] += d[1];
    } else if (s[i] == '?') {
      d[2] = d[2] * 3 + d[1];
      d[1] = d[1] * 3 + d[2];
      d[0] = d[0] * 3 + p;
      p = p * 3 % mod;
    }
    d[0] %= mod;
    d[1] %= mod;
    d[2] %= mod;
  }
  cout << d[2] << endl;
  return 0;
}
