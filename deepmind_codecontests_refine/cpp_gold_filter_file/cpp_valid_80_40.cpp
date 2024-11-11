#include <bits/stdc++.h>
using namespace std;
int _read() {
  char ch = getchar();
  while (ch != '0' && ch != '1') ch = getchar();
  return ch - 48;
}
int T, n, a[20005], pd, w;
void work() {
  scanf("%d", &n);
  pd = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = _read();
    if (a[i] == 0) w = i, pd = 1;
  }
  if (pd == 0) {
    printf("%d %d %d %d\n", 1, n - 1, 2, n);
  } else {
    if (w <= n / 2)
      printf("%d %d %d %d\n", w, n, w + 1, n);
    else
      printf("%d %d %d %d\n", 1, w, 1, w - 1);
  }
}
int main() {
  scanf("%d", &T);
  while (T--) work();
  return 0;
}
