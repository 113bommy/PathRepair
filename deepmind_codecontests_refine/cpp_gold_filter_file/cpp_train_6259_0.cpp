#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  bool ok = 1;
  for (int i = 1; i < n && ok; ++i)
    if (a[i] != a[i - 1] && 2 * a[i - 1] > a[i]) ok = 0;
  printf("%s\n", ok ? "NO" : "YES");
  return 0;
}
