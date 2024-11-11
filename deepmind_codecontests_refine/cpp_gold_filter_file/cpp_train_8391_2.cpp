#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
using namespace std;
int n, m;
int f[110], k[110];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &k[i], &f[i]);
  }
  if (n == 1 && m == 0) {
    printf("1\n");
    return 0;
  }
  int flag;
  int all = 0;
  int pos = 0;
  for (int i = 1; i <= 100; i++) {
    flag = 0;
    for (int j = 1; j <= m; j++) {
      int temp = k[j] / i;
      if (k[j] % i != 0) temp++;
      if (temp != f[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      all++;
      if (!pos) {
        pos = n / i;
        if (n % i != 0) pos++;
      } else {
        int woc = n / i;
        if (n % i != 0) woc++;
        if (pos == woc) all--;
      }
    }
  }
  if (all != 1)
    printf("-1\n");
  else {
    printf("%d\n", pos);
  }
  return 0;
}
