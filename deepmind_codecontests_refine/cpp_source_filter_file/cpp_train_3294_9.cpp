#include <bits/stdc++.h>
int hold, a[111111];
using namespace std;
int main() {
  int num, x, y;
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    scanf("%d %d", &x, &y);
    for (int j = 0; j < y; j++) a[j] = 0;
    for (int j = 0; j < y; j++) scanf("%d", &a[j]);
    sort(a, a + y);
    int longest = 0;
    longest = max(a[0], x - a[y - 1] + 1);
    for (int j = 1; j < y - 1; j++)
      if ((a[j + 1] - a[j]) / 2 + 1 > longest)
        longest = (a[j + 1] - a[j]) / 2 + 1;
    printf("%d\n", longest);
  }
  return 0;
}
