#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int a[M];
int main() {
  int n, i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  int ans = 10000000;
  for (i = n / 2 + 1; i <= n; i++) {
    ans = min(ans, a[i] - a[i - n / 2]);
  }
  printf("%d\n", ans);
  return 0;
}
