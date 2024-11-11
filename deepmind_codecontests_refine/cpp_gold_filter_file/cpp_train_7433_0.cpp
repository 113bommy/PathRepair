#include <bits/stdc++.h>
int main() {
  char a[100001], stack[100000];
  scanf("%s", a);
  int l = strlen(a);
  int i, top = 0;
  stack[top] = a[0];
  top = top + 1;
  for (i = 1; i < l; i++) {
    if (stack[top - 1] != a[i]) {
      stack[top] = a[i];
      top = top + 1;
    } else if (stack[top - 1] == a[i]) {
      top--;
    }
  }
  if (top == 0)
    printf("yes\n");
  else
    printf("no\n");
}
