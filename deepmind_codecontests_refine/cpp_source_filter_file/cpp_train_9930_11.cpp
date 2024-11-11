#include <bits/stdc++.h>
using namespace std;
int n, m;
int in[100000 + 5];
bool doit() {
  if (scanf("%d%d", &n, &m) != 2) return false;
  for (int i = 0; i < n; ++i) in[i] = 0;
  int x, y;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    ++in[--x], ++in[--y];
  }
  sort(in, in + n);
  if (in[0] == 1 && in[n - 2] == 1 && in[n - 1] == n - 1)
    printf("star topology\n");
  else if (in[2] == 2 && in[3] == 2) {
    if (in[0] == 1 && in[1] == 1)
      printf("bus topology\n");
    else if (in[0] == 2)
      printf("ring topology\n");
    else
      printf("unknown topology\n");
  } else
    printf("unknown topology\n");
  return true;
}
int main() {
  while (1)
    if (!doit()) break;
}
