#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
void dbg(const char* fmt, ...) {}
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) {
    for (int j = 1; j < n; ++j) {
      if ((n - j - 1) & (1 << i))
        printf("%d ", n - i - 1);
      else
        printf("%d ", n);
    }
    printf("%d\n", n);
  }
  return 0;
}
