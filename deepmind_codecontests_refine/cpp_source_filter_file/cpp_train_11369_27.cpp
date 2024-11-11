#include <bits/stdc++.h>
using namespace std;
int q[10005], n, top;
char str[10005];
int calc_next(int x) {
  int i;
  for (i = x; i < n; i++)
    if (str[i] == '>') return i;
}
void pr(int x, int y) {
  int i;
  for (i = 1; i <= q[top]; i++) printf(" ");
  for (i = x; i <= y; i++) printf("%c", str[i]);
  printf("\n");
}
int main(void) {
  scanf("%s", &str);
  n = strlen(str);
  int i, k;
  for (i = 0; i < n; i++) {
    k = calc_next(i);
    if (str[i + 1] == '/') {
      --top;
      pr(i, k);
    } else {
      pr(i, k);
      ++top;
      q[top] = q[top - 1] + k - i + 1;
    }
    i = k;
  }
  return 0;
}
