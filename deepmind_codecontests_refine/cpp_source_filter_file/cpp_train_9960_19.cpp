#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn = 1e5 + 10;
int ans[50] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
int main() {
  long long n;
  scanf("%lld", &n);
  if (n <= 10)
    printf("%d\n", ans[n]);
  else {
    printf("%lld\n", 244 + (n - 10) * 49);
  }
  return 0;
}
