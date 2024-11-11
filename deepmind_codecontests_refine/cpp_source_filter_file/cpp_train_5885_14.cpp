#include <bits/stdc++.h>
using namespace std;
inline void read(int &n) {
  int f = 1;
  n = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) n = n * 10 + ch - '0';
  n *= f;
}
inline void write(int n, char ch = '\n') {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  int st[30];
  int top = 0;
  do {
    st[++top] = n % 10;
    n /= 10;
  } while (n);
  while (top) putchar(st[top--] + '0');
  putchar(ch);
}
const double PI = 3.1415926;
double f(double l, double n) {
  return l * l * l * n / (12 * tan(PI / n)) *
         sqrt(1 - 1 / (4 * sin(PI / n) * sin(PI / n)));
}
int main() {
  int l3, l4, l5;
  read(l3), read(l4), read(l5);
  printf("%.9f\n", f(l3, 3) + f(l4, 4) + f(l5, 5));
  return 0;
}
