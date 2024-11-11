#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
char str[101];
long long p[101];
void init() {
  p[0] = 1;
  for (int i = 1; i < 101; i++) p[i] = p[i - 1] * 2 % MOD;
}
long long solve() {
  int n = strlen(str);
  long long ans = 0;
  if (str[0] == '1') ans = p[n - 1] * p[n - 1] % MOD;
  for (int i = 1; i < n; i++) {
    if (str[i] == '1') {
      ans = (ans + p[n - i - 1] * p[n - i - 1] % MOD * p[i] % MOD) % MOD;
    }
  }
  return ans;
}
int main() {
  init();
  while (~scanf("%s", str)) {
    printf("%d\n", (int)solve());
  }
  return 0;
}
