#include <bits/stdc++.h>
using namespace std;
void FastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long modpow(long long a, long long p, long long mod) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    p /= 2;
  }
  return ret;
}
long long power(long long a, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a);
    a = (a * a);
    p /= 2;
  }
  return ret;
}
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int b = 0;
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--)
    if (s[i] == 'B') ans += (1 << i);
  cout << ans << '\n';
  return 0;
}
