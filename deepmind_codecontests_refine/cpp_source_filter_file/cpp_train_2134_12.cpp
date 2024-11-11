#include <bits/stdc++.h>
int max, min;
void gg(int a1, int b1, int a2, int b2) {
  int z = a1 + a2;
  int m;
  if (b1 > b2)
    m = b1;
  else
    m = b2;
  max = z > m ? z : m;
  min = z < m ? z : m;
}
int main() {
  int a, b, a1, b1, a2, b2;
  scanf("%d%d%d%d%d%d", &a, &b, &a1, &b1, &a2, &b2);
  if (a < b) {
    int y = b;
    b = a;
    a = y;
  }
  int flag = 0;
  gg(a1, b1, a2, b2);
  if (max >= a && min >= b) flag = 1;
  gg(a1, b1, b2, a2);
  if (max >= a && min >= b) flag = 1;
  gg(b1, a1, a2, b2);
  if (max >= a && min >= b) flag = 1;
  gg(b1, a1, b2, a2);
  if (max >= a && min >= b) flag = 1;
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
}
