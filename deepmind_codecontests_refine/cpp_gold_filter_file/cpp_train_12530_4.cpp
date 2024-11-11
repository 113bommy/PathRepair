#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using std::bitset;
using namespace std;
int n = 450;
int x[550], p[550];
int main() {
  int i, j, tem;
  x[1] = 0;
  p[1] = 1000000;
  for (i = 2; i < n; i++) {
    x[i] = i * 1000;
    p[i] = n - i;
  }
  x[n] = 500000;
  p[n] = 1000000;
  printf("%d\n", n);
  for (i = 1; i <= n; i++) printf("%d %d\n", x[i], p[i]);
  return 0;
}
