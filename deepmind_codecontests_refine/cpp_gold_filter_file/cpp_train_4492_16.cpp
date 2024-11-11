#include <bits/stdc++.h>
using namespace std;
long long n, x, y;
int main() {
  cin >> n;
  cin >> x;
  cin >> y;
  if (n > y) {
    printf("-1");
    return 0;
  }
  if ((y - (n - 1)) * (y - (n - 1)) + (n - 1) >= x) {
    printf("%lld ", y - (n - 1));
    for (int i = 1; i < n; i++) printf("1 ");
  } else
    printf("-1");
  return 0;
}
