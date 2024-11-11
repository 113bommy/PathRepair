#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int i, ans;
  int num[2005];
  while (scanf("%d%d", &n, &k) != EOF) {
    ans = 0;
    for (i = 0; i < n; i++) scanf("%d", &num[i]);
    sort(num, num + n);
    for (i = 0; i < n; i = i + k) ans += (num[i] - 1) * 2;
    printf("%d\n", ans);
  }
}
