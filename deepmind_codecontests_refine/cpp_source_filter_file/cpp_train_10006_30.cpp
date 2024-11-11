#include <bits/stdc++.h>
using namespace std;
int rd() {
  char c = getchar();
  int t = 0, f = 1;
  while (!isdigit(c)) f = (c == '-') ? -1 : 1, c = getchar();
  while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
  return t * f;
}
void wt(int x) {
  if (x < 0)
    putchar('-'), wt(-x);
  else {
    if (x > 9) wt(x / 10);
    putchar(x % 10 + 48);
  }
}
int main() {
  int n = rd();
  for (int i = ((int)1); i <= ((int)n / 3 * 2); i++) printf("0 %d\n", i);
  for (int i = ((int)1); i <= ((int)n - n / 3 * 2); i++)
    printf("3 %d\n", i * 2);
  return 0;
}
