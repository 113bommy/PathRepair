#include <bits/stdc++.h>
using namespace std;
char str[200010];
int main() {
  int N, T;
  scanf("%d%d", &N, &T);
  for (int i = 1; i <= N; i++) scanf("\n%c", &str[i]);
  int p;
  for (int i = 1; i <= N; i++)
    if (str[i] == '.') p = i;
  int L = N - p + 1;
  int last = N + 1;
  int tot = 1;
  for (int i = p; i <= N; i++) {
    if (str[i] >= '5' && str[i] <= '9') {
      last = i;
      break;
    }
  }
  if (last != N + 1) {
    L = N - last;
    str[last - 1]++;
    last--;
    while (tot < T && last > p && str[last] >= '5' && str[last] <= ('9' + 1)) {
      last--;
      tot++;
      str[last]++;
    }
    if (last == p) {
      str[last] = '.';
      str[p - 1]++;
      last = p - 1;
      while (str[last] >= '9') {
        str[last] = '0';
        str[last - 1]++;
        last--;
      }
    }
  } else
    last = N;
  if (str[0] == 1) printf("1");
  for (int i = 1; i < p; i++)
    if (str[i] >= ('9' + 1))
      printf("0");
    else
      printf("%c", str[i]);
  if (last > p) {
    printf(".");
    for (int i = p + 1; i <= last; i++)
      if (str[i] >= ('9' + 1))
        printf("0");
      else
        printf("%c", str[i]);
  }
  return 0;
}
