#include <bits/stdc++.h>
using namespace std;
int n, price, p[100001], a[100001], ans;
int main() {
  scanf("%d", &n);
  int price = 1001;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i], &p[i]);
    price = min(price, p[i]);
    ans += price * a[i];
  }
  printf("%d\n", ans);
  return 0;
}
