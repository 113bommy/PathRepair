#include <bits/stdc++.h>
using namespace std;
int N, M, l[1010], c[1010], ret = 0, x, y;
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; ++i) {
    scanf("%d%d", &x, &y);
    l[x] = 1;
    c[y] = 1;
  }
  for (int i = 2; i <= (N - 1) / 2; ++i) {
    x = l[i] + c[i] + l[N + 1 - i] + c[N + 1 - i];
    ret = ret + 4 - x;
  }
  if (N % 2 == 1) {
    x = l[N / 2 + 1] + c[N / 2 + 1];
    ret = ret + min(1, 2 - x);
  } else if (N >= 4) {
    x = l[N / 2] + c[N / 2] + l[N / 2 + 1] + l[N / 2 + 1];
    ret = ret + 4 - x;
  }
  printf("%d", ret);
  return 0;
}
