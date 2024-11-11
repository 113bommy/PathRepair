#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int a[200010];
int main() {
  int T, i, j, k, n, m;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]), a[i] += i;
  sort(a, a + n);
  for (i = 0; i < n - 1; i++) {
    if (a[i + 1] < a[i] + 1) {
      puts(":(");
      return 0;
    }
  }
  for (i = 0; i < n; i++) printf("%d ", a[i] - i);
  puts("");
  return 0;
}
