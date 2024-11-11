#include <bits/stdc++.h>
using namespace std;
const int ans[12] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
int main() {
  int n;
  scanf("%d", &n);
  if (n <= 11)
    printf("%d", ans[n]);
  else
    printf("%lld ", 292ll + (n - 11) * 49ll);
  return 0;
}
