#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
long long quick_pow(long long a, int n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a;
    n /= 2;
    a = a * a % mod;
  }
  return ans;
}
int main() {
  char s[55], ans[55] = {0};
  int n;
  scanf("%d%s", &n, s);
  for (int i = 0, j = 0; j < n; i++) ans[i] = s[j], j += i + 1;
  printf("%s\n", ans);
  return 0;
}
