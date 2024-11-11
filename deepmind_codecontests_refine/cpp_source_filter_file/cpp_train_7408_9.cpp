#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    long long ans = 1;
    for (int i = 1; i <= n; ++i) ans *= 2LL;
    if (n % 2 == 0)
      cout << ans << endl;
    else
      printf("0\n");
  }
  return 0;
}
