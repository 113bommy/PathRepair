#include <bits/stdc++.h>
using namespace std;
int n, w, sum, dat[1010], pos = -1, res[1010];
int main() {
  scanf("%d%d", &n, &w);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &dat[i]);
    sum += dat[i];
    if (dat[i] == 1) pos = i;
  }
  if (w < 1 || w > sum || (n == 1 && w != sum) || (w == 1 && pos == -1)) {
    puts("No");
    return 0;
  }
  puts("Yes");
  if (n == 1) {
    for (int i = 1; i <= 2 * dat[1]; i++) puts("1");
  } else if (w == 1) {
    dat[pos]--;
    printf("%d\n", pos);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 2 * dat[i]; j++) printf("%d\n", i);
    }
    printf("%d\n", pos);
  } else {
    w = w - 2;
    dat[1]--;
    dat[2]--;
    for (int i = 1; i <= n; i++) {
      while (w && dat[i]) {
        res[i]++;
        w--;
        dat[i]++;
      }
    }
    printf("%d\n", 1);
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= 2 * dat[i]; j++) {
        printf("%d\n", i);
      }
    }
    puts("1\n2");
    for (int i = 1; i <= 2 * dat[1]; i++) puts("1");
    puts("2");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 2 * res[i]; j++) {
        printf("%d\n", i);
      }
    }
  }
  return 0;
}
