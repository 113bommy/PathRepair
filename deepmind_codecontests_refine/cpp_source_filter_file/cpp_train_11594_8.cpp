#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000;
int fs[MAX_N], as[MAX_N];
int main() {
  int s, k;
  scanf("%d%d", &s, &k);
  int n = 2;
  fs[0] = 0, fs[1] = 1;
  while (n < MAX_N) {
    fs[n] = 0;
    for (int i = max(0, n - k); i < n; i++) fs[n] += fs[i];
    if (fs[n] >= s) break;
    n++;
  }
  int m = 0;
  while (s > 0) {
    while (n > 0 && s < fs[n - 1]) n--;
    s -= fs[--n];
    as[m++] = fs[n];
  }
  if (m == 1) as[m++] = 0;
  printf("%d\n", m);
  for (int i = m - 1; i >= 0; i--) {
    printf("%d", as[i]);
    putchar(i ? ' ' : '\n');
  }
  return 0;
}
