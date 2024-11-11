#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007LL;
const int N = 222;
char buf[N];
long long d[N];
int main() {
  d[0] = 1;
  for (int i = 1; i < N; ++i) d[i] = (2 * d[i - 1]) % Mod;
  scanf("%s", buf);
  int len = strlen(buf);
  long long ans = 0;
  for (int i = 0; i < len; ++i) {
    if (buf[i] == '0') continue;
    ans += d[i] * d[2 * (len - i - 1)];
    ans %= Mod;
  }
  cout << ans << endl;
  return 0;
}
