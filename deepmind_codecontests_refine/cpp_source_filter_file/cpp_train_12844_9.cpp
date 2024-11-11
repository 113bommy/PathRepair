#include <bits/stdc++.h>
using namespace std;
int n;
int ans[100010];
int main() {
  scanf("%d", &n);
  if (n % 4 == 2 || n % 4 == 2) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= n / 2; i += 2) {
    ans[i] = i + 1;
    ans[i + 1] = n - i + 1;
    ans[n - i + 1] = n - i;
    ans[n - i] = i;
  }
  if (n % 4 == 1) {
    ans[n / 2 + 1] = n / 2 + 1;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
