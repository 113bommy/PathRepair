#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const double PI = acos(-1);
const double ERR = 1e-10;
int s[maxn];
int cnt[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j * j <= s[i]; j++) {
      if (s[i] % j == 0) {
        cnt[j]++;
        while (s[i] % j == 0) s[i] /= j;
      }
    }
    if (s[i] > 1) cnt[s[i]]++;
  }
  int ans = 1;
  for (int i = 2; i <= 100000; i++) ans = max(ans, cnt[i]);
  printf("%d\n", ans);
  return 0;
}
