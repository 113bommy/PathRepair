#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000009;
int main() {
  int n;
  char a[110];
  while (scanf("%s", &a) != EOF) {
    n = strlen(a);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = (ans * 2 + a[i] - '0') % MOD;
    }
    for (int i = 0; i < n - 1; i++) {
      ans = (ans << 1) % MOD;
    }
    printf("%d\n", ans);
  }
  return 0;
}
