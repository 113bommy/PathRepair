#include <bits/stdc++.h>
int like[5005];
int main() {
  int i, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &like[i]);
  bool right = 0;
  for (i = 0; i < n; i++) {
    if (like[like[like[i]]] == i) {
      right = 1;
      break;
    }
  }
  if (right)
    puts("YES");
  else
    puts("NO");
}
