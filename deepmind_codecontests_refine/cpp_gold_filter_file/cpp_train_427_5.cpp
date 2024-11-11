#include <bits/stdc++.h>
const int N = 1e5 + 5;
int n;
int a[N], b[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = n; i >= 1; i--) {
    a[i] = a[i] - a[i - 1];
    b[i] = b[i] - b[i - 1];
  }
  std::sort(a + 2, a + n + 1);
  std::sort(b + 2, b + n + 1);
  bool jud = true;
  for (int i = 1; i <= n; i++)
    if (a[i] != b[i]) {
      jud = false;
      break;
    }
  if (jud)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
