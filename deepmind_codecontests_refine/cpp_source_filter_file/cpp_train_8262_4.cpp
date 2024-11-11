#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int n, res;
int tab[MAXN + 3];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &tab[i]);
  sort(tab + 1, tab + n + 1);
  for (int i = 2; i <= n; i++) {
    if (tab[i] == 0) continue;
    if (tab[i] == tab[i - 1] && tab[i] == tab[i - 2]) {
      puts("-1");
      return 0;
    }
    if (tab[i] == tab[i - 1]) res++;
  }
  printf("%d\n", res);
  return 0;
}
