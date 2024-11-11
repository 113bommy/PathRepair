#include <bits/stdc++.h>
using namespace std;
const int maxN = 100100;
long long s[maxN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    s[i] = s[i - 1] + x;
  }
  if (s[n] % 3) {
    puts("0");
    return 0;
  }
  long long cnt = 0;
  for (int i = 1; i <= n - 1; i++)
    if (s[i] == s[n] / 3 * 2) cnt++;
  long long ans = 0;
  for (int i = 1; i <= n - 2; i++) {
    if (s[i] == s[n] / 3 * 2) cnt--;
    if (s[i] == s[n] / 3) ans += cnt;
  }
  printf("%lld\n", ans);
  scanf("%*s");
}
