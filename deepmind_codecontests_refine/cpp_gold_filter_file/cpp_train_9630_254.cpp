#include <bits/stdc++.h>
using namespace std;
int n;
long long ans[60005];
int main() {
  ans[3] = 1;
  int x = 3;
  for (int i = 4; i <= 60000; i++) {
    ans[i] = ans[i - 1] + x;
    x += 2;
  }
  scanf("%d", &n);
  printf("%I64d\n", ans[n]);
  return 0;
}
