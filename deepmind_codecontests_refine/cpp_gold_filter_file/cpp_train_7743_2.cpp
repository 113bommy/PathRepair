#include <bits/stdc++.h>
using namespace std;
int last, n, k;
char c[2000000];
int main() {
  scanf("%d %d\n", &n, &k);
  last = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%c", &c[i]);
    if (i == 1 && c[i] == '#') {
      printf("NO");
      return 0;
    }
    if (i - last <= k && c[i] == '.') last = i;
  }
  if (last == n) {
    puts("YES");
  } else
    puts("NO");
  return 0;
}
