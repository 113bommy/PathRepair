#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int s;
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k);
    if (k == 1)
      s++;
    else
      ans += s;
  }
  printf("%d\n", ans);
  return 0;
}
