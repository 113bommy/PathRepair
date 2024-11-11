#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
int main() {
  int T, n, m;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    if (n == 1) {
      printf("0\n");
      continue;
    } else if (n == 2) {
      printf("%d\n", m);
    } else
      printf("%d\n", m * 2);
  }
  return 0;
}
