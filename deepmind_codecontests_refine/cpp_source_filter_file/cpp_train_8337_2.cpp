#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char s[N], p[N];
int ne[N];
int main() {
  int n, k;
  scanf("%d%d%s", &n, &k, p + 1);
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && p[j + 1] != p[i]) j = ne[i];
    if (p[j + 1] == p[i]) j++;
    ne[i] = j;
  }
  for (int i = 1; i <= n; i++) printf("%c", p[i]);
  for (int i = 1; i < k; i++)
    for (int j = ne[n] + 1; j <= n; j++) printf("%c", p[j]);
  return 0;
}
