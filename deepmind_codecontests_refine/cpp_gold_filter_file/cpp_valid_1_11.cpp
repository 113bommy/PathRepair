#include <bits/stdc++.h>
using namespace std;
const int N = 6005;
long long cnt[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    cnt[2 * (x / 2 % 2) + y / 2 % 2]++;
  }
  long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      for (int k = j + 1; k < 4; k++) {
        ans -= 1ll * cnt[i] * cnt[j] * cnt[k];
      }
    }
  }
  printf("%lld", ans);
  return 0;
}
