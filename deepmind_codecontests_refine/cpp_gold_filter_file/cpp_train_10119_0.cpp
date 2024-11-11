#include <bits/stdc++.h>
using namespace std;
int p[9];
char s[9][9];
int main() {
  int n, k, i, h, num, Min, Max, ret = INT_MAX;
  for (i = 1; i < 9; i++) p[i] = i;
  scanf("%d %d\n", &n, &k);
  for (i = 0; i < n; i++) scanf("%s", s[i]);
  do {
    Min = INT_MAX;
    Max = INT_MIN;
    for (i = 0; i < n; i++) {
      num = 0;
      for (h = 0; h < k; h++) num = 10 * num + (s[i][p[h]] - '0');
      Min = min(Min, num);
      Max = max(Max, num);
    }
    ret = min(ret, Max - Min);
  } while (next_permutation(p, p + k));
  printf("%d", ret);
  return 0;
}
