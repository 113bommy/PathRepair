#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6;
string s;
long long pp[N];
int pref[N];
const int mod = 1e9 + 7;
long long int fpower(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
int main() {
  pp[0] = 1;
  for (int i = 1; i < N; i++) {
    pp[i] = (pp[i - 1] + pp[i - 1]) % mod;
  }
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + (s[i] == '1');
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int ones = pref[r] - pref[l - 1];
    long long int ans = (pp[ones] - 1 + mod) % mod;
    long long int zer = r - l + 1 - ones;
    if (zer > 0) ans = (ans + (ans * (pp[zer - 1])) % mod) % mod;
    printf("%lld\n", ans);
  }
}
