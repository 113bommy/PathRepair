#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
char str[N];
int l1 = 0x3f3f3f3f, r1, l2 = 0x3f3f3f3f, r2;
int main() {
  scanf("%d%s", &n, str + 1);
  for (int i = 1; i <= n; i++)
    if (str[i] == 'L') {
      l1 = min(l1, i);
      r1 = max(r1, i);
    } else if (str[i] == 'R') {
      l2 = min(l2, i);
      r2 = max(r2, i);
    }
  if (!r1)
    printf("%d %d\n", l2, r2 + 1);
  else if (!l1)
    printf("%d %d\n", r1, l1 - 1);
  else
    printf("%d %d\n", l2, r2);
  return 0;
}
