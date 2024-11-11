#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, l, ans, temp;
char c;
int pos[2000000], st[2000000];
char expr[2000000];
int gettype(int p, int q) {
  int x, left, right;
  if (p == q) {
    if (expr[p] == '0') return 0;
    if (expr[p] == '1') return 1;
    if (expr[p] == '?') return 4;
  }
  x = pos[p];
  left = gettype(p + 1, x - 1);
  right = gettype(x + 1, q - 1);
  if (left > right) {
    temp = left;
    left = right;
    right = temp;
  }
  if (expr[x] == '|') {
    if (left == 0) return right;
    if (left == 1) return 1;
    if (left == 2 && right == 2) return 2;
    return 3;
  }
  if (expr[x] == '&') {
    if (left == 0) return 0;
    if (left == 1) return right;
    if (left == 2 && right == 2) return 2;
    return 3;
  }
  if (expr[x] == '^') {
    if (left == 0 || left == 2) return right;
    if (left == 1)
      if (right == 1)
        return 0;
      else
        return right;
    if (left == 3) return 3;
    if (left == 4) return 2;
  }
}
int main() {
  scanf("%d", &n);
  l = 0;
  scanf("%c", &c);
  while (c == '\n') scanf("%c", &c);
  while (c != '\n') {
    l++;
    expr[l] = c;
    scanf("%c", &c);
  }
  k = 0;
  for (i = 1; i <= l; i++) {
    if (expr[i] == '(') {
      k++;
      st[k] = i;
    }
    if (expr[i] == ')') {
      st[k] = 0;
      k--;
    }
    if (expr[i] == '|' || expr[i] == '&' || expr[i] == '^') pos[st[k]] = i;
  }
  ans = gettype(1, l);
  if (ans >= 3)
    printf("yes\n");
  else
    printf("no\n");
  return 0;
}
