#include <bits/stdc++.h>
typedef struct node {
  int num[11];
  int bit;
} node;
node a, b, c;
node base_3(int cur) {
  node tmp;
  memset(tmp.num, 0, sizeof(tmp.num));
  tmp.bit = 0;
  while (cur) {
    tmp.num[tmp.bit] = cur % 3;
    cur /= 3;
    tmp.bit++;
  }
  return tmp;
}
int main() {
  long A, B, ans;
  int i, t;
  scanf("%ld%ld", &A, &B);
  a = base_3(A);
  b = base_3(B);
  t = (a.bit) > (b.bit) ? (a.bit) : (b.bit);
  for (i = 0; i < t; i++) c.num[i] = (a.num[i] + b.num[i]) % 3;
  for (i = t - 1, ans = 0; i >= 0; i--) ans = ans * 3 + c.num[i];
  printf("%ld\n", ans);
  return 0;
}
