#include <bits/stdc++.h>
using namespace std;
int main() {
  int f[100] = {1, 1}, k, n;
  for (int i = 2; i <= 50; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  while (~scanf("%lld%lld", &n, &k)) {
    int pos = 0, tem = n;
    while (pos < n) {
      pos++;
      if (k <= f[tem - 1]) {
        printf("%d ", pos);
        tem--;
      } else {
        printf("%d %d ", pos + 1, pos);
        k -= f[tem - 1];
        pos++;
        tem -= 2;
      }
    }
    puts("");
  }
}
