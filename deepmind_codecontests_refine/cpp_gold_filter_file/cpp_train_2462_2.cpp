#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N], p[N], d[N];
int main(int argc, char const *argv[]) {
  int n, gain = 0;
  scanf("%d\n", &n);
  for (int i = 2; i <= n; i++) scanf("%d", p + i);
  for (int i = 1; i <= n; i++) d[i] = d[p[i]] + 1;
  for (int i = 1; i <= n; i++) a[d[i]] += 1;
  for (int i = 1; i <= n; i++) gain += (a[i] % 2);
  printf("%d\n", gain);
  return 0;
}
