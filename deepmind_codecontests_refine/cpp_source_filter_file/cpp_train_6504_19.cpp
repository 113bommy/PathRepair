#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500;
int d[maxn], l[maxn];
int main() {
  int i, n;
  scanf("%d", &n);
  int N = 1 << n + 1;
  for (i = 2; i <= N - 1; i++) scanf("%d", &l[i]);
  for (i = (N - 1 / 2); i >= 1; i--) {
    d[i] = d[2 * i] + d[2 * i + 1] + abs(l[2 * i] - l[2 * i + 1]);
    l[i] += max(l[2 * i], l[2 * i + 1]);
  }
  printf("%d", d[1]);
  return 0;
}
