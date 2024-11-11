#include <bits/stdc++.h>
using namespace std;
int N, K;
char s[111];
int a[101];
int x;
int main() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; ++i) {
    scanf(" %s", s);
    int z = 0;
    for (; s[z] != 0; ++z)
      ;
    ++a[z];
  }
  for (int i = 2; i < 101; ++i) a[i] += a[i - 1];
  scanf(" %s", s);
  for (x = 0; s[x] != 0; ++x)
    ;
  int p, q;
  p = a[x - 1] + 1 + a[x - 1] / K * 5;
  q = a[x] + (a[x] - 1) / K * 5;
  printf("%d %d\n", p, q);
  return 0;
}
