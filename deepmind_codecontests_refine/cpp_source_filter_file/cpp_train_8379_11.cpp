#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
#pragma comment(linker, "/STACK:268435456")
#pragma warning(disable : 4996)
  int i, j, l, n, t;
  long long ans = 1, h = 1;
  scanf("%d", &n);
  for (i = 0; i < 3 * n; i++) {
    ans = (ans * 3) % mod;
  }
  for (i = 0; i < n; i++) {
    h = (h * 7) % mod;
  }
  printf("%I64d", (ans - h) % mod);
  return 0;
}
