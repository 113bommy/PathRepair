#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int ans = 1;
  for (int i = 2; i <= n; ++i) {
    ans = (ans * 3) % 1000000 + 3;
  }
  printf("%d\n", ans);
  return 0;
}
