#include <bits/stdc++.h>
int n, p;
char s[1001];
int ar[1001];
int rec(int x) {
  if (x < 0) return 0;
  for (int j = ar[x] + 1; j <= p; j++) {
    if (x == 1 && j != ar[x - 1]) {
      ar[x] = j;
      return 1;
    } else if (x > 1 && j != ar[x - 1] && j != ar[x - 2]) {
      ar[x] = j;
      return 1;
    } else if (x == 0) {
      ar[x] = j;
      return 1;
    }
  }
  if (rec(x - 1) == 1) {
    for (int j = 1; j <= p; j++) {
      if (x == 1 && j != ar[x - 1]) {
        ar[x] = j;
        return 1;
      } else if (x > 1 && j != ar[x - 1] && j != ar[x - 2]) {
        ar[x] = j;
        return 1;
      } else if (x == 0) {
        ar[x] = j;
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  scanf("%d %d", &n, &p);
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    ar[i] = s[i] - 'a' + 1;
  }
  if (rec(n - 1) == 1) {
    for (int i = 0; i < n; i++) {
      printf("%c", ar[i] + 'a' - 1);
    }
  } else
    printf("NO");
}
