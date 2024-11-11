#include <bits/stdc++.h>
using namespace std;
int n, x;
long long ans;
int cnt[16] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};
int main() {
  scanf("%d", &n);
  if (!n) {
    puts("1");
    return 0;
  }
  while (n) {
    x = n % 16;
    ans += (long long)cnt[x];
    n /= 16;
  }
  printf("%I64d\n", ans);
}
