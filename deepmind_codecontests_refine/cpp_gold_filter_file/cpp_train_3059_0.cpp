#include <bits/stdc++.h>
int x;
int pow(int a, int b) {
  int ret, rem;
  if (b == 1) return a % x;
  if (b % 2)
    rem = a % x;
  else
    rem = 1;
  ret = (pow(a, b / 2) % x);
  return (((ret % x) * (ret % x)) % x * (rem % x)) % x;
}
bool isprim(int number) {
  int i, a;
  bool flag;
  flag = 1;
  for (i = 1; i <= x - 2; i++) {
    a = (pow(number, i) - 1) % x;
    if (a > 0) continue;
    if (a == 0)
      flag = 0;
    else {
      while (a < 0) a += x;
      if (a % x == 0) flag = 0;
    }
  }
  a = (pow(number, i) - 1) % x;
  while (a < 0) a += x;
  if (((a) % x) == 0 && flag) return 1;
  return 0;
}
int main() {
  int i, answer = 0;
  scanf("%d", &x);
  for (i = 1; i < x; i++)
    if (isprim(i)) answer++;
  printf("%d\n", answer);
}
