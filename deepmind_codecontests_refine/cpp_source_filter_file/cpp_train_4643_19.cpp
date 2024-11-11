#include <bits/stdc++.h>
int top = -1;
char stack[100009];
char str[100009], temp[100009];
void push(char item) {
  top++;
  stack[top] = item;
}
void pop() { top--; }
char min(char x, char y) {
  if (x < y)
    return x;
  else
    return y;
}
void func(int n) {
  int p = 0, k = 0;
  char te2[100009];
  char set;
  while (p < n || top >= 0) {
    if (top >= 0) {
      if (stack[top] <= temp[p]) {
        te2[k++] = stack[top];
        pop();
      } else {
        set = str[p];
        push(set);
        p++;
      }
    } else {
      set = str[p];
      push(set);
      p++;
    }
  }
  printf("%s", te2);
  printf("\n");
}
int main() {
  int n;
  scanf("%s", str);
  for (n = 0; str[n] != '\0'; n++)
    ;
  temp[n] = 'z';
  int l = n - 1;
  while (l >= 0) {
    temp[l] = min(str[l], temp[l + 1]);
    l--;
  }
  func(n);
}
