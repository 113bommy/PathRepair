#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int LEN = 201010;
int main() {
  int n, tt;
  long long sum, ans;
  while (scanf("%d", &n) != EOF) {
    ans = sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tt);
      if (tt)
        sum += tt;
      else
        ans += sum;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
