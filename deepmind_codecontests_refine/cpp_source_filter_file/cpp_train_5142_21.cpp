#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long x = 0;
  int op = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') op = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * op;
}
inline void write(long long a) {
  if (a < 0) putchar('-'), a = -a;
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
int main() {
  puts("9\?\?>>\?\?0");
  for (int i = 0; i < 9; i++) printf("%d\?\?<>%d\n", i, i + 1);
  puts("\?\?<>1");
  for (int i = 0; i < 9; i++) printf("?%d>>%d?\n", i, i);
  for (int i = 0; i < 9; i++) printf("%d>>%d?\n", i, i);
  return 0;
}
