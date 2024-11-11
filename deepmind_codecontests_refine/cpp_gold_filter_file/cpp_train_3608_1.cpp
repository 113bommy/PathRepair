#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a(200000);
  int ans, s1 = 0, s2 = 0, n, i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s1 += a[i];
  }
  for (int i = 1; i <= n; i++) {
    s2 += a[i];
    if (s2 >= (s1 + 1) / 2) {
      printf("%d", i);
      break;
    }
  }
  return 0;
}
