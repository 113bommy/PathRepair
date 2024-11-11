#include <bits/stdc++.h>
using namespace std;
char str[50009];
int p[123333];
const int MOD = 1e9 + 7;
int main() {
  scanf("%s", str);
  int n = strlen(str);
  p[0] = 1;
  for (int j = 1; j <= n; j++) p[j] = (2 * p[j - 1]) % MOD;
  int level = p[0], inside = p[n - 1], a = 0, b = n - 1;
  int ans = 0;
  for (int j = 0; str[j]; j++) {
    if (str[j] == '1') {
      long long theta = inside * inside;
      theta %= MOD;
      theta *= level;
      theta %= MOD;
      ans += theta;
      ans %= MOD;
    }
    level = p[++a];
    inside = p[--b];
  }
  cout << ans << endl;
}
