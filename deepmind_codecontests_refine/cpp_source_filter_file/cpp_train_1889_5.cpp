#include <bits/stdc++.h>
using namespace std;
int n, attt, bttt;
int long long ans = 0, sum = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &attt);
    if (sum > attt / 2) {
      sum -= attt / 2;
      ans += (long long)attt / 2;
      sum += attt % 2;
    } else {
      attt = 2 * sum;
      ans += sum;
      sum = attt % 3;
      ans += (long long)attt / 3;
    }
  }
  printf("%lld\n", ans);
}
