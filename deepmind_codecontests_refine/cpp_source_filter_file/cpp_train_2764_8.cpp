#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  int roz = n * 5;
  long long tab[roz + 1];
  for (int i = 0; i < roz; i++) tab[i] = LLONG_MAX;
  tab[1] = x;
  for (int z = 0; z < 3; z++) {
    for (int i = 1; i < roz; i++) {
      tab[i + 1] = min(tab[i + 1], tab[i] + x);
      if (i * 2 <= roz)
        tab[i * 2] = min(tab[i * 2], tab[i] + y);
      else
        tab[roz] = min(tab[roz], tab[i] + y + (i * 2 - roz) * x);
    }
    for (int i = roz; i > 0; i--) tab[i - 1] = min(tab[i - 1], tab[i] + x);
  }
  printf("%lld\n", tab[n]);
}
