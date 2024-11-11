#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int a[5];
int pow_mod(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    ans = ans * ans % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  int n;
  string s;
  cin >> n >> s;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') ++a[0];
    if (s[i] == 'G') ++a[1];
    if (s[i] == 'C') ++a[2];
    if (s[i] == 'T') ++a[3];
  }
  sort(a, a + 4);
  int cnt = 0;
  for (int i = 0; i < 4; ++i)
    if (a[i] == a[3]) ++cnt;
  printf("%d\n", pow_mod(cnt, n));
  return 0;
}
