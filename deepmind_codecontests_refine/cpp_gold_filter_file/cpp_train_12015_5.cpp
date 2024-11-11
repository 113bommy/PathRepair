#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) {
    int maxx = 0, tmp;
    long long sum = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &tmp);
      maxx = max(maxx, tmp);
      sum += tmp;
    }
    int ans = sum % (n - 1) ? sum / (n - 1) + 1 : sum / (n - 1);
    ans = max(ans, maxx);
    printf("%d\n", ans);
  }
  return 0;
}
