#include <bits/stdc++.h>
using namespace std;
bitset<300000001> P;
int l, r, res;
int main() {
  scanf("%d%d", &l, &r), P.set();
  for (int i = 3, j; (j = i * i) <= r; i += 2)
    if (P[i])
      for (; j <= r; j += i << 1) P[j] = false;
  for (int i = max(5, l + ((5 - l % 4) % 4)); i <= r; i += 4)
    if (P[i]) ++res;
  printf("%d\n", res + (l <= 2 && 2 <= r));
}
