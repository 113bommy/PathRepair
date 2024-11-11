#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  scanf("%d", &n);
  int mn = 1e9, ans;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    mn = min(mn, a);
  }
  if (mn == 1)
    ans = -1;
  else
    ans = 1;
  printf("%d\n", ans);
}
