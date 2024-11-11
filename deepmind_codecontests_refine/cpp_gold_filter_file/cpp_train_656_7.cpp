#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < (n); i++) {
    int a;
    scanf("%d", &a);
    ans += a * (i + 1);
  }
  printf("%d\n", ans);
  return 0;
}
