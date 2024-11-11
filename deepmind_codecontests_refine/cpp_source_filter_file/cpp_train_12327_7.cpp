#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3010;
int n, p[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  int inv = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      if (p[j] > p[i]) ++inv;
  if (!inv) return puts("0"), 0;
  if (inv & 1)
    printf("%d\n", 1 + (inv - 1) * 2);
  else
    printf("%d\n", 3 + (inv - 2) * 2);
}
