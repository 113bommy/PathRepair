#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char cc = getchar();
  while (cc < '0' || cc > '9') {
    if (cc == '-') f = -1;
    cc = getchar();
  }
  while (cc >= '0' && cc <= '9') {
    x = x * 10 + cc - '0';
    cc = getchar();
  }
  return x * f;
}
int main() {
  for (int i = 21; i <= 50; i++)
    printf("%d", ((min(i, 25) + i) % (2 + i % 3)) > 0);
}
