#include <bits/stdc++.h>
using namespace std;
int ar[1000006], stk[1000006], t;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &ar[i]);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    ar[x] *= -1;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (ar[i] > 0) {
      if (t == 0 || abs(ar[stk[t - 1]]) != abs(ar[i]))
        stk[t++] = i, ar[i] *= -1;
      else
        t--;
    } else
      stk[t++] = i;
  }
  if (t) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < n; i++) printf("%d%c", ar[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
