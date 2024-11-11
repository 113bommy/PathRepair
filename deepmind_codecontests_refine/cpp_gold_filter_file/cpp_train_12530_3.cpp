#include <bits/stdc++.h>
using namespace std;
int n;
int p[500], x[500];
int main() {
  int n = 302;
  p[0] = 1000000;
  x[0] = 0;
  for (int i = 1; i <= 300; i++) {
    p[i] = 300 - i + 1;
    x[i] = x[i - 1] + (int)ceil(sqrt(4.0 * p[i - 1] * p[i])) + 1;
  }
  p[301] = 1000000;
  x[301] = 0;
  for (int i = 1; i <= 300; i++)
    x[301] = max(x[301], x[i] + (int)ceil(sqrt(4.0 * p[i] * p[301])) + 1);
  printf("%d\n", n);
  for (int i = 0; i < 302; i++) printf("%d %d\n", x[i], p[i]);
  return 0;
}
