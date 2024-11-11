#include <bits/stdc++.h>
using namespace std;
int a[111111], b[111111], ans[111111];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    ans[a[i]] = b[i];
  }
  for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
  return 0;
}
