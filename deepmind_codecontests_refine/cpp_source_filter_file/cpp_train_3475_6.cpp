#include <bits/stdc++.h>
using namespace std;
int p[1000007];
int n, t;
int stk[1000007];
int main() {
  int top = 0, i, j, q;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &p[i]);
  scanf("%d", &t);
  for (j = 0; j < t; j++) {
    scanf("%d", &q);
    p[q] = -p[q];
  }
  if (n % 2 != 0)
    printf("NO\n");
  else {
    for (i = n - 1; i >= 0; i--) {
      if (p[i] < 0)
        stk[++top] = p[i];
      else {
        if (top == 0) {
          p[i] = -p[i];
          stk[++top] = p[i];
        } else {
          if (p[i] + stk[top] == 0)
            top--;
          else {
            p[i] = -p[i];
            stk[++top] = p[i];
          }
        }
      }
    }
    if (top)
      printf("NO\n");
    else {
      printf("YES\n");
      for (i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", p[i]);
      }
    }
  }
  return 0;
}
