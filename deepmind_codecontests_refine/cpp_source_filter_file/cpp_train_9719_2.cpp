#include <bits/stdc++.h>
int s;
int s1;
int s2;
int s3;
int a, b, c;
int main() {
  scanf("%d", &s1);
  scanf("%d", &s2);
  scanf("%d", &s3);
  b = sqrt(s3 * s1 / s2);
  c = (s3 / b);
  a = (b * s2 / s3);
  s = (a + b + c) * 4;
  printf("%d", &s);
  return 0;
}
