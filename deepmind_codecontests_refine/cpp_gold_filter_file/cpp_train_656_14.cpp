#include <bits/stdc++.h>
using namespace std;
int a[105];
long long ans;
int main() {
  scanf("%d", &a[0]);
  for (int i = 1; i <= a[0]; ++i) {
    scanf("%d", &a[i]);
    ans += a[i] * i;
  }
  printf("%lld", ans);
  return 0;
}
