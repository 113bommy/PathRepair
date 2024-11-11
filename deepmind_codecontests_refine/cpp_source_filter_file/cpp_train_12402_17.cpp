#include <bits/stdc++.h>
using namespace std;
long long p[40], ans;
bool insert(long long val) {
  for (int i = 40; i >= 0; i--) {
    if ((val >> i) & 1) {
      if (!p[i]) {
        p[i] = val;
        ans++;
        break;
      }
      val ^= p[i];
    }
  }
  return val > 0;
}
int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0, x;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    sum ^= x;
    insert(sum);
  }
  if (sum == 0)
    printf("-1\n");
  else {
    printf("%lld\n", ans);
  }
}
