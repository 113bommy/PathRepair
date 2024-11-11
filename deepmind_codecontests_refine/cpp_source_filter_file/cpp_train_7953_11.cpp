#include <bits/stdc++.h>
using namespace std;
int a[4010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < int(n); i++) {
    a[i] = max(a[i], -a[i]);
  }
  int ans = 0;
  for (int i = 0; i < int(n); i++) {
    int x = 0, y = 0;
    for (int j = 0; j < int(i); j++) {
      if (a[j] > a[i]) x++;
    }
    for (int j = int(i + 1); j < int(n); j++) {
      if (a[j] > a[i]) y++;
    }
    ans += min(x, y);
  }
  printf("%d\n", ans);
}
