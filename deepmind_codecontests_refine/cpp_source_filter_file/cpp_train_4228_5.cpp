#include <bits/stdc++.h>
using namespace std;
int n, a[1024], b[1024], x, c[1024], flag[1024], miss[4], len;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      c[i] = a[i];
      flag[c[i]] = 1;
    } else {
      miss[len++] = i;
    }
  }
  if (len == 1) {
    for (int i = 1; i <= n; i++)
      if (!(flag[i])) c[miss[0]] = i;
  } else {
    if (flag[a[miss[0]]] && !flag[b[miss[0]]]) {
      c[miss[0]] = b[miss[0]];
      c[miss[1]] = a[miss[1]];
    } else if (flag[b[miss[0]]] && !flag[a[miss[0]]]) {
      c[miss[0]] = a[miss[0]];
      c[miss[1]] = b[miss[1]];
    } else if (flag[a[miss[1]]] && !flag[b[miss[1]]]) {
      c[miss[0]] = b[miss[1]];
      c[miss[1]] = a[miss[0]];
    } else if (flag[b[miss[1]]] && !flag[a[miss[1]]]) {
      c[miss[0]] = a[miss[1]];
      c[miss[1]] = b[miss[0]];
    } else {
      c[miss[1]] = a[miss[1]];
      c[miss[0]] = b[miss[0]];
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", c[i]);
  printf("\n");
  return 0;
}
